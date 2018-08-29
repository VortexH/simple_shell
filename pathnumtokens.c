#include "header.h"

/**
 * numToken - gets the number of tokens in the string passed in
 * @b: Stored values of strings passed in
 * @d: String of delimiting characters being searched for
 * Description: Getting the number of delimiters to malloc an array of pointers
 * that each point to a single token of the passed in string.
 * Return: Number of tokens.
 */

int pathNumToken(memstruct *mlcs)
{
	int len, n;
	char *tmp;

	n = 0;
	tmp = mlcs->path_copy;
	while (tmp)
	{
		len = _strspn(tmp, mlcs->pathDelims);
		tmp += len;
		tmp = _strpbrk(tmp, mlcs->pathDelims);
		if (tmp)
			n++;
		else
		  n++;
	}


	return (n);


}
