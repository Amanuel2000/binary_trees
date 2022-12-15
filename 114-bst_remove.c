#include "binary_trees.h"

/**
 * _bst_min_node - gets the minium node in a binary search tree
 *
 * @tree: the root node to a bst
 * Return: node containing the minimum value
 */
bst_t *_bst_min_node(bst_t *tree)
{
	if (tree == NULL)
		return (NULL);
	while (tree != NULL && tree->left != NULL)
		tree = tree->left;
	return (tree);
}

/**
 * bst_remove - removes a node from a binary search tree
 *
 * @root: the root node of the bst
 * @value: value to be deleted
 * Return: pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);
	if (value == root->n)
	{
		if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else
		{
			temp = _bst_min_node(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
			if (root->right)
				root->right->parent = root;
		}
	}
	else if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else
	{
		root->right = bst_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	return (root);
}
