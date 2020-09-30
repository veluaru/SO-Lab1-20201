#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        char c;
        char binario[4];
        int contador = 1;
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        c = fgetc(fp);
        while (c != EOF)
        {
            if (contador == 5)
            {
                int x = (binario[3] << 24) | (binario[2] << 16) | (binario[1] << 8) | binario[0];
                for (int a = 0; a < x; a++)
                {
                    printf("%c", c);
                }
                contador=0;
            }
            else
            {
                binario[contador - 1] = c;
            }
            c = fgetc(fp);
            contador = contador + 1;
        }

        fclose(fp);
    }

    return 0;
}