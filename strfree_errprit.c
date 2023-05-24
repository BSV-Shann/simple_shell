#include "main.h"

/**
 * str_len - Calculate the length of a string.
 * @str: String to find the length of.
 *
 * Return: Length of the string. 0 if string is NULL.
 */
int str_len(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * double_free - Free memory allocated for a double pointer.
 * @to_be_freed: Address of the elements to be freed.
 */
void double_free(char **to_be_freed)
{
	int index = 0;

	while (to_be_freed[index] != NULL)
	{
		free(to_be_freed[index]);
		index++;
	}

	free(to_be_freed);
}

/**
 * single_free - Free n number of string pointers.
 * @n: Number of pointers to free.
 * @...: Variable number of pointers to be freed.
 */
void single_free(int n, ...)
{
	int i;
	char *str;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (str == NULL)
			str = "(nil)";

		free(str);
	}

	va_end(args);
}

/**
 * error_printing - Print an error message for a command not found.
 * @av: Name of the program running the shell.
 * @count: Number of commands run on the shell.
 * @command: Command not found.
 */
void error_printing(char *av, int count, char *command)
{
	print_str(av, 1);
	print_str(": ", 1);
	print_number(count);
	print_str(": ", 1);
	print_str(command, 1);
}

/**
 * exec_error - Print exec errors.
 * @av: Name of the program running the shell.
 * @count: Number of commands entered.
 * @tmp_command: Command that failed.
 */
void exec_error(char *av, int count, char *tmp_command)
{
	error_printing(av, count, tmp_command);
	print_str(": ", 1);
	perror("");
	exit(1);
}

