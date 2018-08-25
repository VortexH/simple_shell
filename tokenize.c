#include "header.h"

/**
 * tokenize - returns an array of null terminated tokens
 *
 * @buffer: contains the input from stdin
 * @nTokens: contains the number of tokens found in the buffer
 * @delims: a string of delimiters separating tokens
 *
 * Description: calls strtok to get token and stores it in a generic array of
 * tokens.
 *
 * Return: The array of tokens
*/
char **tokenize(char *buffer, int nTokens, char *delims)
{
	char **tokenArray;
	char *token;
	int i;

	tokenArray = malloc(sizeof(char *) * (nTokens + 1));
	if (!tokenArray)
		return (NULL);

	i = 0;
	token = strtok(buffer, delims);
	if (!strcmp("exit", token))
		return (NULL);
	while (token != NULL)
	{
		tokenArray[i] = token;
		token = strtok(NULL, delims);
		i++;
	}
	tokenArray[i] = NULL;

	return (tokenArray);

}
