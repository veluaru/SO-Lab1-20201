#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    if (argc == 2)
    {
        char buffer[1000];
        while (fgets(buffer, 1000, stdin))
        {
            if (strstr(buffer, argv[1]) != NULL)
            {
                printf("%s", buffer);
            }
        }
    }
    else
    {

        for (int i = 2; i < argc; i++)
        {

            char *line = NULL;
            size_t lenght = 0;
            ssize_t read;
            //Si el line se inicializa en NULL y el lenght en 0 para mandarlos al getline, este reserva el espacio de memoria que
            //necesita para la linea por nosotros

            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL)
            {
                printf("wgrep: cannot open file\n");
                exit(1);
            }

            while ((read = getline(&line, &lenght, fp)) != -1)
            {

                if (strstr(line, argv[1]) != NULL)
                {
                    printf("%s", line);
                }
            }
            fclose(fp);
        }
    }

    return 0;
}