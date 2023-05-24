#include "main.h"

/**
 * _strcmp - compares two strings.
 * @string1: First string.
 * @string2: Second string.
 *
 * Return:0 if the strings are equal.
 * -1 if the strings are not equal.
 */
int _strcmp(char *string1, char *string2)
{
	int index;

	if (str_len(string1) != str_len(string2))
		return (-1);
	for (index = 0; string1[index] != '\0'; index++)
	{
		if (string1[index] != string2[index])
			return (-1);
	}
	return (0);
}

/**
 * _strdup - Creates a copy of a string.
 * @source: The original string.
 * Return: A pointer to the duplicated string.
 */
char *_strdup(char *source)
{
	int index;
	int length = str_len(source);
	char *destination = malloc(sizeof(char) * (length + 1));

	for (index = 0; source[index] != '\0'; index++)
		destination[index] = source[index];
	destination[index] = '\0';

	return (destination);
}

/**
 * print_str - Prints a string character by character.
 * @string: The string to be printed.
 * @newLine:the string is NULL, it prints "(null)".
 * Return: If the value is 0, a new line will be printed.
 * Otherwise, no new line is printed.
 */
void print_str(char *string, int newLine)
{
	int index;

	if (string == NULL)
		string = "(null)";
	for (index = 0; string[index] != '\0'; index++)
		write(STDOUT_FILENO, &string[index], 1);
	if (newLine == 0)
		write(STDOUT_FILENO, "\n", 1);
}

/**
 * _write_char - Writes a character to the standard output.
 * @character: The character to be written.
 *
 * Return:The number of characters successfully written.
 */
int _write_char(char character)
{
	return (write(STDOUT_FILENO, &character, 1));
}
