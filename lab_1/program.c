#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sched.h>

void parentFoo(void)
{
    printf("PARENT: My suicide message!\n");
}

void childFoo(void)
{
    printf("    CHILD: My suicide message\n");
}

void signalHandlerSIGINT(int sig)
{
    printf("Caught signal num: %d; PID: %d\n", sig, getpid());
}

void signalHandlerSIGTERM(int sig, siginfo_t *info, void *ctx)
{
    printf("Caught signal num: %d; PID: %d\n", sig, info->si_pid);
    if (sig == SIGTERM) {
        exit(0);
    }
}

int main()
{
    int exCode;
    pid_t pid;

    struct sigaction termHandler;
    memset(&termHandler, 0, sizeof(termHandler));

    termHandler.sa_sigaction = signalHandlerSIGTERM;
    termHandler.sa_flags = SA_RESTART | SA_SIGINFO;
    sigaction(SIGTERM, &termHandler, NULL);
    
    signal(SIGINT, signalHandlerSIGINT);

    switch(pid = fork())
    {
        case -1:
            printf("The child process was not created!");
            exit(0);
        case 0:
            atexit(childFoo);
            printf("    CHILD: I'm a child!\n");
            printf("    CHILD: My PID: %d  Parent PID: %d\n", getpid(), getppid());
            printf("    CHILD: Enter my return code: ");
            scanf("%d", &exCode);
            printf("    CHILD: Deth! :(\n");
            exit(exCode);
        default:
            atexit(parentFoo);
            printf("PARENT: I'm a parent!\n");
            printf("PARENT: My PID: %d  Child PID: %d\n", getpid(), pid);
            printf("PARENT: I'm waiting for my baby to die\n");
            wait(&exCode);
            printf("PARENT: Child Return Code: %d\n", WEXITSTATUS(exCode));
            printf("PARENT: Deth!\n");
    }

    printf("\n\n");

    while(1) sched_yield;

	return 0;
}