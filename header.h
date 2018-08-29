#ifndef _HEADER_H_
#define _HEADER_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#define au __attribute__((unused))

/**
 * struct mallocs - Struct of all function variables that cross functions
 * @path_array: Array of pointers to path string values
 * @tokenArray: Array of pointers to values passed in through getline
 * @argv: Arguments passed in on the command line
 * @env: Environment variable
 * @buffer: Values stored from getline
 * @path_copy: Copy of path string to not alter original
 * @direc_copy: Copy of individual directory string to not alter original
 * @delims: Delimiters for strtok
 * @pathDelims: Delimiters for strtok specifically for path string
 * @getReturn: Return value of getline to check for failure
 * @nTokens: Number of tokens returned from numTokens
 * @loop_count: Count of main loop instances
 *
 * Description: Holds variables for inter-function operability
 */

typedef struct mallocs
{
	char **path_array;
	char **tokenArray;
	char **tmparr;
	char **argv;
	char **env;
	char *buffer;
	char *path_copy;
	char *direc_copy;
	char *delims;
	char *pathDelims;
	char *input_token;
	ssize_t getReturn;
	int nTokens;
	unsigned int loop_count;
} memstruct;

int numToken(memstruct *mlcs);
int pathNumToken(memstruct *mlcs);
char **tokenize(memstruct *mlcs);
char **tokenizepath(memstruct *mlcs);
int execute_command(memstruct *mlcs);
char *_getenv(memstruct *mlcs);
void get_path_array(memstruct *mlcs);
char *search_tokens(memstruct *mlcs);
void custom_exit(memstruct *mlcs);

void printenv(memstruct *mlcs);
char *_strpbrk(char *s, char *accept);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
unsigned int _strspn(char *s, char *accept);
char *_strdup(char *str);


#endif
