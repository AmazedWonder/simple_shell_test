#include "commands.h"
#include "general.h"

/**
 * is_executable - funtion checks if a filename have
 *  permissions to run
 * @filename: filename to check
 *
 * Return: PERMISSIONS On success
 * On error, NON_PERMISSIONS
 * NON_FILE for no file
 **/
int is_executable(char *filename)
{
	struct stat stats;

	if (stat(filename, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}

	return (NON_FILE);
}

/**
 * is_file - funtion checks if a file or binary
 * Description: iterates for excute permissions and
 * if is a file
 * @file: File to check
 *
 * Return:  PERMISSIONS,file with the correct permissions
 * NON_PERMISSIONS, file not have permissions or doesn't exists
 * If is not a file, NON_FILE
 **/
int is_file(char *file)
{
	int i, size;

	size = _strlen(file);
	for (i = 0; i < size; i++)
		if (file[i] == '/')
			return (is_executable(file));

	return (NON_FILE);
}