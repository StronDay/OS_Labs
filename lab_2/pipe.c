#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    time_t begin = time(NULL);

    int fd[2];

    if (pipe(fd) == -1)
    {
        printf("Errrr!...");
        return 1;
    }

    int id = fork();

    if (id != 0)
    {
        close(fd[0]);

        time_t end = time(NULL);

        int out[2];
        out[0] = getpid();
        out[1] = end - begin;

        printf("PARENT: my pid: %d\n", out[0]);
        
        write(fd[1], &out, sizeof(int) * 2);
        close(fd[1]);
        wait(NULL);
    }

    if (id == 0)
    {
        close(fd[1]);

        sleep(5);

        time_t end = time(NULL);

        int in[2];

        read(fd[0], &in, sizeof(int) * 2);

        printf("CHILD: parent time: %d, parent pid: %d, child time: %ld\n", in[1], in[0], (end - begin));
        close(fd[0]);
    }

    return 0;
}
