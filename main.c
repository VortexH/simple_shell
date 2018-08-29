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

	mlcs.loop_count = 1;
	mlcs.argv = argv;
	mlcs.env = env;
	mlcs.buffer = NULL;
	/** delimiters for commands to shell are: newlines, tabs, and spaces */
	mlcs.delims = " \n\t";
	/** delims for path are colons and null bytes **/
	mlcs.pathDelims = ":\0";
	/** call once to generate array of directories from path **/
	mlcs.path_array = get_path_array(mlcs);
	if (!mlcs.path_array)
	{
		write(1, mlcs.argv[0], _strlen(mlcs.argv[0]));
		write(1, ": ", 2);
		perror("");
		exit(EXIT_FAILURE);
	}
	while (check)
	{
		write(1, ">>>> ", 5);

		mlcs.getReturn = getline(&mlcs.buffer, &n , stdin);

		if (mlcs.getReturn == -1)
			return (-1);

		mlcs.nTokens = numToken(mlcs);
		if (mlcs.nTokens)
		{
			mlcs.tokenArray = tokenize(mlcs);
			if (!mlcs.tokenArray)
			{
				free(mlcs.buffer);
				free(mlcs.path_array);
				return (-1);
			}
			execute_command(mlcs);
			free(mlcs.tokenArray);
			mlcs.tokenArray = NULL;
		}
		free(mlcs.buffer);
		mlcs.buffer = NULL;
		mlcs.loop_count++;
	}
	return (0);
}
