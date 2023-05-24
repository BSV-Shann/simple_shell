#include "main.h"

/**
 * parse_line - Parses the command line looking for commands and arguments.
 * This function is also in charge of freeing memory that is no longer
 * needed by the program.
 * @line: A pointer to a string. Will always be NULL upon function entry.
 * @size: A holder for numbers of size_t. Will always be initialized to 0.
 * @command_counter: A counter keeping track of how many commands have been
 * entered into the shell.
 * @av: Name of the program running the shell
 */
void parse_line(char *line, size_t size, int command_counter, char **av)
{
	int i;
	ssize_t read_len;
	int token_count;
	char **param_array;
	const char *delim = "\n\t ";

	token_count = 0;
	write(STDOUT_FILENO, PROMPT, str_len(PROMPT));
	read_len = getline(&line, &size, stdin);
	if (read_len != -1)
	{
		param_array = tokenize_interface(line, delim, token_count);
		if (param_array[0] == NULL)
		{
			free_resources(2, param_array, line);
			return;
		}
		i = built_in(param_array, line);
		if (i == -1)
			create_child_process(param_array, line, command_counter, av);
		for (i = 0; param_array[i] != NULL; i++)
			free(param_array[i]);
		free_resources(2, param_array, line);
	}
	else
		exit_b(line);
}

/**
 * create_child_process - Creates a child process to execute another program.
 * @param_array: An array of string pointers containing the possible program name.
 * This array is NULL terminated.
 * @line: The contents of the read line.
 * @count: A counter keeping track of how many commands have been entered.
 * @av: Name of the program running the shell
 */
void create_child_process(char **param_array, char *line, int count, char **av)
{
	pid_t child_pid;
	int status;
	int i;
	int check;
	struct stat buf;
	char *tmp_command;
	char *command;

	child_pid = fork();
	if (child_pid == 0)
	{
		tmp_command = param_array[0];
		command = find_command_path(param_array[0]);
		if (command == NULL)
		{
			/* Looking for file in current directory */
			check = stat(tmp_command, &buf);
			if (check == -1)
			{
				error_printing(av[0], count, tmp_command);
				print_str(": not found", 0);
				free_resources(2, line, tmp_command);
				for (i = 1; param_array[i]; i++)
					free(param_array[i]);
				free(param_array);
				exit(100);
			}
			/* File exists in current working directory or has full path */
			command = tmp_command;
		}
		param_array[0] = command;
		if (param_array[0] != NULL)
		{
			if (execve(param_array[0],
				param_array, environ) == -1)
				exec_error(av[0], count, tmp_command);
		}
	}
	else
		wait(&status);
}

/**
 * tokenize_interface - Interacts with other token functions and makes
 * them more accessible to other parts of the program.
 * @line: A string containing the raw user input.
 * @delim: A constant string containing the desired delimiter to tokenize line
 * @token_count: Holder for the amount of tokens in a string
 * Return: An array of token representing the command else NULL
 */
char **tokenize_interface(char *line, const char *delim, int token_count)
{
	char **param_array;

	token_count = count_token(line, delim);
	if (token_count == -1)
	{
		free(line);
		return (NULL);
	}
	param_array = tokenize(token_count, line, delim);
	if (param_array == NULL)
	{
		free(line);
		return (NULL);
	}
	return (param_array);
}

/**
 * tokenize - Separates string into an array of tokens.
 * @token_count: An integer rep-ing the amount of tokens in the array.
 * @line: String separated by an specified delimeter
 * @delim: The desired delimeter to separate tokens.
 * Return: A NULL terminated array of string pointer, else returns NULL.
 */
char **tokenize(int token_count, char *line, const char *delim)
{
	int i;
	char **buffer;
	char *token;
	char *line_cp;

	line_cp = _strdup(line);
	buffer = malloc(sizeof(char *) * (token_count + 1));
	if (buffer == NULL)
		return (NULL);
	token = strtok(line_cp, delim);
	for (i = 0; token != NULL; i++)
	{
		buffer[i] = _strdup(token);
		token = strtok(NULL, delim);
	}
	buffer[i] = NULL;
	free(line_cp);
	return (buffer);
}

/**
 * count_token - Counts tokens in a passed string.
 * @line: String that is separated by an specified delimeter
 * @delim: The desired delimeter to separate tokens.
 * Return: Upon success the total count of the tokens. Otherwise -1.
 */
int count_token(char *line, const char *delim)
{
	char *str;
	char *token;
	int i;

	str = _strdup(line);
	if (str == NULL)
		return (-1);
	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);
	free(str);
	return (i);
}
