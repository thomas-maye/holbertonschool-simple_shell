#include "simple_shell.h"
/**
 * main - main entry of the programm that prins all arguments passed to it.
 *
 * @ac: the argument count not used
 * @av: the argument vector NULL terminated array of strings
 *
 * Return: Always 0 for succesful return.
 */
int main(int ac, char **av)
{
	(void)ac;/**unused parameter*/
	(void)av;

	shell_prompt();
	return (0);
}
