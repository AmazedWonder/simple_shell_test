#include "inputprompt.h"

/**
 * split_words - function is used to split an array of
 * str words using delimeter
 * 
 * @line: line of string to split
 * @sep: delimiter # used to split array of str
 *
 * Return: tokenized string
 **/
char **split_words(char *line, const char *sep)
{
	char **words, **tmp, *token;
	size_t new_size, old_size;

	old_size = sizeof(char *);
	words = malloc(old_size);
	if (words != NULL)
	{
		new_size = 1;
		token = strtok(line, sep);
		while (token)
		{
			if (token[0] == '#')
				break;
			tmp = _realloc(words, old_size, (new_size + 1) * sizeof(char *));
			old_size = (new_size + 1) * sizeof(char *);
			if (tmp == NULL)
				break;

			words = tmp;
			++new_size;

			words[new_size - 2] = malloc(_strlen(token) + 1);
			if (words == NULL)
			{
				free(words);
				free(tmp);
			}

			if (words[new_size - 2] != NULL)
				_strcpy(words[new_size - 2], token);

			token = strtok(NULL, sep);

			tmp = NULL;
		}

		words[new_size - 1] = NULL;
	}

	return (words);
}

/**
 * join_words - Joins multiple words into a single string with a separator
 * @word1: First word
 * @word2: Second word
 * @word3: Third word
 * @sep: Separator to insert between words
 *
 * Return: pointer to string joined
 * followed by a separator and
 * end by a new line or NULL if fail
 **/
char *join_words(char *word1, char *word2, char *word3, const char *sep)
{
	char *aux;
	int size_str1, size_str2, size_str3, size_sep;

	size_str1 = size_str2 = size_sep = 0;

	if (word1 != NULL)
		size_str1 = _strlen(word1);
	else
		word1 = "";

	if (word2 != NULL)
		size_str2 = _strlen(word2);
	else
		word2 = "";

	if (word3 != NULL)
		size_str3 = _strlen(word3);
	else
		word3 = "";

	if (sep != NULL)
		size_sep = _strlen((char *)sep);
	else
		sep = "";

	aux = malloc(size_str1 + size_str2 + size_sep + size_str3 + size_sep + 2);
	if (aux == NULL)
		return (NULL);

	aux = _strcpy(aux, word1);
	aux = _strcat(aux, (char *)sep);
	aux = _strcat(aux, word2);
	aux = _strcat(aux, (char *)sep);
	aux = _strcat(aux, word3);
	aux = _strcat(aux, "\n");

	return (aux);
}