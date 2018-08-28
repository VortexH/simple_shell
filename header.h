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
	char **argv;
	char **env;
	char *buffer;
	char *path_copy;
	char *direc_copy;
	char *delims;
	char *pathDelims;
	ssize_t getReturn;
	int nTokens;
	unsigned int loop_count;
} memstruct;

int numToken(memstruct mlcs);
int pathNumToken(memstruct mlcs);
char **tokenize(memstruct mlcs);
char **tokenizepath(memstruct mlcs);
int execute_command(memstruct mlcs);
char *_getenv(memstruct mlcs);
char **get_path_array(memstruct mlcs);
char *search_tokens(memstruct mlcs);
void custom_exit(memstruct mlcs);

void printenv(memstruct mlcs);
char *_strpbrk(char *s, char *accept);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
unsigned int _strspn(char *s, char *accept);
char *_strdup(char *str, int n);


#endif
