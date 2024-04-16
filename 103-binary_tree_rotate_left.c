#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tr: pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tr)
{
	if (tr == NULL)
		return (NULL);
	tr->parent = tr->right;
	if (tr->right)
	{
		tr->right = tr->right->left;
		tr->parent->left = tr;
		tr->parent->parent = NULL;
		if (tr->right)
			tr->right->parent = tr;
		return (tr->parent);
	}
	return (tr);
}


