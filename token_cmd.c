#include "simple_shell.h"

/**
 * token_cmd - Splits the command line into individual arguments.
 * This function takes a command line input as a string and splits it
 * into individual tokens (arguments) based on spaces. The resulting
 * tokens are stored in an array of strings, which is dynamically
 * allocated and returned.
 *
 * @line_cmd: The command line input string to be tokenized.
 *
 * Return: A dynamically allocated array of strings (tokens), where each
 *         string is an argument from the command line. The last element
 *         of the array is set to NULL to indicate the end of the arguments.
 */

char **token_cmd(char *line_cmd)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Error allocation\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line_cmd, " ");
	while (token != NULL)
	{
		tokens[position] = strdup(token);
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Error allocation\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " ");
	}
	tokens[position] = NULL;
	return (tokens);
}

