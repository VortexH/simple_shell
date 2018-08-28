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
	memstruct mlcs;
	size_t n = 0;
	int check = 1;
	char *buffer = NULL;
	ssize_t getReturn;

	mlcs.delims = " \n\t";
/**	mlcs.path_array = get_path_array(env, mlcs);
 */
	while (check)
	{
		write(1, ">>>> ", 5);

		getReturn = getline(&buffer, &n, stdin);

		printf("Hello");

		mlcs.buffer = buffer;

		if (getReturn == -1)
			return (-1);

		mlcs.nTokens = numToken(mlcs);
		if (mlcs.nTokens)
		{
			mlcs.tokenArray = tokenize(env, mlcs);
			if (!mlcs.tokenArray)
				return (-1);
			execute_command(argv, mlcs);
		}

	}
	return (0);
}
