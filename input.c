#include "shell.h"

/**
 * read_input - Reads a line of input from the user.
 * @void: No parameters.
 *
 * Description: This function reads a line of input from the standard input
 * using getline. The newline character at the end is replaced with a null
 * terminator.
 *
 * Return: A pointer to the input string, or NULL on failure or EOF.
 */
char *read_input(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;

	/* Read a line of input */
read = getline(&line, &len, stdin);

	/* Check for EOF or error */
if (read == -1)
{
	free(line);
	if (feof(stdin))  /* End of File */
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	else  /* Some error occurred */
	{
		perror("read_input");
		exit(EXIT_FAILURE);
	}
}
	/* Replace newline with null terminator */
if (read > 0 && line[read - 1] == '\n')
line[read - 1] = '\0';
	return (line);
}
