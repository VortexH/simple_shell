#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int numToken(char *buffer, char *delims);
char **tokenize(char *buffer, int tokenNum, char *delims);



#endif
