#include "simple_shell.h"

/**
 * _strcmp - the function
 * @s1: blabla
 * @s2: blabla2
 * Return: the difference between s1 and s2
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
