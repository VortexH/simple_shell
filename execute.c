#include "header.h"

/**
 * execute_command - executing the command passed in as token[0]
 * @tokens: Pointer to array of pointers of tokens
 * Return: 0 For success
 */

int execute_command(char **tokens)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if ((execve(tokens[0], tokens, NULL)) == -1)
			return (-1);

	}
	else if (pid > 0)
	{
		wait(&status);
	}

	return (0);
}
