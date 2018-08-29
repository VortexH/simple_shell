#include "header.h"

/**
 * _strdup - return a pointer to a newly allocated space in memory
 * @str: string given to the function
 * Description: which contains a copy of the string given as a parameter
 * Return: Pointer to the allocated space in memory
*/

char *_strdup(char *str)
{
	int len;
	char *new_str;
	int pos;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		;
	len = len + 1;

	new_str = malloc(sizeof(char) * len);

	if (new_str != NULL)
		for (pos = 0; pos < len; pos++)
			new_str[pos] = str[pos];

	return (new_str);
}
