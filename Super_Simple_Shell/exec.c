#include <stdio.h>
#include <unistd.h>
/**
 * main - program that executes command and called
 * in shell_prompt function
 *
 * @cmd: String containing the command to execute, including any
 * arguments. It should be in the format expected by the execve function
 *
 * Return: no return.
 * Executes command or prints error message to stderr if failed to.
 */
void cmd_execute(char *cmd)
{
	char *args[MAX_WORDS];
	char *token;
	int i = 0;

	token = strtok(cmd, DELIMITERS);

	while (token != NULL && i < MAX_WORDS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, DELIMITERS);
	}
	args[i] = NULL;

	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_environment();
	}
	else
	{
		cmd_execute(args[0], args);
	}
}

