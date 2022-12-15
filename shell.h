#ifndef SHELL_H
#define SHELL_H


#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>

extern char **environ;

/* TODO include documentation for struct */
typedef struct dir_s
{
	char *dir;
	struct dir_s *next;
} dir_t;

/* utilities */
void free_list(dir_t *head);
void free_args(char **argv);
void sig_handler(int sig);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
dir_t *add_node_end(dir_t **head, char *dir);
dir_t *get_path(char *path);
char *concat_path(char *pathname, char *progname);
char *find(char *cname);
char *find(char *command);
char **tok_arr(char *str, const char *delim);
char **get_input(ssize_t *len);
int _exits(char *argv);
int execute_cmd(char **argv);
int exec_builtin(char **argv);

/* string functions */
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(const char *s1, char *s2);
int _strlen(const char *str);
char * _strcpy(char *dest, char *src);
char *_strcat(char *s1, char *s2);

/* functionalities */
int _unsetenv(char *var);
int _setenv(char *var, char *value);
char **_getenv(const char *var);
int setenv_handler(char **av);


#endif /* SHELL_H */
