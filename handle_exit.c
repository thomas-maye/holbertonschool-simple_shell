#include "simple_shell.h"

/**
 * handle_exit - Exits the shell program.
 * This function is responsible for terminating the shell program
 * and ensuring a successful exit by calling the `exit` function
 * with the status `EXIT_SUCCESS`.
 *
 * Return: This function does not return a value, as it is of type void.
 */

void handle_exit(void)
{
	exit(EXIT_SUCCESS);
}
