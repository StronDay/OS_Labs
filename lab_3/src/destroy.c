#include "sharedMemory.h"

int main()
{
    if (deleteSharedMemory("./src/memory.c"))
    {
        printf("Destroyed!\n");
    }
    else
    {
        printf("Not destroy!\n");
    }

    return 0;
}