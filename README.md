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

- **token.cmd.c :**

*This function divides the command entered by the user into words called tokens*

Prototype : `char **token_cmd(char *line);`

- **exe_cmd.c :**

*This function executes the command entered by the user*

Prototype : `void exe_cmd(char **args, char **env);`

- **find_cmd_in_path.c :**

*This function searches for the command entered in the path and if the command is executable*

Prototype : `char *find_cmd_in_path(char *command);`

- **print_env.c :**

*This function displays environment variables*

Prototype : `void print_env(char **env);`

- **handle_exit.c :**

*This function manages the program output*

Prototype : `void handle_exit(void);`

- **free_args.c :**

*This function frees the memory allocated to the arguments*

Prototype : `void free_args(char **args);`

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

`./hsh`

## Examples 🧾

List directory contents:
```bash
Nico & Tom's Shell$ ls -l
```

Print environment variables:
```bash
Nico & Tom's Shell$ env
```

Exit the shell:
```bash
Nico & Tom's Shell$ exit
```

## Man page 📑

The man page is written in the `man_1_simple_shell` file with a special layout. To display it, simply write `man hsh` in our new terminal.



## Memory leaks

In order to identify memory leaks in our program, we used the valgrind tool as follows:

```bash
Nico & Tom's Shell$ valgrind --leak-check=full ./hsh
```

## Authors 👨🏻‍💻👨🏻‍💻

> [!NOTE]
> C#24 : [Nicolas MARTINEZ](https://github.com/Bomays) & [Thomas MAYE](https://github.com/thomas-maye)
