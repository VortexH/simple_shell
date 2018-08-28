#include "header.h"

/**
 * search_tokens - searching the path_array
 * @path_array: Array of strings found in path from env
 * @token: First token from input
 * Description: Searching our path array for the token, effectively searching
 * the path for a directory containing the command that was input
 * Return: The token, either concatenated with the command or directly the path
 */

char *search_tokens(memstruct mlcs)
{
	int i = 0;
	char *tmp;
	char *pathSlashed;
	char *direc_copy;

	if (mlcs.tokenArray[0][0] == '/')
		return (mlcs.tokenArray[0]);
	while (mlcs.path_array[i])
	{
		direc_copy = strdup(mlcs.path_array[i]);
		pathSlashed = strcat(direc_copy, "/");
		tmp = strcat(pathSlashed, mlcs.tokenArray[0]);

		if (!access(tmp, F_OK))
		{
			if (!access(tmp, R_OK | X_OK))
				return (tmp);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	return (mlcs.tokenArray[0]);
}
