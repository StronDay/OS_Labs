#ifdef  SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <stdbool.h>

int* connectSharedMemory(char* fileName, unsigned int size);
bool disconnectSharedMemory(int* sharedMemory);
bool deleteSharedMemory(char* fileName);

#endif