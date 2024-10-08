#include <stdio.h>
#include <stdlib.h>

/* Test malloc - limit heap size */
void main()
{
    char *test;
    int x = 0;
    while(1)
    {
        x++;
        test = (char *) malloc(sizeof(char)*10000*x);
        printf("Oke with %d - %x\n", x, test);
        if (test == 0)
            return;        
    }
}