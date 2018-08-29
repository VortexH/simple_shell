#include "header.h"

/**
 * _getenv - our own get environment function
 * @env: Environment variable containing all env strings
 * Description: Gets specifically the path string from env
 * Return: The path string
 */

char *_getenv(memstruct mlcs)
{
	int i, j;
	char *name = "PATH";
	char *t;

	for (i = 0; mlcs.env[i]; i++)
	{
		for (j = 0; mlcs.env[i][j] == name[j]; j++)
			if (mlcs.env[i][j + 1] == '=' && name[j + 1] == 0)
			{
				t = mlcs.env[i] + j + 2;
				return (t);
			}

	}

	return (NULL);

}
