#include "sharedMemory.h"

int main()
{
    int *sharedMemory = connectSharedMemory("./src/memory.c", sizeof(int) * 2);
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