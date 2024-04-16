#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tr: pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tr)
{
	if (tr == NULL)
		return (NULL);
	tr->parent = tr->left;
	if (tr->left)
	{
		tr->left = tr->left->right;
		tr->parent->right = tr;
		tr->parent->parent = NULL;
		if (tr->left)
			tr->left->parent = tr;
		return (tr->parent);
	}
	return (tr);
}

