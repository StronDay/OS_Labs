#include "sharedMemory.h"

#define ERROR_VALUE (-1)

int getSharedMemory(char* fileName, unsigned int size)
{
    key_t key = ftok(fileName, 5);

    if (key == ERROR_VALUE)
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

    if (sharedMemoryID == ERROR_VALUE)
    {
        printf("Shared memory was not initialized!\n");
        return 0;
    }

    result = shmat(sharedMemoryID, NULL, 0);
    if (result == (int*)ERROR_VALUE) return NULL;

    return result;
}

bool disconnectSharedMemory(int* sharedMemory)
{
    return (shmdt(sharedMemory) != ERROR_VALUE);
}

bool deleteSharedMemory(char* fileName)
{
    int sharedMemoryID = getSharedMemory(fileName, 0);
    if (sharedMemoryID == ERROR_VALUE) return NULL;

    return (shmctl(sharedMemoryID, IPC_RMID, NULL) != ERROR_VALUE);
}