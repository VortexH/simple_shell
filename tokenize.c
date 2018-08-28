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
char **tokenize(char **env, memstruct mlcs)
{
	int i;
	char *token;

	/** allocate blocks for tokens and NULL pointer **/
	mlcs.tokenArray = malloc(sizeof(char *) * (mlcs.nTokens + 1));
	if (!mlcs.tokenArray)
		return (NULL);

	i = 0;
	token = strtok(mlcs.buffer, mlcs.delims);

	if (!_strcmp("exit", mlcs.tokenArray[0]))
		exit(EXIT_FAILURE);
	if (!_strcmp("env", mlcs.tokenArray[0]))
		printenv(env);

	while (token != NULL)
	{
		mlcs.tokenArray[i] = token;
		token = strtok(NULL, mlcs.delims);
		i++;
	}
	mlcs.tokenArray[i] = NULL;

	return (mlcs.tokenArray);

}
