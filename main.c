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
	memstruct *mlcs = malloc(sizeof(memstruct));
	size_t n = 0;
	int check = 1;

	if (!mlcs)
		return (-1);

	variable_initializer(mlcs, argv, env);

	get_path_array(mlcs);

	if (!mlcs->path_array)
		custom_exit(mlcs);

	while (check)
	{
		if (isatty(0) == 1)
			write(1, "$ ", 2);

		mlcs->getReturn = getline(&mlcs->buffer, &n, stdin);
		printf("%s\n", mlcs->buffer);
		if (mlcs->getReturn == -1)
		{
			if (mlcs->path_array)
				free(mlcs->path_array);
			if (mlcs->tokenArray)
				free(mlcs->tokenArray);
			if (mlcs->buffer)
				free(mlcs->buffer);
			if (mlcs->direc_copy)
				free(mlcs->direc_copy);
			if (mlcs->path_copy)
				free(mlcs->path_copy);
			free(mlcs);
			if (isatty(0) == 1)
				write(1, "\n", 1);
			exit(EXIT_FAILURE);

		}

		mlcs->nTokens = numToken(mlcs);
		if (mlcs->nTokens)
		{
			mlcs->tokenArray = tokenize(mlcs);
			if (!mlcs->tokenArray)
				custom_exit(mlcs);
			execute_command(mlcs);
			free(mlcs->tokenArray);
			mlcs->tokenArray = NULL;
		}
			free(mlcs->buffer);
			mlcs->buffer = NULL;
		mlcs->loop_count++;
	}
	return (0);
}
