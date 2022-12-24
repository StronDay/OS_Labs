#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
    if (deleteSharedMemory("memory_buff.c"))
    {
        printf("Destroyed!\n");
    }
    else
    {
        printf("Not destroy!\n");
    }

    return 0;
}