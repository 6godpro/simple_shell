#ifndef SHELL_H
#define SHELL_H


#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>

/* Global environment */
extern char **environ;
extern char **aliases;
/**
 * struct dir_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct dir_s.
 */
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
char **get_input(ssize_t *len);
int _exits(char *argv);
int execute_cmd(char **argv);
int exec_builtin(char **argv);
void cpy_lineptr(char **lineptr, size_t *n, char *buff, size_t byte);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* string functions */
void _puts(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int _putchar(char c);
int _strcmp(const char *s1, char *s2);
int _strlen(const char *str);
int count_words(char **str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *s1, char *s2);
char **_strtok(char *str, const char *delim);
int letters_len(char *str, const char *delim);
int count_token(char *str, const char *delim);

/* env functionalities */
void print_env(void);
int _unsetenv(char *var);
int _setenv(char *var, char *value);
int setenv_handler(char **av);
int unsetenv_handler(char **av);
char **_getenv(const char *var);

/* alias functionalities */
char **creat_alias(void);
int set_alias(char **aliases, char **argv);
int alias_handler(char **argv);
void print_alias(char **aliases, char *name);

#endif /* SHELL_H */
