#include "general.h"
#include "inputprompt.h"
#include <unistd.h>

/**
 * _putchar_to_fd - function print a character to a specific
 * file descriptor
 * @c: character to print
 * @fd: Place to print the character
 *
 * Return: 1 On success.
 * On error, -1 and errno is set appropriately.
 **/
int _putchar_to_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}


/**
 * print_to_fd - function to print a string
 *
 * @msg: string to print in
 * the file descriptor(fd) specified
 * @fd: File descriptor to print
 *
 * Return: 1 On success fd string printed
 * On error, -1 and errno is set appropriately.
 **/
int print_to_fd(char *msg, int fd)
{
	int size;

	size = _strlen(msg);

	return (write(fd, msg, size));
}