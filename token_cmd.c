#include "simple_shell.h"

/**
 * count_tokens - Counts the number of tokens in the command line.
 * @line_cmd: The command line input string to be tokenized.
 *
 * Return: The number of tokens.
 */

int count_tokens(char *line_cmd)
{
	int count = 0;
	char *cp_line_cmd = strdup(line_cmd);
	char *token;

	if (!cp_line_cmd)
	{
		fprintf(stderr, "Error allocation\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(cp_line_cmd, DELIMITERS);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, DELIMITERS);
	}

	free(cp_line_cmd);
	return (count);
}

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
	int num_tokens = count_tokens(line_cmd);
	char **tokens = malloc((num_tokens + 1) * sizeof(char *));
	char *token;
	int position = 0;

	if (!tokens)
	{
		fprintf(stderr, "Error allocation\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line_cmd, DELIMITERS);
	while (token != NULL)
	{
		tokens[position] = strdup(token);
		if (!tokens[position])
		{
			fprintf(stderr, "Error allocation\n");
			exit(EXIT_FAILURE);
		}
		position++;
		token = strtok(NULL, DELIMITERS);
	}
	tokens[position] = NULL;
	return (tokens);
}
