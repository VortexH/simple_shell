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
	int numTokes, i, j;

	numTokes = 0;
	if (*buffer == '\n')
		return (1);
	for (i = 0; buffer[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (buffer[i] == delims[j])
			{
				numTokes++;
				break;
			}
		}
	}

	return (numTokes);
}
