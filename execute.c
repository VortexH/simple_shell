#include "header.h"

/**
 * execute_command - executing the command passed in as token[0]
 * @mlcs: Pointer to struct containing all variables
 * Return: 0 For success
 */

int execute_command(memstruct *mlcs)
{
	pid_t pid;
	int status;

	mlcs->input_token = _strdup(mlcs->tokenArray[0]);
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

	free(mlcs->input_token);
	mlcs->input_token = NULL;
	free(mlcs->direc_copy);
	mlcs->direc_copy = NULL;
	return (0);
}
