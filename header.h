#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#define au __attribute__((unused))

typedef struct mallocs
{
	char **path_array;
	char **tokenArray;
	char *buffer;
	char *path_copy;
	char *direc_copy;
	char *delims;
	ssize_t getReturn;
	int nTokens;
} memstruct;

int numToken(memstruct mlcs);
char **tokenize(char **env, memstruct mlcs);
int execute_command(char **argv, memstruct mlcs);
char *_getenv(char **env);
char **get_path_array(char **env, memstruct mlcs);
char *search_tokens(memstruct mlcs);


void printenv(char **env);
char *_strpbrk(char *s, char *accept);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
unsigned int _strspn(char *s, char *accept);

#endif
