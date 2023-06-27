#include <stdin.h>
#include <stdlib.h>
#include <unistd.h>

void _prompt(void);
/**
* _prompt - funcrion displays prompt
*
* Return: void
*/
void _prompt(void)
{
	printf("$ ");  /* Customize the prompt if desired*/
}


/**
* main - entry point
* getline function
*
* Return: 0 always
*/

int main(void)
{
	size_t bytes = 100;
	char *buffer = NULL;

	/*getline automatically alloc memry*/
	/*buffer = malloc(sizeof(char) * bytes);*/
	while (1)
	{
	_prompt();

	printf("Enter name\n");
	getline(&buffer, &bytes, stdin);

	if (getline(&buffer, &bytes, stdin) == NULL)
	{
		printf("\n");
		break;  /*End of file (Ctrl+D) condition*/
	}

	printf("%sbuffer size is %ld\n", buffer, bytes);

	free(buffer);

	return (0);
}
