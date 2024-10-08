#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <errno.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <wait.h>
#include "lib/include/sock_com.h"
#include "lib/include/file_io.h"

int package_counter = 0; 
pthread_mutex_t package_counter_l; 
int clientfd;
struct start_frame file_transfer;

int main(int argc, char * argv[])
{
    int sockfd_local = sock_server_init_local("./tmp/sendfile", 100);

    /* Start file transfer */
    printf("Server is ready to revice file!\n");
    clientfd = accept(sockfd_local, NULL, NULL);
    while (1)
    {
        int start_frame_size = sizeof(struct start_frame);
        ssize_t byte_read = read(clientfd, &file_transfer, sizeof(struct start_frame));
        if (byte_read != sizeof(struct start_frame))
            errExit("Error in setup connection\n");        
        printf("Start receive file: %s in %d packet, total %ld bytes\n", file_transfer.name, file_transfer.separate_total, file_transfer.filesize);
        break;
    }

    int num_connection = file_transfer.num_connection, i = 0;
    FILE * fp_all[num_connection];
    for (i = 0; i < num_connection; i++)
    {
        char name_file[30];
        sprintf(name_file, "./tmp/%d_rev", i);
        fp_all[i] = fopen(name_file, "wb+");
    }

    while (package_counter <= file_transfer.separate_total)
    {
        FILE * rev_fp;
        struct data_frame data_rev;
        ssize_t byte_read = read(clientfd, &data_rev, sizeof(struct data_frame));
        if (byte_read != sizeof(struct data_frame))
            errExit("Error in setup connection\n");        
        int read_size = DATA_STREAM_LENGTH;
        if (DATA_STREAM_LENGTH*(data_rev.id+1) > file_transfer.filesize)
            read_size = file_transfer.filesize - DATA_STREAM_LENGTH*data_rev.id;
        
        int rev_pos = 0;
        while (file_transfer.separate_total / num_connection * (rev_pos+1) - 1 < data_rev.id)
            rev_pos++;        
        if (rev_pos >= num_connection) rev_pos -= 1;
        rev_fp = fp_all[rev_pos];
        int writed = fwrite(data_rev.data, read_size, 1, rev_fp);
        printf("%d : %d\n", data_rev.id, rev_pos);
        
        // if (writed == 0)
        // {
        //     printf("[ERROR] Checksum error in packet %d : %d - SUM: %d\n", data_rev.id, data_rev.checksum, checksum_package(data_rev.data));
        // }
        // else
        //     printf("Reveiced packet %d - SUM: %d, length: %d, writed: %d\n", data_rev.id, checksum_package(data_rev.data), read_size, writed);
        package_counter++;
    }

    int sum = 0;
    for (i = 0; i < num_connection; i++)
    {
        int fs = get_filesize(fp_all[i]);
        printf("Reviced file size: %d\n", fs);
        sum += fs;
    }
    printf("Total: %d\n", sum);

    printf("Merging!\n");
    FILE * final_fp = fopen("./tmp/rev", "wb+");
    for (i = 0; i < num_connection; i++)
    {
        char name_file[30];
        sprintf(name_file, "./tmp/%d_rev", i);
        printf("Merging file %s\n", name_file);
        mergeFile(final_fp, fp_all[i]);
        remove(name_file);
    }
    // fclose(rev_fp);
    printf("Completed! \nSaved to ./tmp/rev - Size: %d\n", (int) get_filesize(final_fp));

    return 0;
}
