#include "header.h"

/**
 * _strspn - Get the length of a specified substring
 *@s: String containing bytes that need to be compared to bytes in accept
 *@accept: String that contains bytes that should be in string s
 *Description: Get the number of leading bytes containing characters in accept
 *Return: Number of bytes as assigned int
*/

unsigned int _strspn(char *s, char *accept)
{
	int i;
	int j;
	int a;
	unsigned int n_bytes;

	n_bytes = 0;
	a = 0;

	for (i = 0; s[i] != '\0' && a == 0; i++)
	{

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				n_bytes++;
				break;
			}
			if (s[i] != accept[j] && accept[j + 1] == '\0')
				a = 1;
		}

	}
	return (n_bytes);
}
