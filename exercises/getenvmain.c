#include <stdio.h>
#include "main.h"

/**
 * main - gets the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    unsigned int i;

    i = 0;
    while (env[i] != NULL)
    {
        _getenv("%s\n", env[i]);
        i++;
    }
    return (0);
}
