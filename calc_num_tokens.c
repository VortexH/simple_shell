#include "header.h"

/**
 * numToken - gets the number of tokens in the string passed in
 * @buffer: Stored values of strings passed in
 * @delims: String of delimiting characters being searched for
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
/**
		printf("Number of bytes with delimiter: %d\n", len);
**/
		b += len;
/**
		printf("String after moving len many bytes: %s\n", b);
**/
		b = _strpbrk(b, d);
/**
		printf("String after strpbrk: %s\n", b);
**/
		if (b)
			n++;
/**
		printf("Number of tokens: %d\n", n);
**/
	}

	return (n);

	
}
