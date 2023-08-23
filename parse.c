#include "shell.h"

/**
 * parse_input - Parses the input string into a command and its arguments.
 * @input: The input string.
 *
 * Description: This function tokenizes the input string based on spaces to
 * separate the command and its arguments. It returns an array of strings where
 * the first element is the command, and the subsequent elements are the arguments.
 *
 * Return: A NULL-terminated array of strings, or NULL on failure.
 */
char **parse_input(char *input)
{
    int bufsize = 64;  /* Initial buffer size for the array of strings */
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "parse_input: allocation error\n");
        exit(EXIT_FAILURE);
    }

    /* Tokenize the input string */
    token = strtok(input, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        /* If we've exceeded the buffer, reallocate */
        if (position >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "parse_input: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}

