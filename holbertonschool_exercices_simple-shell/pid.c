#include "simple_shell"
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("PID process is : %u\n", my_pid);
	return (0);
}
