#include "simple_shell.h"

/**
 * handle_cmd_prompt - Command that manages and processes orders related
 * to env and exit
 *
 * @args: the array of argument
 * @env: An array of strings representing the environment variables, which
 *       can be accessed by the shell or passed to executed commands.
 *
 * Return : This function does not return any value, as it is of type void.
 */

void handle_cmd_prompt(char **args, char **env)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		exit(EXIT_SUCCESS);
	}

	else if (strcmp(args[0], "env") == 0)
	{
		print_env(env);
	}

	else if (strcmp(args[0], "man") == 0)
	{
		handle_man_cmd(args);
	}

	else
	{
		exe_cmd(args, env);
	}
}
/**
 * new_shell_prompt - Displays the shell prompt and processes user input.
 * This function continuously displays a shell prompt, reads user input,
 * tokenizes the input into commands, and executes the appropriate function
 * based on the command entered.
 *
 * @env: An array of strings representing the environment variables, which
 *       can be accessed by the shell or passed to executed commands.
 *
 * Return: This function does not return any value, as it is of type void.
 */
void new_shell_prompt(char **env)
{
	char *line = NULL, **args;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("Nico & Tom's Shell$ ");
			fflush(stdout);
		}
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		if (nread > 0 && line[nread - 1] == '\n')
		{
			line[nread - 1] = '\0';
			nread--;
		}

		if (nread == 0)
			continue;
		args = token_cmd(line);

		if (args == NULL || args[0] == NULL)
		{
			if (args)
				free_args(args);
			continue;
		}

		handle_cmd_prompt(args, env);
		free_args(args);
	}
	free(line);
}
