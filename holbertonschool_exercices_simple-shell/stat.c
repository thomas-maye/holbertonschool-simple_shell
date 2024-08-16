#include "simple_shell.h"
/**
 * file_stat - Function that check file status using stat system call
 *
 * @path: path of the file to check
 *
 * Return: Returns 0 on success or 1 on error
 */
int file_stat(const char *path)
{
    struct stat st;

    if (stat(path, &st) == 0)
    {
        return (0);
    } 
    else
    {
	    perror("Error");
	    return (-1);
    }
}
