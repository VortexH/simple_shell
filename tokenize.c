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
 * tokens.
 *
 * Return: The array of tokens
*/
char **tokenize(memstruct mlcs)
{
	int i;
	char *token;

	/** allocate blocks for tokens and NULL pointer **/
	mlcs.tokenArray = malloc(sizeof(char *) * (mlcs.nTokens + 1));
	if (!mlcs.tokenArray)
		return (NULL);

	token = strtok(mlcs.buffer, mlcs.delims);

	if (!_strcmp("exit", token))
	{
		free(mlcs.tokenArray);
		free(mlcs.path_array);
		free(mlcs.buffer);
		exit(EXIT_FAILURE);
	}
	if (!_strcmp("env", token))
		printenv(mlcs);

	for (i = 0; token != NULL; i++)
	{
		mlcs.tokenArray[i] = token;
		token = strtok(NULL, mlcs.delims);
	}
	mlcs.tokenArray[i] = NULL;

	return (mlcs.tokenArray);

}
