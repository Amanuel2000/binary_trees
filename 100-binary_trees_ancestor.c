#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *p_first, *p_second, *p_temp;

	if (first == NULL || second == NULL)
		return (NULL);

	p_first = (binary_tree_t *)first;
	p_second = (binary_tree_t *)second;

	while (p_first != NULL)
	{
		p_temp = p_second;
		while (p_temp != NULL)
		{
			if (p_first == p_temp)
				return (p_first);
			p_temp = p_temp->parent;
		}
		p_first = p_first->parent;
	}

	return (NULL);
}
