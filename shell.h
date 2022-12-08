#ifndef SHELL_H
#define SHELL_H

typedef struct dir_s dir_t;

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>

extern char **environ;


/* utilities */
char *find(char *command);
dir_t *add_node_end(dir_t **head, char *dir);
void free_list(dir_t *head);
dir_t *get_path(char *path);
char **tok_arr(char *str, const char *delim);
int execute_cmd(char **argv);
char **clear(char **args);
char *concat_path(char *pathname, char *progname);
char *find(char *cname);


/* functionalities */
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
char **_getenv(const char *var);


/* TODO include documentation for struct */
typedef struct dir_s
{
	char *dir;
	struct dir_s *next;
} dir_t;


#endif /* SHELL_H */
