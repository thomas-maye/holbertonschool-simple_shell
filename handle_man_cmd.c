#include "simple_shell.h"


/**
 * handle_builtin_cmd - function that handle built-in commands
 * of the simple-shell by displaying help of
 * provide user command input.
 *
 * @args: arguments inputed by user, for which he desires help
 *
 * Returns: no return (void)
 *
 */
void handle_builtin_cmd(char **args)
{
	if (strcmp(args[1], "env") == 0)
	{
		printf("env: prints the current environment variables.\n");
		return;
	}

	if (strcmp(args[1], "exit") == 0)
	{
		printf("exit: exit the simple_shell.\n");
		return;
	}

	printf("no manual entry for %s\n", args[1]);
}


/**
 * handle_man_cmd - function that displays help for built-in commands
 * It displays help information of buil-in commands supported
 * by Nico & Tom's Shell. User has to types 'man <comand>'.
 *
 * @args: arguments inputed by user, for which he desires help
 *
 * Return: No return (void)
 */
void handle_man_cmd(char **args)
{
	pid_t pid;
	int status;
	char *man_path, *man_args[3];

	if (args[1] == NULL)
	{
		printf("Usage: man <command>\n");
		return;
	}
	if (strcmp(args[1], "hsh") == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Fork error");
			return;
		}
		else if (pid == 0)
		{
			man_args[0] = "man";
			man_args[1] = "./man_1_simple_shell";
			man_args[2] = NULL;

			man_path = find_cmd_in_path("man", environ);
			if (man_path == NULL)
			{
				perror("error: man command not found");
				exit(EXIT_FAILURE);
			}
			execve(man_path, man_args, environ);
			perror("error executing man");
			free(man_path);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
		return;
	}
	handle_builtin_cmd(args);
}
