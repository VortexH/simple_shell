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
char **tokenize(char *buffer, int nTokens, char *delims, char **env)
{
	char **tokenArray;
	char *token;
	int i;

	/** allocate blocks for tokens and NULL pointer **/
	tokenArray = malloc(sizeof(char *) * (nTokens + 1));
	if (!tokenArray)
		return (NULL);

	i = 0;
	token = strtok(buffer, delims);

	if (!_strcmp("exit", token))
		exit(EXIT_FAILURE);
	if (!_strcmp("env", token))
		printenv(env);

	while (token != NULL)
	{
		tokenArray[i] = token;
		token = strtok(NULL, delims);
		i++;
	}
	tokenArray[i] = NULL;

	return (tokenArray);

}
