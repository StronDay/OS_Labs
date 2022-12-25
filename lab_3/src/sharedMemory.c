#include "sharedMemory.h"
#include <errno.h>

#define ERROR_VALUE (-1)

int getSharedMemory(char* fileName, unsigned int size, bool isMainProcess)
{
    key_t key = ftok(fileName, 0);

    if (key == ERROR_VALUE)
    {
        printf("The key was not initialized!\n");
        return -1;
    }

    if (isMainProcess)
    {
        return shmget(key, size, 0666 | IPC_CREAT | IPC_EXCL);
    }

    return shmget(key, size, 0666 | IPC_CREAT);
}

int* connectSharedMemory(char* fileName, unsigned int size,  bool isMainProcess)
{
    int sharedMemoryID = getSharedMemory(fileName, size, isMainProcess);
    int* result;

    if (sharedMemoryID == ERROR_VALUE)
    {
        if (errno == EEXIST) 
        {
            printf("There is already a program with a loop!\n");
            return 0;
        }

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
    int sharedMemoryID = getSharedMemory(fileName, 0, false);
    if (sharedMemoryID == ERROR_VALUE) return NULL;

    return (shmctl(sharedMemoryID, IPC_RMID, NULL) != ERROR_VALUE);
}