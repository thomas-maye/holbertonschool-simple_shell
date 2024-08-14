#include "main.h"

/**
 * exe_cmd - Forks a child process and executes the command.
 * @argv: Array of arguments for the execve call.
 */

void exe_cmd(char **argv)
{
        pid_t child_pid;
        int status;

        child_pid = fork();
        if (child_pid == -1)
        {
                perror("Error fork");
                return;
        }
        else if (child_pid == 0)
        {
                if (execve(argv[0], argv, NULL) == -1)
                {
                        perror("Error Shell");
                        return;
                }
        }
        else
                wait(&status);
}
