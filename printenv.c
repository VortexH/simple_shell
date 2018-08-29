#include "header.h"

/**
 * printenv - prints all the strings in environment to std out
 *
 * @mlcs: Pointer to struct containing all variables
 *
 * Return: void
*/

void printenv(memstruct *mlcs)
{
	int i;

	for (i = 0; mlcs->env[i]; i++)
	{
		write(1, mlcs->env[i], _strlen(mlcs->env[i]));
		write(1, "\n", 1);
	}
}
