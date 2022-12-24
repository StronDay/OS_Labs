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
    int *sharedMemory = connectSharedMemory("memory_buff.c", sizeof(int) * 2);
    if (sharedMemory == NULL)
    {
        printf("ERROR: couldn't get shared memory!\n");
        return -1;
    }

    int input[2];

    memcpy(&input, sharedMemory, sizeof(int) * 2);
    time_t tTime = input[0];
    
    printf("PID: %d, TIME: %s", input[1], asctime(gmtime(&tTime)));

    disconnectSharedMemory(sharedMemory);

    return 0;
}