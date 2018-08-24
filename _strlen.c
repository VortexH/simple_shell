#include "header.h"

/**
 * _strlen - Returns the length of a string
 * @s: pointer to a string
 * Description: See above
 * Return: 0/1 Fail/Pass
*/
int _strlen(char *s)
{
	int num_cars = 0;

	while (*s > 0)
	{
		num_cars++;
		s++;
	}

	return (num_cars);
}
