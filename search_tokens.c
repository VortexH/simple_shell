#include "header.h"

char *search_tokens(char **path_array, char *token)
{
	int string_result, i = 0;
	DIR *directory;
	struct dirent *dirent;
	char *temp_token;

	if (token[0] == '/')
		return (token);
	else
	{
		while (path_array[i])
		{
			directory = opendir(path_array[i]);
			dirent = readdir(directory);
			while (dirent)
			{
				string_result = strcmp(dirent->d_name, token);
				if (!string_result)
				{
					temp_token = strcat(path_array[i], "/");
					token = _strcat(temp_token, token);
					return(token);
				}
				dirent = readdir(directory);
			}
			i++;
		}
	}
	return (NULL);
}
