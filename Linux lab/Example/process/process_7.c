#include <stdio.h>
#include <sys/time.h>
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

    int i;
    setbuf(stdout, NULL);

    for (i = 1; i < argc; i++)
    {
        switch (fork())
        {
            case -1:
                exit(1);
                break;
            case 0:
                printf("[%s] Child %d started, sleeping %ss\n", 
                            get_time_now(), getpid(), argv[i]);
                sleep(atoi(argv[i]));
                exit(EXIT_SUCCESS);
            default:
                break;
        }
    }
    printf("\n");
    /* Parent waits for each child to exit */
    for (;;) {                      
        child_pid = wait(NULL);
        if (child_pid == -1) 
        {
            printf("No more children - bye!\n");
            exit(EXIT_SUCCESS);
        }
        else
            printf("[%s] wait() returned child PID %ld\n",
                get_time_now(), (long) child_pid);
    }
    return 0;
}

