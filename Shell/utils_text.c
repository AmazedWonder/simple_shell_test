#include "inputprompt.h"

/**
 * _strlen - function responsible for returning the
 * length of a string
 * @msg: string to calculate length
 *
 * Return: int length of string
 **/
int _strlen(char *msg)
{
	int i;

	for (i = 0; msg[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcat - function concatenates(append) source string
 * to destination string
 *
 * @dest: string appended
 * @src: Source string
 *
 * Return: concatenated(joined) string
 */
char *_strcat(char *dest, char *src)
{
	int l_dest, i;

	l_dest = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++, l_dest++)
		dest[l_dest] = src[i];

	dest[l_dest] = '\0';

	return (dest);
}

/**
 * _strcpy - function copies a string to another destination
 *
 * @dest: destination of copied str
 * @src: source string to copy
 *
 * Return: pointer value of dest(string)
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}


/**
 * _strdup - Pointer to a newly allocated space in memory
 * string duplicated
 *
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string
 **/
char *_strdup(char *str)
{
	int size, i;
	char *dest;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(dest + i) = *(str + i);

	/* (dest + i) = 0; */

	return (dest);
}

/**
 * _strcmp - function used to compare two strings
 *
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Integer value of compared string
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}