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
#include "err_exit.h"
#include <inttypes.h>

#ifndef __SOCK_COM
#define __SOCK_COM

#define DATA_STREAM_LENGTH 1024

struct start_frame
{
    char name[100];
    int checksum;
    int separate_total;
    int num_connection;
    long filesize;
};

struct data_frame
{
    uint8_t data[DATA_STREAM_LENGTH];
    int id;
    int checksum;
};

int sock_server_init_local(const char * sockpath, int max_connection);
int sock_client_init_local(const char * sockpath);

#endif
