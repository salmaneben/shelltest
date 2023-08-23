#include "shell.h"

/**
 * check_builtin - Checks if the command is a built-in and executes it.
 * @args: Null-terminated array of arguments. args[0] is the command.
 *
 * Description: This function checks if the command is a built-in and, if so,
 * executes the built-in command.
 *
 * Return: 1 if the command is a built-in and was executed, 0 otherwise.
 */
int check_builtin(char **args)
{
	if (args[0] == NULL)
		return (0);
	if (_strcmp(args[0], "exit") == 0)
	{
		shell_exit();
		return (1);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		shell_env();
		return (1);
	}
	return (0);
}
/**
 * shell_exit - Exits the shell.
 * @void: No parameters.
 *
 * Description: This function exits the shell.
 */
void shell_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * shell_env - Prints the current environment.
 * @void: No parameters.
 *
 * Description: This function prints the current environment variables.
 */
void shell_env(void)
{
	int i = 0;

	while (environ[i])
	{
	printf("%s\n", environ[i]);
		i++;
	}
}
