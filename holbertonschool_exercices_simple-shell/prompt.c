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
	char **arg;

	arg = av;

	while (*arg != NULL)
	{
		printf("%s\n", *arg);
		arg++;
	}
	shell_prompt();
	return (0);
}

/**
 * shell_prompt - program that prompts the user with a "$ " symbol,
 * waits for a command to be entered, and then prints the command
 * on the next line. It continues until the user input
 * an end-of-file(EOF) signal as Ctrl+D.
 *
 * Return: returns 0 when succesful, or error when fails.
 *
 */
int shell_prompt(void)
{
	char *bufferinput = NULL;
	size_t buffersize = 0;
	ssize_t input;

	while (1)
	{
		printf("$ ");
		input = getline(&bufferinput, &buffersize, stdin);

		if (input == -1)/** end-of-file(EOF)*/
		{
			printf("\n");
			break;
		}

		if (bufferinput[input - 1] == '\n')
		{
			bufferinput[input - 1] = '\0';
		}

		cmd_execute(bufferinput);
	}
	free(bufferinput);
	return (0);
}

/**
 * split_string - program that splits a string into words named tokens
 * based on delimiters which are defined in the header file.
 *
 * @str: the string to parse
 *
 * Return: returns array of strings or NULL if there is an error.
 *
 */
char **split_string(const char *str)
{
	char **words = NULL;
	char *token, *str_copy;
	int count = 0, i;

	words = (char **)malloc(MAX_WORDS * sizeof(char *));
	/**arrays pointers table allocation*/
	if (words == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (NULL);
	}
	str_copy = strdup(str);
	if (str_copy == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		free(words);
		return (NULL);
	}
	token = strtok(str_copy, DELIMITERS);
	/** divide arrays in token(words) which are copied in "words" table*/
	while (token != NULL && count < MAX_WORDS)
	{
		words[count] = strdup(token);
		if (words[count] == NULL)/**free all memory allocated if alloc failure*/
		{
			fprintf(stderr, "Memory allocation error\n");
			for (i = 0; i < count; i++)
			{
				free(words[i]);
			}
			free(words);
			free(str_copy);
			return (NULL);
		}
		count++;
		token = strtok(NULL, DELIMITERS);
	}
	words[count] = NULL;
	free(str_copy);
	return (words);
}
