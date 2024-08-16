#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void new_shell_prompt(char **env);
void exe_cmd(char **args, char **env);
char *find_cmd_in_path(char *command);
void print_env(char **env);
char **token_cmd(char *line);
void free_args(char **args);
void handle_exit(void);

#endif
