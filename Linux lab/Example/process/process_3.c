#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    FILE* fptr;
    fptr = fopen("test.txt", "r");
    char buffer[60];

    if (fptr == NULL) 
        return 0;

    __pid_t childPID = fork();
    if (childPID == -1)
        return 0;
    else if (childPID == 0)
        printf("Child get line: %s", 
            fgets(buffer, 60, fptr));
    else
    {
        wait(childPID);
        printf("Parent get line: %s\n", 
            fgets(buffer, 60, fptr));
    }

    return 0;
}

