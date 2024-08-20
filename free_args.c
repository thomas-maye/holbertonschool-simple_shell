#include "simple_shell.h"

/**
 * free_args - Frees memory allocated for an array of arguments.
 * This function iterates through an array of strings (arguments) and frees
 * the memory allocated for each string, as well as the memory allocated
 * for the array itself.
 *
 * @args: An array of strings representing command-line arguments,
 *        typically allocated dynamically.
 *
 * Return: This function does not return a value, as it is of type void.
 */

void free_args(char **args)
{
	int i = 0;

	for (; args[i]; i++)
		free(args[i]);
	free(args);
}
