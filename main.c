#include "header.h"

/**
 * main - Main function calling all other functions
 * @argc: Number of arguments passed in after program
 * @argv: Value of arguments passed in after program
 * @env: Environment variable
 * Description: Refer to README for full description
 * Return: 0 for success, -1 for failure
 */

int main(au int argc, char **argv, char **env)
{
	char *buffer = NULL;
	char *delims = " \t\n";
	char **token_array, **path_array;
	size_t n = 0;
	ssize_t getReturn;
	int nTokens, check = 1;

	path_array = get_path_array(env);
	if (path_array != NULL)
		printf("asldfja\n");
	
	while (check)
	{
		write(1, ">>>> ", 5);

		getReturn = getline(&buffer, &n, stdin);
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
