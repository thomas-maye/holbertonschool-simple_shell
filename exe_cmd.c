#include "simple_shell.h"

/**
 * exe_cmd - Creates a child process to execute a command.
 * This function forks the current process to create a child process.
 * The child process then attempts to execute the command specified by the
 * user. If the command is not found in the system's PATH, an error is
 * displayed. The parent process waits for the child process to finish
 * execution before continuing.
 *
 * @args: An array of arguments where the first element is the command and
 *        the following elements are the command's arguments, all passed to
 *        execve.
 * @env:  An array of strings representing the environment variables, which
 *        are passed to the execve system call.
 *
 * Return: This function does not return a value, as it is of type void.
 */

void exe_cmd(char **args, char **env)
{
	pid_t pid;
	int status;
	char *cmd_path;

	cmd_path = find_cmd_in_path(args[0]);
	if (cmd_path == NULL)
	{
		perror(args[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error fork");
		free(cmd_path);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(cmd_path, args, env) == -1)
		{
			perror("Error execve ./shell");
			free(cmd_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	free(cmd_path);
}
