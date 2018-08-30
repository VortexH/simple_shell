#include "header.h"

/**
 *_strcmp - compare ascii value of two array element values
 *@s1: first string to compare
 *@s2: second string to compare
 *Return: value of ascii difference in string value
 */

int _strcmp(char *s1, char *s2)
{
	int a, total;

	for (a = 0; s1[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
		{
			total = s1[a] - s2[a];
			break;
		}
		else
			total = s1[a] - s2[a];
	}
	if (s1[a] != s2[a])
		return (1);
	return (total);
}
