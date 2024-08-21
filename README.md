![instagram_feed180](https://github.com/user-attachments/assets/6ee6244d-5e42-4ec7-9122-8d086b28f423)

# Project Holberton : C - Simple Shell

## Description 📄

> [!NOTE]
> Our program is a simple C shell that allows a user to execute commands from the command line.
It runs interactively, displaying a prompt (Nico & Tom's Shell$) where the user can enter commands.
The program parses these commands, executes them, and displays the results.

## Setup 💿

To clone the repo using `https://github.com/thomas-maye/holbertonschool-simple_shell.git`

## Command of Compilation 📥

The compilation command to compile the files that make up the Simple Shell is as follows :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Requirements ⚙️

- [x] Allowed editors : `vi`, `vim`, `emacs`
- [x] Our files compile on `Ubuntu 20.04 LTS`
- [x] Our code of respect Betty code Style and Betty Doc
- [x] We have no more than five functions per file
- [x] All function prototypes can be found in `simple_shell.h`

## Functions 🧰

- **main.c :**

*The program entry point*

Prototype : `int main(void);`

- **new_shell_prompt.c :**

*This function displays the prompt and reads user commands*

Prototype : `void new_shell_prompt(char **env);`
& Prototype : `void handle_cmd_prompt(char **args, char **env);`

- **token.cmd.c :**

*This function divides the command entered by the user into words called tokens*

Prototype : `char **token_cmd(char *line);`
Prototype : `int count_tokens(char *line_cmd)`

- **exe_cmd.c :**

*This function executes the command entered by the user*

Prototype : `void exe_cmd(char **args, char **env);`

- **find_cmd_in_path.c :**

*This function searches for the command entered in the path and if the command is executable*

Prototype : `char *find_cmd_in_path(char *command);`
& Prototype : `char *find_path_in_env(char **env)`

- **print_env.c :**

*This function displays environment variables*

Prototype : `void print_env(char **env);`

- **handle_exit.c :**

*This function manages the program output*

Prototype : `void handle_exit(void);`

- **free_args.c :**

*This function frees the memory allocated to the arguments*

Prototype : `void free_args(char **args);`

## The header file

* Our header file is a file containing C declarations, macro definitions to be shared between several source files, external variables and librairies that we need to execute this program.*

File : `simple_shell.h`

```c
#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define DELIMITERS " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

void new_shell_prompt(char **env);
void exe_cmd(char **args, char **env);
char *find_path_in_env(char **env);
char *find_cmd_in_path(char *cmd, char **env);
void print_env(char **env);
char **token_cmd(char *line);
void free_args(char **args);
void handle_cmd_prompt(char **args, char **env);
void handle_man_cmd(char **args);
void handle_builtin_cmd(char **args);
void handle_exit(void);
int count_tokens(char *line_cmd);

#endif
```

## How it Works ▶️

1. **Initialization**:
   - *The* `main` *function initializes the shell environment and invokes* `new_shell_prompt`.*

2. **Prompt and Input**:
   - *The shell displays a prompt (*`Nico & Tom's Shell$`*) and waits for the user to enter a command.*

3. **Command Parsing**:
   - *The entered command is read as a string.*
   - `token_cmd` *splits the command string into an array of tokens (command and arguments).*

4. **Command Execution**:
   - *Built-in commands like* `exit` *and* `env` *are handled directly within the shell.*
   - *For other commands,* `exe_cmd` *is called, which:*
     - *Searches for the command using* `find_cmd_in_path`.
     - *Forks a child process to execute the command with* `execve`.

5. **Error Handling**:
   - *If an invalid command is entered, the shell returns an error message.*
   - *Memory allocated for command arguments and paths is freed after use.*

6. **Loop**:
   - *The shell continuously loops back to display the prompt after each command execution, until* `exit` *is invoked.*

## Usage 💡

After compiling, we can run our shellwith :

```c
./hsh
```
For example, here's what it looks like :

```c
root@e6dde706a7d3:/workspace/Holberton/holbertonschool-simple_shell# ./hsh
Nico & Tom's Shell$ 
```

## Examples 🧾

### Here are the commands we tested and found to work in **interactive mode** :

1. **List directory contents:**
```bash
Nico & Tom's Shell$ ls -l
```
The result :
```bash
total 72
-rwxr-xr-x 1 root root   169 Aug 20 19:38 AUTHORS
-rw-r--r-- 1 root root  3300 Aug 20 10:09 README.md
-rw-r--r-- 1 root root  1386 Aug 20 16:55 exe_cmd.c
-rw-r--r-- 1 root root  1899 Aug 20 10:09 find_cmd_in_path.c
-rw-r--r-- 1 root root   561 Aug 20 21:27 free_args.c
-rw-r--r-- 1 root root   368 Aug 16 12:36 handle_exit.c
-rw-r--r-- 1 root root  1611 Aug 20 19:38 handle_man_cmd.c
-rwxr-xr-x 1 root root 17848 Aug 20 21:27 hsh
-rw-r--r-- 1 root root   763 Aug 16 12:36 main.c
-rwxr-xr-x 1 root root  2512 Aug 20 19:38 man_1_simple_shell
-rw-r--r-- 1 root root  1726 Aug 20 19:38 new_shell_prompt.c
-rw-r--r-- 1 root root   450 Aug 16 12:36 print_env.c
-rw-r--r-- 1 root root   967 Aug 20 19:38 simple_shell.h
-rw-r--r-- 1 root root  1703 Aug 20 11:06 token_cmd.c
Nico & Tom's Shell$ 
```
2. **List of files in the current directory**

```bash
Nico & Tom's Shell$ ls
```
The result :

```bash
AUTHORS    exe_cmd.c	       free_args.c    handle_man_cmd.c	main.c		    new_shell_prompt.c	simple_shell.h	token_cmd.c
README.md  find_cmd_in_path.c  handle_exit.c  hsh		man_1_simple_shell  print_env.c		
```
3. **Print Working directory**
```bash
Nico & Tom's Shell$ pwd
```
The result :

```bash
/workspace/Holberton/holbertonschool-simple_shell
```
4. **List of files in the current directory with a path**
```bash
Nico & Tom's Shell$ /bin/ls
```
The result :
```bash
AUTHORS    exe_cmd.c	       free_args.c    handle_man_cmd.c	main.c		    new_shell_prompt.c	simple_shell.h	token_cmd.c
README.md  find_cmd_in_path.c  handle_exit.c  hsh		man_1_simple_shell  print_env.c		
```
5. **Print environment variables:**
```bash
Nico & Tom's Shell$ env
```
The result :
```bash
HOSTNAME=e6dde706a7d3
PWD=/workspace/Holberton/holbertonschool-simple_shell
HOME=/root
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=00:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.avif=01;35:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:*~=00;90:*#=00;90:*.bak=00;90:*.crdownload=00;90:*.dpkg-dist=00;90:*.dpkg-new=00;90:*.dpkg-old=00;90:*.dpkg-tmp=00;90:*.old=00;90:*.orig=00;90:*.part=00;90:*.rej=00;90:*.rpmnew=00;90:*.rpmorig=00;90:*.rpmsave=00;90:*.swp=00;90:*.tmp=00;90:*.ucf-dist=00;90:*.ucf-new=00;90:*.ucf-old=00;90:
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm
LESSOPEN=| /usr/bin/lesspipe %s
SHLVL=1
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
OLDPWD=/
_=./hsh
Nico & Tom's Shell$
```
6. **Exit the shell:**
```bash
Nico & Tom's Shell$ exit
```
The result :
```bash
root@e6dde706a7d3:/workspace/Holberton/holbertonschool-simple_shell# 
```
### Here are the commands we tested and found to work in **non interactive mode** :

```bash
root@e6dde706a7d3:/workspace/Holberton/holbertonschool-simple_shell# echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
root@e6dde706a7d3:/workspace/Holberton/holbertonschool-simple_shell# echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
root@e6dde706a7d3:/workspace/Holberton/holbertonschool-simple_shell#
```
```bash
root@e6dde706a7d3:/workspace/Holberton/holbertonschool-simple_shell# echo "/bin/ls" | ./hsh
AUTHORS    exe_cmd.c	       free_args.c    handle_man_cmd.c	main.c		    new_shell_prompt.c	simple_shell.h
README.md  find_cmd_in_path.c  handle_exit.c  hsh		man_1_simple_shell  print_env.c		token_cmd.c
```
```bash
root@e6dde706a7d3:/workspace/Holberton/holbertonschool-simple_shell# cat test_ls_2 | ./hsh
AUTHORS    exe_cmd.c	       free_args.c    handle_man_cmd.c	main.c		    new_shell_prompt.c	simple_shell.h	token_cmd.c
README.md  find_cmd_in_path.c  handle_exit.c  hsh		man_1_simple_shell  print_env.c		test_ls_2
AUTHORS    exe_cmd.c	       free_args.c    handle_man_cmd.c	main.c		    new_shell_prompt.c	simple_shell.h	token_cmd.c
README.md  find_cmd_in_path.c  handle_exit.c  hsh		man_1_simple_shell  print_env.c		test_ls_2
root@e6dde706a7d3:/workspace/Holberton/holbertonschool-simple_shell# echo "/bin/ls" | ./hsh
AUTHORS    exe_cmd.c	       free_args.c    handle_man_cmd.c	main.c		    new_shell_prompt.c	simple_shell.h	token_cmd.c
README.md  find_cmd_in_path.c  handle_exit.c  hsh		man_1_simple_shell  print_env.c		test_ls_2
root@e6dde706a7d3:/workspace/Holberton/holbertonschool-simple_shell# cat test_ls_2 
/bin/ls
/bin/ls
root@e6dde706a7d3:/workspace/Holberton/holbertonschool-simple_shell# cat test_ls_2 | ./hsh
AUTHORS    exe_cmd.c	       free_args.c    handle_man_cmd.c	main.c		    new_shell_prompt.c	simple_shell.h	token_cmd.c
README.md  find_cmd_in_path.c  handle_exit.c  hsh		man_1_simple_shell  print_env.c		test_ls_2
AUTHORS    exe_cmd.c	       free_args.c    handle_man_cmd.c	main.c		    new_shell_prompt.c	simple_shell.h	token_cmd.c
README.md  find_cmd_in_path.c  handle_exit.c  hsh		man_1_simple_shell  print_env.c		test_ls_2
root@e6dde706a7d3:/workspace/Holberton/holbertonschool-simple_shell#
```

## Man page 📑

The man page is written in the `man_1_simple_shell` file with a special layout. To display it, simply write `man hsh` in our new terminal or falling that use `man ./man_1_simple_shell`.

## Memory leaks

In order to identify memory leaks in our program, we used the valgrind tool as follows:

```bash
Nico & Tom's Shell$ valgrind --leak-check=full ./hsh
```

## Authors 👨🏻‍💻👨🏻‍💻

> [!NOTE]
> C#24 : [Nicolas MARTINEZ](https://github.com/Bomays) & [Thomas MAYE](https://github.com/thomas-maye)
