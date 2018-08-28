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

char **get_path_array(char **env, memstruct mlcs)
{
	char *path;
	char **path_array;

	path = _getenv(env);
	mlcs.path_copy = strdup(path);
	mlcs.nTokens = numToken(mlcs);
	path_array = tokenize(env, mlcs);


	return (path_array);
}
