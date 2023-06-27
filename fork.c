#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - entry point
 * multiplies numbers
 *
 * Return: 0 always
 */
int main(void)
{
	pid_t pid;

	printf("Before fork, pid is %u\n", pid);
/* creation of child process */
	fork();
/* if fork fails*/
	if (pid == -1)
	{
		perror("Error\n");
		return (1);
	}

	if (pid == 0)/*child pr*/
	{
	printf("after fork, became child process, pid is %u\n", pid);
	}
	else
	{
	wait(NULL);
	printf("parent process, pid is %u\n", pid);
	}
	return (0);
}
