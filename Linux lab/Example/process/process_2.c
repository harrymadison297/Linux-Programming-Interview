#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Create process with PID: %d\n", getpid());
    __pid_t childPID = fork();
    if (childPID == -1)
    {
        printf("[ERROR] Couldn't folk");
        return 0;
    }
    else if (childPID == 0)
        printf("This is child process with PID: %d\n", getpid());
    else
        printf("Created child process with PID: %d\n", childPID);

    printf("END\n");
    return 0;    
}



