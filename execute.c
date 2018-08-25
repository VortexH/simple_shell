#include "header.h"

/**
 * execute_command - executing the command passed in as token[0]
 * @token_array: Pointer to array of pointers of tokens
 * @argv: Argument array of values passed in
 * Return: 0 For success
 */

int execute_command(char **token_array, char **argv, char **path_array)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		token_array[0] = search_tokens(path_array, token_array[0]);
		if ((execve(token_array[0], token_array, NULL)) == -1)
		{
			write(1, argv[0], _strlen(argv[0]));
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
