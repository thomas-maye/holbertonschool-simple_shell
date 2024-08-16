#include <stdio.h>
#include <stdlib.h>

/**
 * main - the principal function
 * Return: nothing because void
 */

int main(void)
{
	char *command_line;
	size_t lenght_line = 0;
	int read_line;

	while (1)
	{
		printf("$ ");
		read_line = getline(&command_line, &lenght_line, stdin);

		if (read_line == -1)
		{
			break;
		}
		printf("%s", command_line);
	}
	free(command_line);
	return (0);
}
