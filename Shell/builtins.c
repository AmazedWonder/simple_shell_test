#include "builtins.h"

/**
 * builtins - function checks and execute shell builtins
 *
 * @info: struct info for shell
 * @arguments: command line input and arguments
 *
 * Return: _TRUE if the command passed is a builtins
 * _FALSE if not
 **/
int builtins(general_t *info, char **arguments)
{
	int status;

	status = check_builtin(info, arguments);
	if (status == _FALSE)
		return (_FALSE);

	return (_TRUE);
}


/**
 * check_builtin - function checks for actual builtin command(builtin_t)
 * or not builtin
 * @info: general struct shell cmd info
 * @arguments: command arguments
 *
 * Return: _TRUE if the command is an actual builtin
 * _FALSE if not
 **/
int check_builtin(general_t *info, char **arguments)
{
	int i, size;
	builtin_t builtins[] = {
		{"exit", bin_exit},
		{"env", bin_env}
	};

	size = sizeof(builtins) / sizeof(builtins[0]);
	for (i = 0; i < size; i++)
	{
		if (_strcmp(info->command, builtins[i].command) == 0)
		{
			builtins[i].func(info, arguments);
			return (_TRUE);
		}
	}

	return (_FALSE);
}