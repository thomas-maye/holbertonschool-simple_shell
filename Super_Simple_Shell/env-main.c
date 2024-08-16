#include "simple_shell.h"

/**
 * _getenv - Function that get the value of an environment variable
 * by searching the environment list for a variable
 * matching the given name.
 *
 * @name: Name of the environment variable to get
 *
 * Return: returns a pointer to the value in the environment,
 * or NULL if it is not found
 *
 */
char *_getenv(const char *name)
{
	int i;
	size_t name_len;

	name_len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (&environ[i][name_len + 1]);
		}
	}

	return (NULL);
}


/**
 * _setenv - Function that change existig or add a new environment variable
 *
 * @name: Name of the environment variable
 * @value: Valueint main(int argc, char *argv[], char *env[]);
 * @overwrite: Determine if existing variable has to be overwritten
 *
 * Return: returns 0 if succeeded or -1 if there is an error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *exist, *new_var, **new_environ;
	size_t len;
	int i, count;

	exist = _getenv(name);

	if (exist && !overwrite)
	{
		return (0);
	}
	len = strlen(name) + strlen(value) + 2;
	new_var = (char *)malloc(len);
	if (!new_var)
	{
		return (-1);
	}
	sprintf(new_var, "%s=%s", name, value);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 &&
				environ[i][strlen(name)] == '=')
		{
			environ[i] = new_var;
			return (0);
		}
	}
	count = 0;
	while (environ[count] != NULL)
		count++;
	new_environ = (char **)realloc(environ, (count + 2) * sizeof(char *));
	if (!new_environ)
	{
		free(new_var);
		return (-1);
	}
	environ = new_environ;
	environ[count] = new_var;
	environ[count + 1] = NULL;
	return (0);
}

/**
 * _unsetenv - Function that remove an environment variable
 * from environment list
 *
 * @name: Name of the environment variable to remove
 *
 * Return: returns  0 if succeeded or -1 if there is an error
 */
int _unsetenv(const char *name)
{
	int i, j;
	size_t name_len;

	name_len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			i--;
		}
	}

	return (0);
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
		printf("%s\n", environ[i]);                                                                               }
}
