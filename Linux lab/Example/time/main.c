#include <sys/time.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

void main()
{
    char *buf = malloc(1000);

    struct timeval now_timeval;
    gettimeofday(&now_timeval, NULL);

    struct tm *now_tm = localtime(&now_timeval.tv_sec);
    printf("Calendar time (seconds since Epoch): %ld\n", (long) mktime(now_tm));

    strftime(buf, 1000, "%A %D %T", now_tm);
    printf("strftime() yields: %s\n", buf);
}


