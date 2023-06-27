#include <stdio.h>
#include <string.h>

/**
* main - entry point
* tokenizer function
*
* Return: 0 always
*/
int main(void)
{
	/*char str[] = "Hello World!";*/
	char *str_src = "Hello Amazing World!"
	char str = malloc(sizeof(char) * strlen(str_src) + 1);
	char *delim = " ";
	char *token;

	strcp(str, str_src);

	token = strtok(str, delim);
	/*printf("%s\n", token);*/

	/* set NULL to parse arr str to be tokenized*/
	while (token)
	{
		token = strtok(NULL, delim);
		printf("%s\n", token);
	}

	return (0);
}
