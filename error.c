#include "shell.h"

/**
 * display_error - Displays an error message based on the error type.
 * @args: Null-terminated array of arguments. args[0] is the command.
 * @error_type: The type of error to display.
 *
 * Description: This function displays an error message based on the type of
 * error encountered.
 */
void display_error(char **args, int error_type)
{
	switch (error_type)
	{
		case CMD_NOT_FOUND:
			fprintf(stderr, "%s: command not found\n", args[0]);
			break;
		case ILLEGAL_NUMBER:
			fprintf(stderr, "%s: Illegal number\n", args[1]);
			break;
		case PERMISSION_DENIED:
			fprintf(stderr, "%s: Permission denied\n", args[0]);
			break;
		default:
			fprintf(stderr, "Unknown error\n");
			break;
	}
}
