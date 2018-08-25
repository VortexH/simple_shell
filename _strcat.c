#include "holberton.h"

/**
 **_strcat - concatenate two strings
 *@dest: destination string
 *@src: source string
 *Return: Character value
 */

char *_strcat(char *dest, char *src)
{
	int destl, srcl;

	destl = 0;
	while (dest[destl] != '\0')
		destl++;
	for (srcl = 0; src[srcl] != '\0'; srcl++)
		dest[destl + srcl] = src[srcl];
	dest[destl + srcl] = '\0';

	return (dest);
}
