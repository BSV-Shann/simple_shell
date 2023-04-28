#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * _stringcopy - copies the string pointed to by src,
 * including the terminating null byte (\0) to buffer pointed to by dest
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 */
void string_copy(char *dest, const char *src);

/**
 * execmd - execute command
 * @argv: arguement to take in
 */
void execmd(char **argv);

#endif
