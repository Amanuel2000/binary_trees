#include "binary_trees.h"

/**

 * bst_insert_helper - Inserts a node into a binary search tree.

 * @tree: A pointer to the binary search tree.

 * @value: The value of the new node.

 *

 * Return: A pointer to the created node, otherwise NULL.

 */

bst_t *bst_insert_helper(bst_t **tree, int value)

{

	bst_t *new_node = NULL, *parent = NULL;



	if (tree != NULL)

	{

		parent = *tree;

		if (*tree == NULL)

		{

			new_node = binary_tree_node(*tree, value);

			*tree = new_node;

		}

		else

		{

			while (parent != NULL)

			{

				if ((parent->n > value) && (parent->left != NULL))

					parent = parent->left;

				else if ((parent->n < value) && (parent->right != NULL))

					parent = parent->right;

				else

					break;

			}

			if (parent->n < value)

			{

				new_node = binary_tree_node(parent, value);

				parent->right = new_node;

			}

			else if (parent->n > value)

			{

				new_node = binary_tree_node(parent, value);

				parent->left = new_node;

			}

		}

	}

	return (new_node);

}



/**

 * tree_height_2 - Computes the height of a binary tree.

 * @tree: The binary tree.

 *

 * Return: The height of the tree.

 */

int tree_height_2(const binary_tree_t *tree)

{

	int left = 0, right = 0;



	if (tree != NULL)

	{

		left = tree_height_2(tree->left);

		right = tree_height_2(tree->right);

	}

	return ((left > right ? left : right) + 1);

}
