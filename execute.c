#include "shell.h"

/**
 * execute_command - Executes a command with its arguments.
 * @args: Null-terminated array of arguments. args[0] is the command.
 *
 * Description: This function forks a new process and executes the given command
 * in the child process using execvp. The parent process waits for the child to finish.
 *
 * Return: 1 if the shell should continue running, 0 if it should terminate.
 */
int execute_command(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        /* Child process*/
        if (execvp(args[0], args) == -1)
        {
            perror("shell");
        }
        exit(EXIT_FAILURE);  /* If exec fails*/
    }
    else if (pid < 0)
    {
        /* Forking error*/
        perror("shell");
    }
    else
    {
        /* Parent process*/
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;  /* Continue execution of shell*/
}

