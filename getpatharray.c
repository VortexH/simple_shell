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

	path = _getenv(env);
	path  = strcat(path, "\n");
	nTokens = numToken(path, ":\n");
	path_array = tokenize(path, nTokens, ":");

	return (path_array);
}

