#include "builtins.h"
#include "general.h"

/**
 * bin_exit - function responsible for implementation
 * of exiting builtins
 * Description: free all memory allocated and
 * exit with the last status_code
 *
 * @info: general struct info about the shell
 * @arguments: args received
 **/
void bin_exit(general_t *info, char **arguments)
{
	int status_code, status;

	status = _TRUE;
	if (arguments[1] != NULL)
		status = number_controller(info, arguments[1]);

	if (status == _FALSE)
		return;

	status_code = info->status_code;

	free_memorypp((void **) arguments);
	free_memory_p((void *) info->buffer);
	free_memory_p((void *) info->environment);
	free_memory_p((void *) info);

	exit(status_code);
}

/**
 * number_controller - function controls the arguments exit
 * validating and processing a number received as input
 * @info: general struct info abt shell
 * @number: argument of builtin num
 *
 * Return: _TRUE if the actual argument is valid
 * _FALSE if not valid
 **/
int number_controller(general_t *info, char *number)
{
	int _number;

	_number = _atoi(number);

	if (_number < 0 || contains_letter(number))
	{
		info->status_code = 2;
		info->error_code = _CODE_ILLEGAL_NUMBER;
		error_extra(info, number);
		return (_FALSE);
	}

	if (_number > 255)
		info->status_code = _number % 256;
	else
		info->status_code = _number;

	return (_TRUE);
}