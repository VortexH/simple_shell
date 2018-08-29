#include "header.h"

/**
 * _strdup - allocating memory for a string and copying that string
 * @str: Given string passed in
 * Return: Pointer to new array
 */

char *_strdup(char *str, int n)
{
	int size;
	int st;
	char *ar;

	if (str == NULL)
		return ('\0');
	size = 0;
	while (str[size] != '\0')
		size++;
	ar = malloc((size + 2 + n) * (sizeof(char)));
	if (!ar)
		return (NULL);
	if (ar != NULL)
	{
		st = 0;
		while (str[st] != '\0')
		{
			ar[st] = str[st];
			st++;
		}
		ar[st] = '/';
	}
	ar[size + 1 + n] = '\0';
	return (ar);

}
