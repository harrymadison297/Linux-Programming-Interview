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

#ifndef __FILE_IO
#define __FILE_IO

long get_filesize(FILE * fp);
int checksum_package(const uint8_t * data);
int mergeFile(FILE * dest, FILE * src);

#endif
