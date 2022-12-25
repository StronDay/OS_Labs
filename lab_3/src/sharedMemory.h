#ifndef  SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int* connectSharedMemory(char* fileName, unsigned int size, bool isMainProcess);
bool disconnectSharedMemory(int* sharedMemory);
bool deleteSharedMemory(char* fileName);

#endif