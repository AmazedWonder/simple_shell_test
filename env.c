#include "builtins.h"

/**
 * bin_env - function responible for implementation of envbuiltin
 * @info: general struct info for shell
 * @arguments: command line args
 **/
void bin_env(general_t *info, char **arguments)
{
	(void) info;
	(void) arguments;

	get_full_env();
}