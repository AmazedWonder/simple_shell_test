#include <stdio.h>
#include <unistd.h>

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

  fork();

  if (pid == -1)
  {
    perror("Error\n");
    return (1);
  }

  printf("after fork, pid is %u\n", pid);

  return (0);
}
