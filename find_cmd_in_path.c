#include "simple_shell.h"

/**
 * find_path_in_env - function that searches PATH in an environment.
 * It searches in envp (pointers table to characters chains which
 * represents a variable each - envp is passed in the main function).
 *
 * @env: the environment
 *
 * Return: returns the absolute PATH of the file if it is found,
 * or NULL if is not found.i
 *
 */


char *find_path_in_env(char **env)
{
	int i = 0;

	if (env == NULL)
		return (NULL);

	for (; env[i] != NULL; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			return (env[i] + 5);
		}
	}
	return (NULL);
}


/**
 * find_cmd_in_path - Searches for a command in the system's PATH.
 * This function checks if the given command can be executed directly
 * or by searching through the directories listed in the PATH environment
 * variable. If the command is found, the full path to the executable is
 * returned; otherwise, NULL is returned.
 *
 * @cmd: The command that the user wants to execute, which may or may not
 *       include a full or relative path.
 * @env: the environement
 *
 * Return: A dynamically allocated string containing the full path to the
 *         command if found, or NULL if the command is not found in any
 *         of the directories in the PATH.
 */

char *find_cmd_in_path(char *cmd, char **env)
{
	char *path = find_path_in_env(env);
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char *full_path = malloc(1024);

	if (path == NULL)
	{
		return (NULL);
	}

	if (full_path == NULL)
	{
		free(path_copy);
		return (NULL);
	}

	if (access(cmd, X_OK) == 0)
	{
		free(path_copy);
		free(full_path);
		return (strdup(cmd));
	}

	while (token != NULL)
	{
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, cmd);

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
