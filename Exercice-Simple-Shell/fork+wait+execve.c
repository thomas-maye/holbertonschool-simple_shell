#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - the principal function
 * Return: 0
 */

int main(void)
{
	pid_t my_pid;
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int status;
	int i = 0;

	my_pid = getpid();
	while (i <= 4 && (child_pid != 0))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		wait(&status);
	}
	if (child_pid == 0)
	{
		printf("Process : %u\nParent process : %u\n", getpid(), getppid());
	}
	else
	{
		printf("%u is the parent process and his ID is %u\n", my_pid, child_pid);
	}
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	return (0);
}
