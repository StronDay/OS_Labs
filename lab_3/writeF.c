#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdbool.h>

#include "sharedMemory.h"

int* connectSharedMemory(char* fileName, unsigned int size);
bool disconnectSharedMemory(int* sharedMemory);
bool deleteSharedMemory(char* fileName);

int main()
{
    int* sharedMemory = connectSharedMemory("memory_buff.c", sizeof(int) * 2); //sizeof(int) * 2
    if (sharedMemory == NULL)
    {
        printf("ERROR: couldn't get shared memory!\n");
        return -1;
    }

    int output[2];
    output[0] = time(NULL);
    output[1] = getpid();

    if (getpid())

    while(1)
    {
        memcpy(sharedMemory, output, sizeof(int) * 2);
        output[0] = time(NULL);
    }

    disconnectSharedMemory(sharedMemory);

    return 0;
}