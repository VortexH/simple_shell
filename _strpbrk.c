#include "header.h"

/**
 * _strpbrk - Search a string's characters in accept and return a pointer to it
 * @s: characters that will be searched for occurrences in accept
 * @accept: contains the characters we want found from s
 *
 * Return: Pointer to instance that matches accept
*/

char *_strpbrk(char *s, char *accept)
{
	int i, j, k, l;

	i = _strlen(s);
	k = _strlen(accept);

	for (j = 0; j < i; j++)
	{
		for (l = 0; l < k; l++)
		{
			if (s[j] == accept[l])
				return (s + j);
		}
	}

	return (NULL);
}
