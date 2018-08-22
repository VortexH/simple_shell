#include "header.h"

/**
 * main - Main function calling all other functions
 * @argc: Number of arguments passed in after program
 * @argv: Value of arguments passed in after program
 * @env: Environment variable
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

	(void)argv;
	(void)env;
	(void)argc;


	write(1, "$ ", 2);

	buffer = malloc(n);
	if (!buffer)
		return (-1);

	getReturn = getline(&buffer, &n, stdin);

	while (getReturn != -1)
	{
		if ((tokenNum = numToken(buffer, delims)))
			tokens = tokenize(buffer, tokenNum, delims);

		else
			return (-1);

		printf("%s", *tokens);
		write(1, "$ ", 2);
		getReturn = getline(&buffer, &n, stdin);
	}
	if (getReturn == -1)
		return (-1);


	return (0);

}
