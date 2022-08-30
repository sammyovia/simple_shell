#include <stdio.h>
#include "main.h"

/**
 * main - gets the environment
 *
 * Return: Always 0.
 */
/*int main(int ac, char **av, char **env)
{
    unsigned int i;

    i = 0;
    while (env[i] != NULL)
    {
        _getenv("%s\n", env[i]);
        i++;
    }
    return (0);
}*/

#include<stdio.h>
	#include<stdlib.h>

	int main ()
	{
		char * ptr_path;
		ptr_path = _getenv("PATH");

		if (ptr_path!=NULL)
			printf ("The set PATH is: %s\n",ptr_path);
		else
			printf("Nothing to show\n");

		return 0;
	}

