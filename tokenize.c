#include "header.h"

/**
 * tokenize - returns an array of null terminated tokens
 *
 * @mlcs: Pointer to struct containing all variables
 *
 * Description: calls strtok to get token and stores it in a generic array of
 * tokens->
 *
 * Return: The array of tokens
*/
char **tokenize(memstruct *mlcs)
{
	int i;
	char *token;


	/** allocate blocks for tokens and NULL pointer **/
	mlcs->tmparr = malloc(sizeof(char *) * (mlcs->nTokens + 1));

	if (!mlcs->tmparr)
		return (NULL);

	token = strtok(mlcs->buffer, mlcs->delims);

	if (!_strcmp("exit", token) && mlcs->nTokens == 1)
	{
		if (mlcs->path_array)
			free(mlcs->path_array);
		if (mlcs->tokenArray)
			free(mlcs->tokenArray);
		if (mlcs->buffer)
			free(mlcs->buffer);
		if (mlcs->direc_copy)
			free(mlcs->direc_copy);
		if (mlcs->path_copy)
			free(mlcs->path_copy);
		if (mlcs->tmparr)
			free(mlcs->tmparr);
		free(mlcs);
		exit(EXIT_FAILURE);
	}

	if (!_strcmp("env", token) && mlcs->nTokens == 1)
		printenv(mlcs);

	for (i = 0; token != NULL; i++)
	{
		mlcs->tmparr[i] = token;
		token = strtok(NULL, mlcs->delims);
	}
	mlcs->tmparr[i] = NULL;

	return (mlcs->tmparr);

}
