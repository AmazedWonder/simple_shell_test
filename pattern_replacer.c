#include "general.h"
#include "inputprompt.h"
#include "commands.h"

/**
 * replacement - function replaces special symbols in a string
 * @info: pointer to general_t structure
 * @index: pointer to index (not used in this function)
 * @string: string to be processed
 *
 * Return: modified string or NULL on failure
 **/

char *replacement(general_t *info, int *index, char *string)
{
	char *tmp;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		tmp = replace_env(info, string);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmp);
}


/**
 * replace_env - function replaces environment variable with its value
 * @info: pointer to general_t structure (not used in this function)
 * @environment: env variable to be replaced
 *
 * Return: Value of the environment variable 
 * or NULL if not found
 **/

char *replace_env(general_t *info, char *environment)
{
	char *env;

	(void) info;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}