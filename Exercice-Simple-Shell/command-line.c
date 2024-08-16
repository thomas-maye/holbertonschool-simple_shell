#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - the principal function
 * Return: nothing because void
 */

int main(void)
{
	char *input_line = NULL, *word;
	size_t buffer_size = 0;
	int line_lenght;

	printf("$ ");
	line_lenght = getline(&input_line, &buffer_size, stdin);

	if (line_lenght == -1)
	{
		free(input_line);
		return (1);
	}

	printf("%s", input_line);

	word = strtok(input_line, " ");
	while (word != NULL)
	{
		printf("%s\n", word);
		word = strtok(NULL, " ");
	}

	free(input_line);
	return (0);
}
