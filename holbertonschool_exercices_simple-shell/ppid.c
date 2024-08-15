#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
/**
 * main - PPID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("PID parent process is : %u\n", my_ppid);
	return (0);
}
