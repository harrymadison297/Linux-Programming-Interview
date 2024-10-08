#include <stdio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h>

char *get_time_now()
{
    char *buf = malloc(1000);
    struct timeval now_timeval;
    gettimeofday(&now_timeval, NULL);
    struct tm *now_tm = localtime(&now_timeval.tv_sec);
    mktime(now_tm);
    strftime(buf, 1000, "%A %D %T", now_tm);
    return buf;
}

int main(int argc, char* argv[])
{
    __pid_t child_pid;
    
    
    return 0;
}

