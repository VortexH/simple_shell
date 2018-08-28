#include "header.h"

void custom_exit(memstruct mlcs)
{

	free(mlcs.tokenArray);
	free(mlcs.path_array);
	free(mlcs.buffer);

	write(1, mlcs.argv[0], _strlen(mlcs.argv[0]));
	write(1, ": ", 2);
	perror("");

	exit(EXIT_FAILURE);

}
