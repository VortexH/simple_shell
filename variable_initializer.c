#include "header.h"

void variable_initializer(memstruct *mlcs, char **argv, char **env)
{

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


}
