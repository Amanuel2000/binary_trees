#include "binary_trees.h"

/**
 * insert_to_queue - Inserts a node to a queue
 * @queue: The queue
 * @tree: Pointer to the root of tree
 *
 * Return: The head of the queue
 */
queue_t *insert_to_queue(queue_t **queue, const binary_tree_t *tree)
{
	queue_n *node;

	if (tree == NULL)
		return (NULL);

	node = malloc(sizeof(queue_n));
	if (node == NULL)
		return (NULL);
	node->value = (binary_tree_t *)tree;
	node->next = NULL;

	if ((*queue)->head == NULL)
		(*queue)->head = node;
	else
		(*queue)->tail->next = node;

	(*queue)->tail = node;
	return (*queue);
}

/**
 * pop_from_queue - Pops an item from a queue
 * @queue: The queue
 *
 * Return: The head of the queue
 */
binary_tree_t *pop_from_queue(queue_t **queue)
{
	queue_n *node;
	binary_tree_t *value;

	if (*queue == NULL || (*queue)->head == NULL)
		return (NULL);

	node = (*queue)->head;
	(*queue)->head = node->next;
	if ((*queue)->head == NULL)
		(*queue)->tail = NULL;

	value = node->value;
	free(node);
	return (value);
}

/**
 * binary_tree_levelorder - traverses binary tree using the level order
 * traversal
 *
 * @tree: the root node of the tree
 * @func: function to call for each visited node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(queue_t));
	if (queue == NULL)
		return;
	queue->head = NULL;
	queue->tail = NULL;
	queue = insert_to_queue(&queue, tree);
	while (queue != NULL)
	{
		tree = pop_from_queue(&queue);
		if (tree == NULL)
			break;
		func(tree->n);
		if (tree->left != NULL)
			queue = insert_to_queue(&queue, tree->left);
		if (tree->right != NULL)
			queue = insert_to_queue(&queue, tree->right);
	}
	free(queue);
}
