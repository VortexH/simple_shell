#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int numToken(char *buffer, char *delims);
int execute_command(char **tokens);
char **tokenize(char *buffer, int tokenNum, char *delims);



#endif
