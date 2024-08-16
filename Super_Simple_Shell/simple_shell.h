#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/**
 * Description - Header file containing function prototypes, macros,
 * global variables and structures for the simple shell program.
 *
 * @authors: Thomas Mayé - Nicolas Martinez
 * @date: 13.08.2024
 *
 */


/** LIBRARIES */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* Declare environ as an external variable */
extern char **environ;



/**PATH LIST  STRUCT */

/**
 * struct PathList - Linked list node representing a directory in PATH.
 * It is used for dynamic storage and traversal of different directories,
 * when we need to search for executables
 * in different directories specified in the PATH.
 *
 * @directory: pointer to a string (char *) which is the name of the directory.
 * It is dynamically allocated so free is required when not needed anymore.
 *
 * @next: Pointer to the next node in the linked list
 *
 */
typedef struct PathList
{
	char *directory;
	struct PathList *next;
} path_list;




/**MACROS */

/** Buffer size for reading input */
#define BUFFER_SIZE 1024
/** Max PATH length */
#define MAX_PATH_LENGTH 4096
/** Max array size and delimiters for reading input using strtok*/
#define MAX_WORDS 100
#define DELIMITERS " \t\r\n\a"
/*
 * number of different child processes executed
 * trhought the command ls -l /tmp
 */
/** #define NUM_CHILDREN 5 */




/** FUNCTION PROTOTYPES */

/** main.c */
int main(int ac, char **av);

/** prompt.c */
int shell_prompt(void);

/** exec.c */
void cmd_execute(char *cmd);
	
/** fork.c */
void cmd_fork_execute(char *command, char **args);i

/** env-main.c */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void print_environment(void);

/** path.c */
int search_incurrentpath(int argc, char **argv);
int check_file_in_path(const char *dir, const char *file);


/** wait.c
void wait_for_child(pid_t pid);

stat.c 
int file_status(int argc, char **argv);

env-environ.c
void print_path_directories(void);
path_list *build_path_list(void);
void free_path_list(path_list *head);
int environ_adress(int ac, char **av);
**/




#endif /* MAIN_H */

