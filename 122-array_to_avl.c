#include "binary_trees.h"

/**
 * array_to_avl - finds the lowest common ancestor of two nodes
 * @array: a pointer to the first node
 * @size: a pointer to the first node
 * Return: If no common ancestor was found return NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *new_node = NULL;

	unsigned int index;

	for (index = 0; index < size; index++)
	{
		avl_insert(&new_node, array[index]);
	}
	return (new_node);
}
