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

#ifndef __ERR_EXIT
#define __ERR_EXIT

void errExit(char * err);

#endif
