#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        __pid_t childPID = fork();

        if (childPID == -1)
            return 0;
        else if (childPID == 0)
        {
            printf("Child process \n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Parent process \n");
            /* Synchorus to avoid race condition
            wait(childPID);
            */
        }
    }

    return 0;
}

