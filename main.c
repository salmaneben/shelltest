#include "shell.h"

/**
 * main - Entry point of the shell program.
 * @void: No parameters.
 *
 * Description: This function initializes the shell and enters the main loop
 * where it waits for user input, parses it, and executes the corresponding
 * commands.
 *
 * Return: 0 on normal execution, error code on failure.
 */
int main(void)
	{
	char *input;
	char **args;
	int status = 1;

    /* Main loop of the shell */
	while (status)
	{
	/* Print the prompt */
		write(STDOUT_FILENO, "$ ", 2);
		/* Read the input from the user */
		input = read_input();
		if (!input)
			continue;
		/* Parse the input into command and arguments */
		args = parse_input(input);
		if (!args)
		{
			free(input);
			continue;
		}
/* Check if the command is a built-in, if not execute it */
		if (!check_builtin(args))
			status = execute_command(args);
		/* Free allocated memory */
		free(input);
		free(args);
	}
	return (0);
}
