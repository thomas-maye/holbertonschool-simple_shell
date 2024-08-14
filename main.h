#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void);
int token_cmd(char *line_cmd, char **argv);
void exe_cmd(char **argv);
char *find_cmd_in_path(char *cmd);

#endif
