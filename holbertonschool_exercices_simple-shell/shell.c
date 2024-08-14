#include "simple_shell.h"

/**
 * check_file_in_path - Check if a file exists in a directory
 *
 * @dir: directory wher to search
 * @file: File we want to find
 *
 * Return: 1 if file is found, or 0 if not
 */
int check_file_in_path(const char *dir, const char *file)
{
	char full_path[MAX_PATH_LENGTH];
	struct stat st;

	strcpy(full_path, dir);
	strcat(full_path, "/");
	strcat(full_path, file);

	return (stat(full_path, &st) == 0);
}

/**
 * search_incurrentpath - Search for files in the current PATH
 *
 * @argc: Count of arguments
 * @argv: Arguments vector
 *
 * Return: 0 on success, 1 if failed
 */
int search_incurrentpath(int argc, char **argv)
{
	char *path;
	char *dir;
	int i;

	if (argc < 2)
	{
		printf("%s filename ...\n", argv[0]);
		return (1);
	}

	path = getenv("PATH");
	if (path == NULL)
	{
		printf("PATH environment variable not found.\n");
		return (1);
	}

	for (i = 1; i < argc; i++)
	{
		printf("%s:", argv[i]);
		dir = strtok(path, ":");
		while (dir != NULL)
		{
			if (check_file_in_path(dir, argv[i]))
			{
				printf("Found in %s\n", dir);
				break;
			}
			dir = strtok(NULL, ":");
		}
		if (dir == NULL)
		{
			printf("Not found\n");
		}
	}

	return (0);
}
