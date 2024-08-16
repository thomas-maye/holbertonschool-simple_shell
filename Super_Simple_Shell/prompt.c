#include "simple_shell.h"

/**
 * shell_prompt - program that prompts the user with a "$ " symbol,
 * waits for a command to be entered, and then prints the command
 * on the next line. It continues until the user input
 * an end-of-file(EOF) signal as Ctrl+D.
 *
 * Return: returns 0 when succesful, or error when fails.
 */
int shell_prompt(void)
{
	char *bufferinput = NULL;
	size_t buffersize = 0;
	ssize_t input;

	while (1)
	{
		printf("$ ");
		input = getline(&bufferinput, &buffersize, stdin);

		if (input == -1)/** end-of-file(EOF)*/
		{
			printf("\n");
			break;
		}

		if (bufferinput[input - 1] == '\n')
		{
			bufferinput[input - 1] = '\0';
		}

		if (bufferinput[input - 1] == '\0')
		{
			cmd_execute(bufferinput);
		}
	}
	free(bufferinput);
	return (0);
}

