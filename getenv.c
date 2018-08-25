#include "header.h"

char *_getenv(char **env)
{
	int i, j;
	char *name = "PATH";

	for (i = 0; env[i]; i++)
	{
		for (j = 0; env[i][j] == name[j]; j++)
			if (env[i][j + 1] == '=' && name[j + 1] == 0)
				return (env[i] + j + 2);

	}
	return (NULL);

}