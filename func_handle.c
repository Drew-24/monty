#include "monty.h"
#define BUFFSIZE 1024
/**
 * func_handle - function that handles a file
 * @ac: parameter
 * @av: parameter
 * Return: 0
 */
void func_handle(char **av)
{
    const char *delim = " ";
    const char *file = "file.txt";
    FILE *input_file = fopen(file, "r");
    char buffer [BUFFSIZE];
    char *token;

    if (!input_file)
        fprintf(stderr, "Error: Can't open file %s\n", file);
    else
    {
        while (getline(buffer, BUFFSIZE, input_file) == 1)
        {
            token = strtok(buffer, delim);
            while (token != NULL)
            {
                printf("%s\n", token);
                token = strtok(NULL, delim);
            }
            
        }
        if (ferror(input_file))
            perror("Error:");
        fclose(input_file);
    }
}