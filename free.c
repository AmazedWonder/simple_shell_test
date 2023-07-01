#include "memory.h"

/**
 * free_memory_p - function free memory using pointer
 *
 * @ptr: pointer to free
 **/
void free_memory_p(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}

	ptr = NULL;
}

/**
 * free_memorypp - functon frees memory alloc
 * using a double pointer to void
 *
 * @ptr: Double pointer to free
 **/
void free_memorypp(void **ptr)
{
	void **tmp;

	for (tmp = ptr; *tmp != NULL; tmp++)
		free_memory_p(*tmp);

	free_memory_p(ptr);
}