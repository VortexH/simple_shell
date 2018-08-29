#include "header.h"

/**
 * tokenizepath - returns an array of null terminated tokens
 *
 * @mlcs: Pointer to struct containing all variables
 *
 * Description: calls strtok to get token and stores it in a generic array of
 * tokens->
 *
 * Return: The array of tokens
*/
char **tokenizepath(memstruct *mlcs)
{
	int i;
	char *token;
	char **tmp;

	/** allocate blocks for tokens and NULL pointer **/
	tmp = malloc(sizeof(char *) * (mlcs->nTokens + 1));
	if (!tmp)
		return (NULL);

	token = strtok(mlcs->path_copy, mlcs->pathDelims);
	for (i = 0; token != NULL; i++)
	{
		tmp[i] = token;
		token = strtok(NULL, mlcs->pathDelims);
	}
	tmp[i] = NULL;

	return (tmp);

}
