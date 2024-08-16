#include "simple_shell.h"

/**
 * main - Entry point for the simple shell program.
 * This function initializes the shell by displaying the prompt and waiting
 * for user input to execute commands.
 *
 * @argc: Argument count, representing the number of command-line arguments.
 *        This parameter is unused in this implementation.
 * @argv: Argument vector, an array of strings representing the command-line
 *        arguments. This parameter is unused in this implementation.
 * @env:  Environment variables, passed to the shell for use during
 *        command execution.
 *
 * Return: Always returns 0 to indicate successful execution.
 */

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	new_shell_prompt(env);
	return (0);
}
