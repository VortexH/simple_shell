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
	char *copy;


	path = _getenv(env);
	copy = strdup(path);
	nTokens = numToken(copy, ":\0");
	path_array = tokenize(copy, nTokens, ":\0");


	

	return (path_array);
}
