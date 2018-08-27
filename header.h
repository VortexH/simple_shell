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

int numToken(char *bf, char *d);
char **tokenize(char *buffer, int nTokens, char *delims, char **env);
int execute_command(char **token_array, char **argv, char **path_array);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
int _strlen(char *s);
char *_getenv(char **env);
char **get_path_array(char **env);
char *search_tokens(char **path_array, char *token);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void printenv(char **env);

#endif
