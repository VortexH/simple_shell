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

	/** delimiters for commands to shell are: newlines, tabs, and spaces */
	mlcs.delims = " \n\t";
	/** delims for path are colons and null bytes **/
	mlcs.pathDelims = ":\0";
	/** call once to generate array of directories from path **/
	mlcs.path_array = get_path_array(env, mlcs);

	while (check)
	{
		write(1, ">>>> ", 5);

		mlcs.getReturn = getline(&mlcs.buffer, &n , stdin);

		if (mlcs.getReturn == -1)
			return (-1);

		mlcs.nTokens = numToken(mlcs);
		if (mlcs.nTokens)
		{
			mlcs.tokenArray = tokenize(env, mlcs);
			if (!mlcs.tokenArray)
				return (-1);
			execute_command(argv, mlcs);
			free(mlcs.tokenArray);
			mlcs.tokenArray = NULL;
		}
		free(mlcs.buffer);
		mlcs.buffer = NULL;

	}
	return (0);
}
