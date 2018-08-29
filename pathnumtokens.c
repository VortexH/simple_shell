#include "header.h"

/**
 * numToken - gets the number of tokens in the string passed in
 * @b: Stored values of strings passed in
 * @d: String of delimiting characters being searched for
 * Description: Getting the number of delimiters to malloc an array of pointers
 * that each point to a single token of the passed in string.
 * Return: Number of tokens.
 */

int pathNumToken(memstruct mlcs)
{
	int len, n;

	n = 0;
	while (mlcs.path_copy)
	{
		len = _strspn(mlcs.path_copy, mlcs.pathDelims);
		mlcs.path_copy += len;
		mlcs.path_copy = _strpbrk(mlcs.path_copy, mlcs.pathDelims);
		if (mlcs.path_copy)
			n++;
		else
		  n++;
	}


	return (n);


}
