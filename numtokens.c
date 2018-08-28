#include "header.h"

/**
 * numToken - gets the number of tokens in the string passed in
 * @b: Stored values of strings passed in
 * @d: String of delimiting characters being searched for
 * Description: Getting the number of delimiters to malloc an array of pointers
 * that each point to a single token of the passed in string.
 * Return: Number of tokens.
 */

int numToken(memstruct mlcs)
{
	int len, n;

	n = 0;
	while (mlcs.buffer)
	{
		len = _strspn(mlcs.buffer, mlcs.delims);
		mlcs.buffer += len;
		mlcs.buffer = _strpbrk(mlcs.buffer, mlcs.delims);
		if (mlcs.buffer)
			n++;
	}

	return (n);


}
