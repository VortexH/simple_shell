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
	int string_result, i = 0;
	DIR *directory;
	struct dirent *dirent;
	char *tmp_token;

	if (token[0] == '/')
		return (token);
	while (path_array[i])
	{
		directory = opendir(path_array[i]);
		dirent = readdir(directory);
		while (dirent)
		{
			string_result = _strcmp(dirent->d_name, token);
			if (!string_result)
			{
				tmp_token = _strcat(path_array[i], "/");
				token = _strcat(tmp_token, token);
				return (token);
			}
			dirent = readdir(directory);
		}
		i++;
	}
	return (token);
}
