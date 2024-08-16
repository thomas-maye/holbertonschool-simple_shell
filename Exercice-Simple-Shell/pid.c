#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("Process : %u\n", my_pid);
    my_pid = getppid();
    printf("Parent process : %u\n", my_pid);
    return (0);
}
