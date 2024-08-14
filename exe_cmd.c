#include "main.h"

/**
 * exe_cmd - Forks a child process and executes the command.
 * @argv: Array of arguments for the execve call.
 */

void exe_cmd(char **argv)
{
	pid_t child_pid;
	int status;
	char *cmd_path;

	cmd_path = find_cmd_in_path(argv[0]);

	if (cmd_path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", argv[0]);
		free(cmd_path);
		return;
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error fork");
		free(cmd_path);
		return;
	}
	else if (child_pid == 0)
	{
		if (execve(cmd_path, argv, NULL) == -1)
		{
			perror("Error Shell");
			free(cmd_path);
			return;
		}
	}
	else
	{
		wait(&status);
		free(cmd_path);
	}
}
