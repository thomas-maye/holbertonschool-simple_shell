#include "main.h"

/**
 * token_cmd - Splits the command line into arguments.
 * @line_cmd: The command line input.
 * @argv: Array to store arguments.
 * Return: Number of arguments.
 */

int token_cmd(char *line_cmd, char **argv)
{
	int argc = 0;
	char *token = strtok(line_cmd, " ");

	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL;
	return (argc);
}
