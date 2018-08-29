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
char **tokenizepath(memstruct mlcs)
{
	int i;
	char *token;

	/** allocate blocks for tokens and NULL pointer **/
	mlcs.path_array = malloc(sizeof(char *) * (mlcs.nTokens + 1));
	if (!mlcs.path_array)
		return (NULL);

	token = strtok(mlcs.path_copy, ":\0");
	for (i = 0; token != NULL; i++)
	{
		mlcs.path_array[i] = token;
		token = strtok(NULL, ":\0");
	}
	mlcs.path_array[i] = NULL;

	return (mlcs.path_array);

}
