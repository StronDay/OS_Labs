#include "sharedMemory.h"
#include "synchron.h"

int main()
{
    int *sharedMemory = connectSharedMemory("./src/memory.c", 100);
    if (sharedMemory == NULL)
    {
        printf("ERROR: couldn't get shared memory!\n");
        return -1;
    }

    int input[2];
    int semID = createSemaphore("./src/memory.c", false);
    if (semID == -1)
    {
        printf("The semaphore was not created!\n");
        return -1;
    }

    freeSemaphore(semID);

    memcpy(&input, sharedMemory, sizeof(int) * 2);
    time_t tTime = input[0];
    
    printf("PID: %d, TIME: %s", input[1], asctime(gmtime(&tTime)));

    lcokSemaphore(semID);

    disconnectSharedMemory(sharedMemory);

    return 0;
}