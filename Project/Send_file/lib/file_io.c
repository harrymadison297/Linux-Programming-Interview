#include "include/file_io.h"

long get_filesize(FILE * fp)
{
    fseek(fp, 0L, SEEK_END);
    long sz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    return sz;
}

int checksum_package(const uint8_t * data)
{
    int i, sum = 0;
    int count = strlen(data);
    for (i = 0; i < count; i++)
        sum += data[i];
    return sum;
}

int mergeFile(FILE * dest, FILE * src)
{
    if (dest == NULL || src == NULL) 
    { 
        puts("Could not open files"); 
        return(1); 
    } 
    fseek(src, 0L, SEEK_SET);
    char c;
    while (1)
    {
        int i = (int) fread(&c, 1, sizeof(char), src);
        if (i == 0)
            break;        
        fwrite(&c, 1, sizeof(char), dest);
    }
    return 0;    
}


