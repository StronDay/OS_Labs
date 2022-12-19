#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int eflag = 0;
int nflag = 0;
int sflag = 0;
int bflag = 0;

void fileOutput(const char *fileName)
{
    int ch;
    FILE *file;
    if ((file = fopen(fileName, "r")) == NULL)
    {
        fprintf (stderr, "Unknown name file\n");
        exit(0);
    }

    unsigned int size = 1024;
    unsigned int num = 0;
    unsigned int counter = 0;

    char buffer[size];
    char symb;

    if (!eflag && !nflag && !sflag && !bflag)
    {
        while (fgets(buffer, size, file))
        {
        printf("%s", buffer);
        }
        printf("\n");
    }

    if (eflag)
    {

        while (!feof(file) && !ferror(file))
        {
            symb = fgetc(file);
            if (symb == '\r') printf("$");
            printf("%c", symb);
        }
        printf("\n");
    }

    if (nflag)
    {
        while (fgets(buffer, size, file))
        {
        num++;
        printf("%d\t%s", num, buffer);
        }
        printf("\n");
    }

    if (sflag)
    {
        // TODO
    }

    if (bflag)
    {
        while (fgets(buffer, size, file))
        {
            if (buffer[0] != '\r')
            {
                num++;
                printf("%d\t%s", num, buffer);
            }
            else 
            {
                printf("\t%s", buffer);
            }
        }
        printf("\n");
    }

    fclose(file);
}

int main(int argc, char **argv)
{
    int retGetopt;

    //fork();

    while((retGetopt = getopt(argc, argv, "ensb")) != -1)
    {
        switch(retGetopt)
        {
            case 'e': // показывать символ $ в конце каждой строки;
                eflag = 1;
                break;

            case 'n': // нумеровать все строки;
                nflag = 1;
                break;

            case 's': // удалять пустые повторяющиеся строки;
                sflag = 1;
                break;

            case 'b': // нумеровать только непустые строки;
                bflag = 1;
                break;

            case '?':
            if (isprint (optopt))
            {
                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
            }
            else
            {
                fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                return 1;
            }
        }
    }

    for(int i = optind; i < argc; i++)
    {
        fileOutput(argv[i]);
    }

    return 0;
}