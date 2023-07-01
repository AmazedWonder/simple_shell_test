#include "general.h"
#include "inputprompt.h"

/**
 * _putchar - function prints a character to standard output(STDOUT)
 * @c: character to print
 *
 * Return: 1 On success
 * -1 On error
 **/
int _putchar(char c)
{
	return (write(STDOUT, &c, 1));
}

/**
 * print - function prints a message to STDOUT
 *
 * @msg: msg to print
 *
 * Return: On success,str printed
 * On errror -1, and set the error
 **/
int print(char *msg)
{
	return (print_to_fd(msg, STDOUT));
}