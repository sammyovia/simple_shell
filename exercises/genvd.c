#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(void)
{
	extern char **environ;
	printf("The begininng of environ is %p\n",&(*environ));

    return (0);
}
