#include "header.h"

/**
 * numToken - gets the number of tokens in the string passed in
 * @b: Stored values of strings passed in
 * @d: String of delimiting characters being searched for
 * Description: Getting the number of delimiters to malloc an array of pointers
 * that each point to a single token of the passed in string->
 * Return: Number of tokens->
 */

int numToken(memstruct *mlcs)
{
	int len, n;
	char *tmp;


	tmp = mlcs->buffer;

	n = 0;
	while (tmp)
	{
		len = _strspn(tmp, mlcs->delims);
		tmp += len;
		tmp = _strpbrk(tmp, mlcs->delims);
		if (tmp)
			n++;
	}

	return (n);


}
