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
#include <math.h>
#include "lib/include/sock_com.h"
#include "lib/include/err_exit.h"
#include "lib/include/file_io.h"

#define BUF_SIZE 100
struct start_frame file_transfer;
int package_counter = 0; 
pthread_mutex_t package_counter_l; 
int client_sockfd;
int num_connection;

void * send_package_thread(void * param);

int main(int argc, char* argv[])
{
    /* Check input */
    if (argc != 5)
        errExit("Usage: ./Sender <num_connection> <receiver_ip> <receiver_port> <file_path>\n");

    /* Set input param */
    num_connection = atoi(argv[1]);
    char * receiver_ip = argv[2];
    int receiver_port = atoi(argv[3]);
    char * file_path = argv[4];
    if (num_connection < 1 || receiver_port < 1)
        errExit("Wrong parameter\n");

    /* Open file */
    FILE * file_ptr = fopen(file_path, "rb");
    if (NULL == file_ptr)
        errExit("File doesn't exist! Try again!\n");

    /* Setup client socket */
    client_sockfd = sock_client_init_local("./tmp/sendfile");

    /* The first packet to accept file transfer */
    strcpy(file_transfer.name, argv[4]);
    file_transfer.checksum = 1024;
    file_transfer.filesize = get_filesize(file_ptr);
    file_transfer.num_connection = num_connection;
    int sp = file_transfer.filesize / DATA_STREAM_LENGTH;
    file_transfer.separate_total = sp;
    ssize_t num_write = write(client_sockfd, &file_transfer, sizeof(struct start_frame));
    if (num_write != sizeof(struct start_frame))
        errExit("Error in start frame packet!\n");
    else
        printf("Start sendfile: %s - Size: %ld bytes - %d Package\n", file_transfer.name, file_transfer.filesize, file_transfer.separate_total);

    /* Start transfer */
    int i = 0;
    pthread_t thread_id[num_connection];
    for (i = 0; i < num_connection; i++)
    {
        pthread_create(&thread_id[i], NULL, &send_package_thread, NULL);
    }
    
    for (i = 0; i < num_connection; i++)
    {
        pthread_join(thread_id[i], NULL);
    }
    
    printf("Completed sendfile: %s - Size: %ld bytes\n", file_transfer.name, file_transfer.filesize);

    return 0;
}

void * send_package_thread(void * param)
{
    FILE * fp = fopen(file_transfer.name, "rb");
    struct data_frame data;
    memset(&data, 0, sizeof(struct data_frame));
    pthread_mutex_lock(&package_counter_l);
    int start_package_send = file_transfer.separate_total / num_connection * package_counter;
    package_counter += 1;
    int total_package_send = file_transfer.separate_total / num_connection * package_counter - 1;
    if (package_counter == num_connection)
        total_package_send = file_transfer.separate_total;
    pthread_mutex_unlock(&package_counter_l);
    if (start_package_send == total_package_send)
        return;

    printf("Send from %d to %d\n", start_package_send, total_package_send);

    int id_pk = start_package_send;
    while (id_pk <= total_package_send)
    {
        fseek(fp, DATA_STREAM_LENGTH*id_pk, SEEK_SET);
        int read_size = DATA_STREAM_LENGTH;
        if (DATA_STREAM_LENGTH*(id_pk+1) > file_transfer.filesize)
            read_size = file_transfer.filesize - DATA_STREAM_LENGTH*id_pk;
        int readed = (int) fread(data.data, read_size, 1, fp);
        data.checksum = checksum_package(data.data);
        data.id = id_pk;
        ssize_t num_write = write(client_sockfd, &data, sizeof(struct data_frame));
        // if (num_write != sizeof(struct data_frame))
        //     errExit("Error in send data packet\n");
        // else
        //     printf("Sended packet id: %d - SUM: %d, size: %d\n", id_pk, data.checksum, read_size);
        id_pk ++;
    }

    fclose(fp);
}