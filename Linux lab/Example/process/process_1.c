#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[], char *envp[])
{
    printf("Print env 10th: %s\n",envp[10]);

    /* Set env */
    int test = setenv("haha", "HAHA_ENV", 1);
    if (!test)
        printf("Set haha env\n");    
    else
        return;

    /* Print env */
    printf("%s\n", getenv("haha"));
    
    /* Unset env */
    test = unsetenv("haha");
    if (!test)
        printf("Set haha env\n");    
    else  
        return;
}



