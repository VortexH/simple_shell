#include "header.h"

/**
 * printenv - prints all the strings in environment to std out
 *
 * @env: environment
 *
 * Return: void
*/

void printenv(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		write (1, env[i], _strlen(env[i]));
		write (1, "\n", 1);
	}
}
	
	
