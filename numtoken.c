#include "header.h"

int numToken(char *buffer, char *delims)
{
	int numTokes, i, j;

	delims = " \n";
	numTokes = 0;
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
