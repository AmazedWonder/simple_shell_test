#include "inputprompt.h"

/**
 * print_err - function prints a message to STDERR
 *
 * @msg: error msg to be printed
 *
 * Return: Number of characters printed,
 * or -1 on failure
 **/
int print_err(char *msg)
{
	return (print_to_fd(msg, STDERR));
}