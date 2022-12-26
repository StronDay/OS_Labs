#include "sharedMemory.h"
#include "synchron.h"

int main()
{
    int* sharedMemory = connectSharedMemory("./src/memory.c", 100);
    if (sharedMemory == NULL)
    {
        printf("ERROR: couldn't get shared memory!\n");
        return -1;
    }

    int output[2];
    output[0] = time(NULL);
    output[1] = getpid();

    int semID = createSemaphore("./src/memory.c", true);
    if (semID == -1)
    {
        printf("The semaphore was not created!\n");
        return -1;
    }

    while(1)
    {
        freeSemaphore(semID);
        memcpy(sharedMemory, output, sizeof(int) * 2);
        output[0] = time(NULL);
        lcokSemaphore(semID);
        sleep(3);
        printf("PID: %d\n", getpid());
    }

    disconnectSharedMemory(sharedMemory);
    semctl(semID, IPC_RMID, 0);

    return 0;
}