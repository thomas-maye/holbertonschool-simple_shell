#include "simple_shell"
/**
 * search_incurrentpath - Search for files in the current PATH
 *i
 * @argc: Count of arguments
 * @argv: Arguments vector
 *
 * Return: return 0 on success or 1 if failed
 */
int search_incurrentpath(int argc, char **argv)
{
	char *path;
	char *dir;
	char path_copy[MAX_PATH_LENGTH];
	int i;

	if (argc < 2)
	{
		printf("Usage:%s filename\n", argv[0]);
		return (1);
	}

	path = getenv("PATH");
	if (path == NULL)
	{
		printf("PATH environment variable not found.\n");
		return (1);
	}

	strncpy(path_copy, path, sizeof(path_copy) - 1);
        path_copy[sizeof(path_copy) - 1] = '\0';

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
		strncpy(path_copy, path, sizeof(path_copy) - 1);
		path_copy[sizeof(path_copy) - 1] = '\0';
	}
	return (0);
}

/**
 * check_file_in_path - Check if a file exists in a directory
 *
 * @dir: directory where to search
 * @file: File we want to find
 *
 * Return: returns 1 if file is found or 0 if not
 */
int check_file_in_path(const char *dir, const char *file)
{
    char full_path[MAX_PATH_LENGTH];
    struct stat st;

    /** create full path concatenating directory and file name in full_path buffer */
    snprintf(full_path, sizeof(full_path), "%s/%s", dir, file);

	/** check if file exist at full path */
    return (stat(full_path, &st) == 0);
}

