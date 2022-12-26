#ifndef SYNCHRON_H
#define SYNCHRON_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int createSemaphore(char* fileName, bool isEXCL);
int lcokSemaphore(int semID);
int freeSemaphore(int semID);

#endif