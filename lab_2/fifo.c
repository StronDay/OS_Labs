#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

int main()
{
    time_t begin = time(NULL);

    if (mkfifo("fifoFile", 0777))
    {
        if (errno != EEXIST)
        {
            printf("The fifa file was not created\n");
            return 1;
        }
    }

    int id = fork();

    if (id != 0)
    {
        int file = open("fifoFile", O_RDWR);

        time_t end = time(NULL);

        int out[2];
        out[0] = getpid();
        out[1] = (end - begin);

        write(file, &out, sizeof(int) * 2);
        

        wait(0);
        close(file);
    }

    if (id == 0)
    {
        int file = open("fifoFile", 'r');

        sleep(5);
        time_t end = time(NULL);

        int in[2];
        read(file, &in, sizeof(int)*2);

        close(file);

        printf("Parent pid: %d, Parent time: %d, Chail time: %ld\n", in[0], in[1], (end - begin));
    }

    return 0;
}