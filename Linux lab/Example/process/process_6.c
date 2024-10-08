#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_log(int b, void *arg) 
{
    printf("Exit status: %d\n", b);
    printf("Argument: %s\n", (char*) arg);
}

int main()
{
    printf("Start process\n");
    on_exit(&exit_log, "Exit message");
    return 10;
}

