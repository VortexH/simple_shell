#include "header.h"

/**
 * execute_command - executing the command passed in as token[0]
 * @tokens: Pointer to array of pointers of tokens
 * Return: 0 For success
 */

int execute_command(char **token_array, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if ((execve(token_array[0], token_array, NULL)) == -1)
		{
			write(1, argv[0], strlen(argv[0]));
			perror(" ");
			exit(EXIT_FAILURE);
		}

	}
	else
	{
		wait(&status);
	}

	return (0);
}
