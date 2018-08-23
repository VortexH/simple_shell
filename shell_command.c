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
	char *delims = " \n";
	char *buffer;
	char **tokens;
	size_t n = 1024;
	ssize_t getReturn;
	int tokenNum = 0;
	int check;

	(void)argv;
	(void)env;
	(void)argc;

	buffer = malloc(n);
	if (!buffer)
		return (-1);


	check = 1;
	while (check)
	{
		write(1, "$ ", 2);

		getReturn = getline(&buffer, &n, stdin);

		if (getReturn == -1)
			return (-1);

		tokenNum = numToken(buffer, delims);
		if (tokenNum)
		{
			tokens = tokenize(buffer, tokenNum, delims);
			if (!tokens)
				return (-1);
			execute_command(tokens);
		}
		else
			return (-1);

	}
	return (0);
}
