#include <stdin.h>
#include <unistd.h>

/**
* main -Entry point
* for execve
*
* Return: 0 always
*/

int main(void)
{
	pid_t pid;
	char *argv[] = {"bin/ls", "-l", "NULL"};
	int result;

	pid = fork();
	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
	result = execve(argv[0], argv, NULL);

		if (result == -1)
			perror("Error\n");
	}
	else
	{
	wait(NULL);
	printf("Successful execve\n");
	}

	return (0);
}
