#include "header.h"

/**
 * get_path_array - returns an array of directories from path
 *
 * @env: environment from parent process
 *
 * Description: gets the path, obtains tokens, and returns the entire path
 * as an array of directories.
 *
 * Return: Array of Paths
*/

char **get_path_array(memstruct mlcs)
{
	char *path = NULL;
	char **path_array = NULL;

	path = _getenv(mlcs);
	mlcs.path_copy = _strdup(path, 0);
	if (!mlcs.path_copy)
		return (NULL);
	mlcs.nTokens = pathNumToken(mlcs);
	path_array = tokenizepath(mlcs);
	free (mlcs.path_copy);

	return (path_array);
}
