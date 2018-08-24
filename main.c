#include "header.h"

/**
 * main - Main function calling all other functions
 * @argc: Number of arguments passed in after program
 * @argv: Value of arguments passed in after program
 * @env: Environment variable
 * Description: Refer to README for full description
 * Return: 0 for success, -1 for failure
 */

int main(int argc, char **argv, char **env)
{
	char *buffer, *delims;
	char **token_array;
	size_t n;
	ssize_t getReturn;
	int nTokens, check;

	(void)env;
	(void)argc;

	buffer = NULL;
	check = 1;
	delims = " \t\n";
	n = 0;
	while (check)
	{
		write(1, ">>>> ", 5);

		getReturn = getline(&buffer, &n, stdin);
		printf("Num Chars Read: %lu\n", (unsigned long) getReturn);
		if (getReturn == -1)
			return (-1);

		nTokens = numToken(buffer, delims);
		if (nTokens)
		{
			token_array = tokenize(buffer, nTokens, delims);
			if (!token_array)
				return (-1);
			execute_command(token_array, argv);
		}

	}
	return (0);
}
