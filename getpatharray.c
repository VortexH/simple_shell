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

char **get_path_array(char **env)
{
	char *path;
	int nTokens;
	char **path_array;
	char *path_copy;


	path = _getenv(env);
	path_copy = strdup(path);
	nTokens = numToken(path_copy, ":\0");
	path_array = tokenize(path_copy, nTokens, ":\0", env);



	return (path_array);
}
