#include "commands.h"
#include "general.h"
#include "memory.h"

/**
 * execute - function responsible for executing a command
 * in other process
 * @command: command to be executed
 * @arguments: @command arguments
 * @info: general struct info about shell
 * @buff: line read
 **/
void execute(char *command, char **arguments, general_t *info, char *buff)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(command, arguments, environ);
		perror("./sh");

		free_memorypp((void *) arguments);

		if (info->value_path != NULL)
		{
			free(info->value_path);
			info->value_path = NULL;
		}

		free(info);
		free(buff);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			info->status_code = WEXITSTATUS(status);
	}
}


/**
 * current_directory - function responsible for executing the command line args
 * if the order require
 * @cmd: command to be executed
 * @arguments: Arguments of @cmd
 * @buff: storage for str of line read
 * @info: general struct info about shell
 *
 * Return: status of the operations
 **/
int current_directory(char *cmd, char **arguments, char *buff, general_t *info)
{

	if (info->is_current_path == _FALSE)
		return (_FALSE);

	if (is_executable(cmd) == PERMISSIONS)
	{
		execute(cmd, arguments, info, buff);
		return (_TRUE);
	}

	return (_FALSE);
}