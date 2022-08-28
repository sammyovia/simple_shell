#include <stdio.h>

/**
 * main - prints the arguments passed
 * @argc: argument count
 * @argv: point
 * Return: on sucess
 */

int main(int ac, char **av)
{
        while (ac--)
                printf("%s\n", *av++);
        return (0);
}
