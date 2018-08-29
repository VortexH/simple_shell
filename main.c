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

	mlcs->path_array = NULL;
	mlcs->tokenArray = NULL;
	mlcs->tmparr = NULL;
	mlcs->argv = argv;
	mlcs->env = env;
	mlcs->buffer = NULL;
	mlcs->path_copy = NULL;
	mlcs->direc_copy = NULL;
	mlcs->input_token = NULL;
	mlcs->delims = " \n\t";
	mlcs->pathDelims = ":\0";
	mlcs->getReturn = 0;
	mlcs->nTokens = 0;
	mlcs->loop_count = 1;

	get_path_array(mlcs);

	if (!mlcs->path_array)
		custom_exit(mlcs);

	while (check)
	{
		write(1, "$ ", 2);

		mlcs->getReturn = getline(&mlcs->buffer, &n, stdin);
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
