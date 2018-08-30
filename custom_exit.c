#include "header.h"

/**
 * custom_exit - exit for specific cases that also prints error and loop number
 * @mlcs: Pointer to struct containing all variables
 * Return: Void
 */

void custom_exit(memstruct *mlcs)
{
	int div = 1;
	unsigned int temp = 0;

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

	write(1, mlcs->argv[0], _strlen(mlcs->argv[0]));
	write(1, ": ", 2);

	while (mlcs->loop_count / div > 9)
		div = div * 10;
	while (div != 0)
	{
		temp = (mlcs->loop_count / div + '0');
		write(1, &temp, 1);
		mlcs->loop_count = mlcs->loop_count % div;
		div = div / 10;
		temp = 0;
	}
	write(1, ": ", 2);

	write(1, mlcs->input_token, _strlen(mlcs->input_token));
	free(mlcs->input_token);
	mlcs->input_token = NULL;

	write(1, ": ", 2);
	perror("");

	free(mlcs);
	exit(EXIT_FAILURE);

}
