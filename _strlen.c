#include "header.h"

/**
 * _strlen - Returns the length of a string
 * @s: pointer to a string
 * Description: See above
 * Return: 0/1 Fail/Pass
*/
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;

	return (i);
}
