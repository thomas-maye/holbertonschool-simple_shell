#include "simple_shell.h"

/**
 * find_cmd_in_path - Searches for a command in the system's PATH.
 * This function checks if the given command can be executed directly
 * or by searching through the directories listed in the PATH environment
 * variable. If the command is found, the full path to the executable is
 * returned; otherwise, NULL is returned.
 *
 * @cmd: The command that the user wants to execute, which may or may not
 *       include a full or relative path.
 *
 * Return: A dynamically allocated string containing the full path to the
 *         command if found, or NULL if the command is not found in any
 *         of the directories in the PATH.
 */

char *find_cmd_in_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char *full_path = malloc(1024);

	if (access(cmd, X_OK) == 0)
	{
		free(path_copy);
		return (strdup(cmd));
	}

	while (token != NULL)
	{
		snprintf(full_path, 1024, "%s/%s", token, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	free(full_path);
	return (NULL);
}
