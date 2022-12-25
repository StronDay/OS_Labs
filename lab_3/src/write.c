#include "sharedMemory.h"

int main()
{
    int pidID = getpid();
    printf("Pid write: %d\n", pidID);

    int* sharedMemory = connectSharedMemory("./src/memory.c", sizeof(int) * 2);
    if (sharedMemory == NULL)
    {
        printf("ERROR: couldn't get shared memory!\n");
        return -1;
    }

    int output[2];
    output[0] = time(NULL);
    output[1] = pidID;

    if (getpid())

    while(1)
    {
        memcpy(sharedMemory, output, sizeof(int) * 2);
        output[0] = time(NULL);
    }

    disconnectSharedMemory(sharedMemory);

    return 0;
}