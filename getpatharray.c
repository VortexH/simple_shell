#include "header.h"

/**
 * get_path_array - returns an array of directories from path
 *
 * @mlcs: Pointer to struct containing all variables
 *
 * Description: gets the path, obtains tokens, and returns the entire path
 * as an array of directories.
 *
 * Return: Array of Paths
*/

void get_path_array(memstruct *mlcs)
{
	char *path = NULL;

	path = _getenv(mlcs);
	mlcs->path_copy = strdup(path);
	mlcs->nTokens = pathNumToken(mlcs);
	mlcs->path_array = tokenizepath(mlcs);

}
