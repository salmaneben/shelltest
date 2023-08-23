#include "shell.h"

/**
 * find_in_path - Searches for a command in the PATH.
 * @command: The command to search for.
 *
 * Description: This function searches for the given command in the directories
 * specified by the PATH environment variable.
 *
 * Return: Full path to the command if found, NULL otherwise.
 */
char *find_in_path(char *command)
{
	char *PATH = getenv("PATH");
	char *path_dup, *token;
	char *full_path = NULL;
	struct stat st;

	if (command == NULL || PATH == NULL)

		return (NULL);
	path_dup = _strdup(PATH);
/* Duplicate the PATH string for tokenization*/
token = strtok(path_dup, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
/* +2 for '/' and '\0'*/
		if (!full_path)
		{
			perror("find_in_path");
			free(path_dup);
			return (NULL);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_dup);
			return (full_path);
		}
		free(full_path);
		full_path = NULL;
		token = strtok(NULL, ":");
	}
	free(path_dup);
	return (NULL);
}

