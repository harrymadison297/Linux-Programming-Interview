#include "include/err_exit.h"

void errExit(char * err)
{
    printf("[ERROR] %s\n", err);
    exit(EXIT_FAILURE);
}