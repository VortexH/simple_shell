#include "header.h"

/**
 * numToken - gets the number of tokens in the string passed in
 * @b: Stored values of strings passed in
 * @d: String of delimiting characters being searched for
 * Description: Getting the number of delimiters to malloc an array of pointers
 * that each point to a single token of the passed in string.
 * Return: Number of tokens.
 */

int numToken(char *b, char *d)
{
	int len, n;

	n = 0;
	while (b)
	{
		len = _strspn(b, d);
		b += len;
		b = _strpbrk(b, d);
		if (b)
			n++;
	}

	return (n);


}
