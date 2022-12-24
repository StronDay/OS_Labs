#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <stdbool.h>
#include "sharedMemory.h"

#define ERR (-1)

int getSharedMemory(char* fileName, unsigned int size)
{
    key_t key = ftok(fileName, 0);
    if (key == -1)
    {
        printf("The key was not initialized!\n");
        return -1;
    }

    return shmget(key, size, 0644 | IPC_CREAT);
}

int* connectSharedMemory(char* fileName, unsigned int size)
{
    int sharedMemoryID = getSharedMemory(fileName, size);
    int* result;

    if (sharedMemoryID == -1)
    {
        printf("Shared memory was not initialized!\n");
        return 0;
    }

    result = shmat(sharedMemoryID, NULL, 0);
    if (result == (int*)ERR) return NULL;

    return result;
}

bool disconnectSharedMemory(int* sharedMemory)
{
    return (shmdt(sharedMemory) != -1);
}

bool deleteSharedMemory(char* fileName)
{
    int sharedMemoryID = getSharedMemory(fileName, 0);
    if (sharedMemoryID == -1) return NULL;

    return (shmctl(sharedMemoryID, IPC_RMID, NULL) != -1);
}