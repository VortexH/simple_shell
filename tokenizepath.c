#include "header.h"

/**
 * tokenize - returns an array of null terminated tokens
 *
 * @buffer: contains the input from stdin
 * @nTokens: contains the number of tokens found in the buffer
 * @delims: a string of delimiters separating tokens
 * @env: environment variable
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
		printf("tokenizepath:path token: %s\n", token);
		tmp[i] = token;
		token = strtok(NULL, mlcs->pathDelims);
	}
	tmp[i] = NULL;

	return (tmp);

}
