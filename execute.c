#include "header.h"

/**
 * execute_command - executing the command passed in as token[0]
 * @token_array: Pointer to array of pointers of tokens
 * @argv: Argument array of values passed in
 * @path_array: Array of pointers to path strings
 * Return: 0 For success
 */

int execute_command(memstruct *mlcs)
{
	pid_t pid;
	int status;


	mlcs->tokenArray[0] = search_tokens(mlcs);
	if (!mlcs->tokenArray[0])
		custom_exit(mlcs);
	pid = fork();
	if (pid == 0)
	{
		if ((execve(mlcs->tokenArray[0], mlcs->tokenArray, NULL)) == -1)
		{
			custom_exit(mlcs);
		}

	}
	else
	{
		wait(&status);
	}

	return (0);
}
