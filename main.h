#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <signal.h>
#define PROMPT "simple_shell $ "


/**
 * struct builtin_d - Defines the builtins functions.
 * @built: The name of the build in command.
 * @f: A pointer to the right builtin function.
 */
typedef struct builtin_d
{
	char *built;
	void (*f)(char *);
} builtin_t;

extern char **environ;

char **tokenize_interface(char *, const char *, int);
int count_token(char *, const char *);
char **tokenize(int, char *, const char *);
void create_child_process(char **, char *, int, char **);
void parse_line(char *, size_t, int, char **);
char *find_command_path(char *);
char *find_command_path(char *command);
int str_len(char *);
char *find_path(char *env_var, char *command);
char *search_directories(char **, char *);
char *build_path(char *, char *);
void double_free(char **);
void free_resources(int, ...);

char **tokenize_path(char *env_var);
char *search_directories(char **path_tokens, char *command);
char *build_path(char *directory, char *command);
/*Builtin functions*/
int built_in(char **, char *);
void (*check_built_ins(char *))(char *);
void exit_b(char *);
void env_b(char *);
void cd_b(char *);

int _strcmp(char *, char *);
char *_strdup(char *);
void print_str(char *, int);
int print_number(int);
int _write_char(char);

void error_printing(char *, int, char *);
void exec_error(char *, int, char *);

#endif
