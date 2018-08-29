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
	memstruct vars = {NULL};
	memstruct *mlcs = &vars;
	size_t n = 0;
	int check = 1;
	int h;

	mlcs->argv = argv;
	mlcs->env = env;
	mlcs->delims = " \n\t";
	mlcs->pathDelims = ":\0";
	get_path_array(mlcs);
	printf("Are the directory tokens being added Properly?\n");
	for (h = 0; mlcs->path_array[h]; h++)
		printf("Directory in path: %s\n", mlcs->path_array[h]);
	if (!mlcs->path_array)
	{
		write(1, mlcs->argv[0], _strlen(mlcs->argv[0]));
		write(1, ": ", 2);
		perror("");
		exit(EXIT_FAILURE);
	}
	while (check)
	{
		write(1, ">>>> ", 5);

		mlcs->getReturn = getline(&mlcs->buffer, &n , stdin);
		if (mlcs->getReturn == -1)
			return (-1);

		mlcs->nTokens = numToken(mlcs);
		if (mlcs->nTokens)
		{
/*-------------------PROBLEMS---------------------------*/
			mlcs->tokenArray = tokenize(mlcs);
/*------------------------------------------------------*/
		if (!mlcs->tokenArray)
			{
				free(mlcs->buffer);
				free(mlcs->path_array);
				return (-1);
			}
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
