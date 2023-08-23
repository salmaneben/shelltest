#ifndef SHELL_H
#define SHELL_H
#define CMD_NOT_FOUND 1
#define ILLEGAL_NUMBER 2
#define PERMISSION_DENIED 3


/* Include necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

/* Struct Definitions (if any) */

/* Function Prototypes */

/* main.c */
int main(void);

/* input.c */
char *read_input(void);

/* parse.c */
char **parse_input(char *input);

/* execute.c */
int execute_command(char **args);

/* builtins.c */
int check_builtin(char **args);
void shell_exit(void);
void shell_env(void);

/* path.c */
char *find_in_path(char *command);

/* error.c */
void print_error(char *message);

/* helpers.c */
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *s);

/* Add other prototypes as needed */

#endif /* SHELL_H */

