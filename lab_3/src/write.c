#include "sharedMemory.h"

int main()
{
    int* sharedMemory = connectSharedMemory("./src/memory.c", 100, true);
    if (sharedMemory == NULL)
    {
        printf("ERROR: couldn't get shared memory!\n");
        return -1;
    }

    int output[2];
    output[0] = time(NULL);
    output[1] = getpid();

    while(1)
    {
        memcpy(sharedMemory, output, sizeof(int) * 2);
        output[0] = time(NULL);
    }

    disconnectSharedMemory(sharedMemory);

    return 0;
}