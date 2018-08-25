#include "header.h"

char *search_tokens(char **path_array, char *token)
{
	int string_result, i = 0;
	DIR *directory;
	struct dirent *dirent;
	char *tmp_token;

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
				string_result = _strcmp(dirent->d_name, token);
				if (!string_result)
				{
					tmp_token = _strcat(path_array[i], "/");
					token = _strcat(tmp_token, token);
					return(token);
				}
				dirent = readdir(directory);
			}
			i++;
		}
	}
	printf("%s", token);
	return (token);
}
