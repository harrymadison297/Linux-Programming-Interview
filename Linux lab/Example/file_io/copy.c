#include <sys/stat.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

void errExit(char* message)
{
    printf("[ERROR] %s\n", message);
    exit(0);
}

void main(int argc, char *argv[])
{
    /* Check arguments */
    if (3 != argc)
        errExit("Invalid argument.\nUsing 'copy old-file new-file'");

    int inputFile, outputFile, openFlags;
    mode_t filePerms;
    __ssize_t numRead;
    char buf[BUF_SIZE];

    /* Open input file for reading */
    inputFile = open(argv[1], O_RDONLY);
    if (-1 == inputFile)
        errExit("Couldn't find input file");

    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH ;
    
    /* Create or open clean output file */
    outputFile = open(argv[2], openFlags, filePerms);
    if (-1 == outputFile)
        errExit("Couldn't open/create output file");

    /* Transfer data from input to output */    
    while ((numRead = read(inputFile, buf, BUF_SIZE)) > 0)
        if (write(outputFile, buf, numRead) != numRead)
            errExit("Error in copying file");        

    if (numRead == -1)
        errExit("Couldn't read");

    if (close(inputFile) == -1)
        errExit("Couldn't close input file");            

    if (close(outputFile) == -1)
        errExit("Couldn't close output file");            
}