#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/**
 * Description - Header file containing function prototypes, macros,
 * global variables and structures for the simple shell program.
 *
 * @authors: Thomas Mayé - Nicolas Martinez
 * @date: 19.08.2024
 *
 */

/** Macros */
#define DELIMITERS " \t\r\n\a"

/** LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/** Prototypes */
void new_shell_prompt(char **env);
void exe_cmd(char **args, char **env);
char *find_path_in_env(char **env);
char *find_cmd_in_path(char *cmd, char **env);
void print_env(char **env);
char **token_cmd(char *line);
void free_args(char **args);
void handle_exit(void);
int count_tokens(char *line_cmd);

#endif
