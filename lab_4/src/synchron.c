#include "synchron.h"

#define ERROR_VALUE (-1)

int createSemaphore(char* fileName, bool isEXCL)
{
    key_t key = ftok(fileName, 5);

    if (key == ERROR_VALUE)
    {
        printf("The key was not initialized!\n");
        return -1;
    }

    if (isEXCL)
    {
        return semget(key, 1, 0644 | IPC_CREAT | IPC_EXCL);
    }
    
    return semget(key, 1, 0644 | IPC_CREAT);
}

int lcokSemaphore(int semID)
{
    struct sembuf semB;

    semB.sem_num = 0;
    semB.sem_op = -1;
    semB.sem_flg = IPC_NOWAIT;

    sleep(3);

    if (semop(semID, &semB, 1) == ERROR_VALUE) 
    {
        printf("semaphore lock failed\n");
        return(0);
    }

    return(1);
}

int freeSemaphore(int semID)
{
    struct sembuf semB;

    semB.sem_num = 0;
    semB.sem_op = 1;
    semB.sem_flg = IPC_NOWAIT;

    if (semop(semID, &semB, 1) == ERROR_VALUE) 
    {
        printf("semaphore lock failed\n");
        return(0);
    }

    return(1);
}