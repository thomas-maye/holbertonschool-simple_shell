#include "simple_shell.h"

/**
 * print_env - Prints the environment variables.
 * This function iterates through the array of environment variables
 * and prints each variable on a new line.
 *
 * @env: An array of strings representing the environment variables.
 *
 * Return: This function does not return a value, as it is of type void.
 */

void print_env(char **env)
{
	int i = 0;

	for (; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
