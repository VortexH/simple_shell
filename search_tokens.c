#include "header.h"

/**
 * search_tokens - searching the path_array
 * @path_array: Array of strings found in path from env
 * @token: First token from input
 * Description: Searching our path array for the token, effectively searching
 * the path for a directory containing the command that was input
 * Return: The token, either concatenated with the command or directly the path
 */

char *search_tokens(char **path_array, char *token)
{
	int i = 0;
	char *tmp;
	char *pathSlashed;
	char *copy;

	if (token[0] == '/')
		return (token);
	while (path_array[i])
	{
		copy = strdup(path_array[i]);
		pathSlashed = strcat(copy, "/");
		tmp = strcat(pathSlashed, token);

		if (!access(tmp, F_OK))
		{
			if (!access(tmp, R_OK | X_OK))
				return (tmp);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	return (token);
}
