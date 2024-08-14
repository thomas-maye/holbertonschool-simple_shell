#include "main.h"

/**
 * main - Main function to display prompt and execute commands.
 * Return: 0 on success.
 */

int main(void)
{
	char *command_line = NULL;
	size_t len = 0;
	ssize_t num_chars_read;
	char *argv[1024];

	while (1)
	{
		printf("#cisfun$ ");
		num_chars_read = getline(&command_line, &len, stdin);

		if (num_chars_read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror("getline");
			break;
		}

		if (num_chars_read > 0 && command_line[num_chars_read - 1] == '\n')
			command_line[num_chars_read - 1] = '\0';

		if (command_line[0] != '\0')
		{
			int argc = token_cmd(command_line, argv);

			if (argc > 0)
				exe_cmd(argv);
		}
	}
	free(command_line);
	return (0);
}
