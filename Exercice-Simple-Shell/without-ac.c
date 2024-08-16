#include <stdio.h>
#include <stdlib.h>

/**
 * main - the principal function
 * @ac: is the number of items in av
 * @av: is a NULL terminated array of strings
 * Return: 0
 */

int main(int ac, char **av)
{
	int i = 0;
	(void)ac;

	while (av[i])
	{
		printf("%s", av[i]);
		i++;
	}
	printf("\n");
	return (0);
}
