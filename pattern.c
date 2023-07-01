#include "commands.h"
#include "general.h"
#include "memory.h"
#include "inputprompt.h"

/**
 * analyze_patterns - function responsible for analyzing
 * patterns in an array of arguments
 * @info: pointer to general_t structure
 * @arguments: Array of arguments inputted
 **/

void analyze_patterns(general_t *info, char **arguments)
{
	int i;

	for (i = 0; arguments[i] != NULL; i++)
		arguments[i] = pattern_handler(info, arguments[i]);
}

/**
 * pattern_handler - function is responsible for handling
 * patterns in a string
 * @info: pointer to general_t structure
 * @string: string to be processed
 *
 * Return: modified str
 **/

char *pattern_handler(general_t *info, char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '$' && string[i + 1] != '\0')
			string = replace_value(info, &i, string);
	}

	return (string);
}

/**
 * replace_value - function is to replace a pattern value in a string
 * @info: pointer to general_t structure
 * @index: pointer to the index of pattern in string
 * @string: string to be processed
 *
 * Return: modified string
 **/

char *replace_value(general_t *info, int *index, char *string)
{
	int i, new_s, old_s;
	char *value;

	i = *index;
	i++;

	value = replacement(info, index, string + i);
	if (value == NULL)
	{
		string = _strcpy(string, "");

		return (string);
		;
	}

	old_s = _strlen(string);
	new_s = _strlen(value) + 1;

	string = _realloc(string, old_s, new_s);
	string = _strcpy(string, value);

	free_memory_p(value);
	*index = i;
	return (string);
}
