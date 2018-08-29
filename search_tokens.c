#include "header.h"

/**
 * search_tokens - searching the path_array
 * @mlcs: Pointer to struct containing all variables
 * Description: Searching our path array for the token, effectively searching
 * the path for a directory containing the command that was input
 * Return: The token, either concatenated with the command or directly the path
 */

char *search_tokens(memstruct *mlcs)
{
	int dirlen, tokenLen, i, j, k;


	if (mlcs->tokenArray[0][0] == '/')
		return (mlcs->tokenArray[0]);
	for (i = 0; mlcs->path_array[i]; i++)
	{
		tokenLen = _strlen(mlcs->tokenArray[0]);
		dirlen = _strlen(mlcs->path_array[i]);

/** put bytes into tmp array --------------------------------------**/
		mlcs->direc_copy = malloc(sizeof(char) * (tokenLen + dirlen + 2));
		printf("Mallocing %d bytes\n", tokenLen + dirlen + 1);
		if (!mlcs->direc_copy)
			return (NULL);
		for (j = 0; mlcs->path_array[i][j]; j++)
		{
			mlcs->direc_copy[j] = (mlcs->path_array[i])[j];
		}
		mlcs->direc_copy[j] = '/';
		for (k = 0, j += 1; mlcs->tokenArray[0][k]; j++, k++)
			mlcs->direc_copy[j] = mlcs->tokenArray[0][k];
		mlcs->direc_copy[j] = '\0';
/**--------------------------------------------------------------------**/
		if (!access(mlcs->direc_copy, F_OK))
		{
			if (!access(mlcs->direc_copy, R_OK | X_OK))
				return (mlcs->direc_copy);
			custom_exit(mlcs);
		}
		free(mlcs->direc_copy);
		mlcs->direc_copy = NULL;
	}

	return (mlcs->tokenArray[0]);
}
