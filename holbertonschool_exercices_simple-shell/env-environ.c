#include "simple_shell.h"


/**
 * print_path_directories - Prints each directory in PATH
 *
 * This function retrieves the PATH environment variable,
 * splits it into directories, and prints each directory.
 */
void print_path_directories(void)
{
	char *path;
	char *path_copy;
	char *token;

	path = getenv("PATH");

	if (path == NULL)
	{
		printf("PATH environment variable not found.\n");
		return;
	}
	path_copy = malloc(strlen(path) + 1);

	if (path_copy == NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}
	strcpy(path_copy, path);

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}

	free(path_copy);
}


/**
 * build_path_list - Function that builds a linked list of PATH directories
 *
 * Return: return a pointer to the head of the linked list
 * or return  NULL if it fails
 *
 */
path_list *build_path_list(void)
{
	char *path = getenv("PATH"), *path_copy, *token;
	path_list *head = NULL, *current = NULL;

	if (path == NULL)
		return (NULL);
	path_copy = malloc(strlen(path) + 1);
	if (path_copy == NULL)
		return (NULL);
	strcpy(path_copy, path);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		path_list *new_node = malloc(sizeof(path_list));

		if (new_node == NULL)
		{
			free(path_copy);
			free_path_list(head);
			return (NULL);
		}
		new_node->directory = malloc(strlen(token) + 1);
		if (new_node->directory == NULL)
		{
			free(new_node);
			free(path_copy);
			free_path_list(head);
			return (NULL);
		}
		strcpy(new_node->directory, token);
		new_node->next = NULL;
		if (head == NULL)
			head = new_node;
		else
			current->next = new_node;
		current = new_node;
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (head);
}

/**
 * free_path_list - Function that frees the linked list
 *
 * @head: Pointer to the head of the linked list
 *
 */
void free_path_list(path_list *head)
{
	path_list *current = head;
	path_list *next;

	while (current != NULL)
	{
		next = current->next;
		free(current->directory);
		free(current);
		current = next;
	}
}

/**
 * print_environment - Function that prints all environment variables
 * iterating through the global environ array to print them all
 *
 * Return: no return
 */
void print_environment(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

/**
 * main - Main entry point of the program. Function that prints
 * the adresses of env and environ, then calls function
 * print_environment.
 *
 * @argc: Number of command-line arguments
 * @argv: An array of command-line argument strings
 * @env: Environment variable array passed
 *
 * Return: Returns always 0 > success
 */
int main(int argc, char *argv[], char *env[])
{
	printf("Address of env: %p\n", (void *)env);
	printf("Address of environ: %p\n", (void *)environ);

	printf("\nPrinting environment variables:\n");
	print_environment();

	return (0);
}
