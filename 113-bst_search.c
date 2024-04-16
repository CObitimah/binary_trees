#include "binary_trees.h"

/**
 * bst_search - searches for a value in a binary search tree
 * @tr: pointer to the root node of the BST to search
 * @val: value to search in the tree
 *
 * Return: pointer to the node containing a value equal to val, or NULL
 */
bst_t *bst_search(const bst_t *tr, int val)
{
	bst_t *tmp;

	tmp = (bst_t *)tr;
	while (tmp)
	{
		if (tmp->n == val)
			return (tmp);
		if (tmp->n < val)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return (NULL);
}

