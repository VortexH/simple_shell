#include "header.h"

/**
 * numToken - gets the number of tokens in the string passed in
 * @buffer: Stored values of strings passed in
 * @delims: String of delimiting characters being searched for
 * Description: Getting the number of delimiters to malloc an array of pointers
 * that each point to a single token of the passed in string.
 * Return: Number of tokens.
 */

int numToken(char *buffer, char *delims)
{
	int i, j, n;
	char *b, *d;

	b = buffer;
	d = delims;
	n = 0;
	for (i = 0; b[i]; i++)
	{
		for (j = 0; d[j]; j++)
		{
			if (b[i] != d[j] && b[i++] == d[j])
				n++;
		}
	}

	printf("Number of tokens: %d\n", n);
	return (n);
}
