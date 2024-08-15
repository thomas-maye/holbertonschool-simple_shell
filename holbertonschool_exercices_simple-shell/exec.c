#include "simple_shell.h"

/**
 * cmd_execute - program that executes command and called
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
	char **args;
	int i;


	args = split_string(cmd);

	if (args == NULL)
	{
		fprintf(stderr, "Error: parsing command failed\n");
		return;
	}

	if (execve(args[0], args, NULL) == -1)
	/** ! >> set NULL to envp for environement variable in simple shell**/
	{
		perror("Error executing command");
	}
	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}


/**
 * cmd_execute_fivechildren - Entry point function for the program
 * It creates 5 NUM_CHILDREN child processes (defined in the header file),
 * each executing the command "ls -l /tmp".
 * The parent process waits for each child to complete
 * before creating the next one.
 *
 * Return: Returns 0 on successful completion, or EXIT_FAILURE if fork fails.
 */
int cmd_execute_fivechildren(void)
{
	for (int i = 0; i < NUM_CHILDREN; i++)
	{
		pid_t pid = create_child();

		if (pid == 0)
		{
			cmd_execute("ls -l /tmp");
			exit(EXIT_SUCCESS);
		}
		else if (pid > 0)
		{
			wait_for_child(pid);
		}
		else
		{
			perror("Error: fork failed");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
/**
 * cmd_execute_inchildren - Executes a given command splitting
 * its string
 *
 * @cmd: The command string to be executed
 *
 * Return: no return when succeeded
 */
void cmd_execute_inchildren(char *cmd)
{
	char *argv[4];
	char *envp[1];
	char *full_path;

	argv[0] = "ls";
	argv[1] = "-l";
	argv[2] = "/tmp";
	argv[3] = NULL;
	envp[0] = NULL;

	full_path = "/bin/ls";

	if (execve(full_path, argv, envp) == -1)
	{
		perror("Error: execution failed");
		exit(EXIT_FAILURE);
	}
}

/**
 * create_child - Creates a new child process by forking the current process
 * to create a new child process.
 *
 * Return: Returns the process ID of the child to the parent
 * returns 0 to the child, or -1 on error
 */
pid_t create_child(void)
{
	return (fork());
}


/**
 * wait_for_child - Function that waits a terminating specific child process
 * in suspending execution of the calling process
 *
 * @pid: The process ID of the child to wait for
 *
 * Return: no return
 *
 */

void wait_for_child(pid_t pid)
{
	waitpid(pid, NULL, 0);
}
