#include "simple_shell"

/**
 * cmd_fork_execute - function that forks a child process and
 * to execute the command using execve
 *
 * @cmd: The command string to be executed
 *
 * Return: no return when succeeded
 */
void cmd_fork_execute(char *command, char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(command, args) == -1)
        {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("Error");
    }
    else
    {
        wait(&status);
	
	if (WIFEXITED(status) || WIFSIGNALED(status))
	{
		return;
	}
    }
}
