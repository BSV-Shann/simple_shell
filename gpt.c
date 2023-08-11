#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * find_command_path - Finds the full path of a program
 * @command: The command for which the full path needs to be found.
 * Return: A string with the full path of the program if found, otherwise NULL.
 */
char *find_command_path(char *command)
{
	char *path_var = getenv("PATH");

	if (path_var == NULL)
		return (NULL);

	char *directory = find_path(path_var, command);

	if (directory == NULL)
		return (NULL);

	char *full_path = build_path(directory, command);

	free(directory);
	return (full_path);
}

/**
 * find_path - Finds the index of an environmental variable.
 * @str: Environmental variable needed to be found.
 * Return: The index of the environmental variable if found, -1 otherwise.
 */
int find_path(char *str, char *command)
{
	int len = strlen(str);

	for (int s = 0; environ[s] != NULL; s++)
	{
		int k;

		for (k = 0; k < len; k++)
		{
			if (environ[s][k] != str[k])
				break;
		}
		if (k == len && environ[s][k] == '=')
			return (s);
	}
	return (-1);
}

/**
 * tokenize_path - Separates a string of paths
 * into an array of path directories.
 * @env_var: pointer to a string.
 * Return: A NULL-terminated array of pointers to strings if successful,
 * otherwise returns NULL. Remember to free allocated memory as needed.
 */
char **tokenize_path(char *env_var)
{
	int token_count = 0;
	char *env_var_copy = strdup(env_var);
	char *token = strtok(env_var_copy, ":");

	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, ":");
	}

	char **path_tokens = malloc(sizeof(char *) * (token_count + 1));

	if (path_tokens == NULL)
	{
		free(env_var_copy);
		return (NULL);
	}

	token_count = 0;
	token = strtok(env_var, ":");
	while (token != NULL)
	{
		path_tokens[token_count] = strdup(token);
		token_count++;
		token = strtok(NULL, ":");
	}
	path_tokens[token_count] = NULL;

	free(env_var_copy);
	return (path_tokens);
}

/**
 * search_directories - Searches through directories
 * for a specific file (command).
 * @path_tokens: Pointer to an array of strings representing different paths.
 * @command: The command to search for (e.g., ls, echo, pwd, /bin/ls, etc.).
 * Return: A string with the topmost directory containing the command file
 * if found, otherwise returns NULL.
 */
char *search_directories(char **path_tokens, char *command)
{
	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
		return (NULL);

	char *directory = NULL;

	for (int i = 0; path_tokens[i] != NULL; i++)
	{
		if (chdir(path_tokens[i]) == -1)
			continue;

		struct stat stat_buf;

		if (stat(command, &stat_buf) == 0)
		{
			directory = strdup(path_tokens[i]);
			break;
		}
		chdir(cwd);
	}

	free(cwd);
	return (directory);
}

/**
 * build_path - Combines two strings to form a full path.
 * @directory: The directory in the path.
 * @command: The file in the directory.
 * Return: A string representing the full path of the command if successful,
 * otherwise NULL.
 */
char *build_path(char *directory, char *command)
{
	size_t dir_len = strlen(directory);
	size_t command_len = strlen(command);
	size_t full_path_len = dir_len + 1 + command_len + 1;

	char *full_path = malloc(full_path_len);

	if (full_path == NULL)
		return (NULL);

	snprintf(full_path, full_path_len, "%s/%s", directory, command);
	return (full_path);
}

