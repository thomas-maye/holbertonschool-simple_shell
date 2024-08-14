#include "main.h"

/**
 * find_cmd_in_path - find the path in the different directory
 * @cmd: the commande that the user wants
 * Return: NULL after the command
 */

char *find_cmd_in_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_dup = strdup(path);
	char *dir = strtok(path_dup, ":");
	char *full_path = malloc(1024);

	if (!full_path || !path_dup)
	{
		perror("Error allocating memory");
		free(full_path);
		return (NULL);
	}

	while (dir != NULL)
	{
		snprintf(full_path, 1024, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path_dup);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_dup);
	free(full_path);
	return (NULL);
}

