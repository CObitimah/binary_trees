#include "binary_trees.h"
#include <stdio.h>

/**
 * greater_than - check if all values in the tree are greater than a value
 * @tr: pointer to the tree to check
 * @val: value to check against
 *
 * Return: 1 if true, 0 if false
 */
int greater_than(const binary_tree_t *tr, int val)
{
	int l, r;

	if (tr == NULL)
		return (1);
	if (tr->n > val)
	{
		l = greater_than(tr->left, val);
		r = greater_than(tr->right, val);
		if (l && r)
			return (1);
	}
	return (0);
}

/**
 * less_than - check if all values in the tree are less than a specific value
 * @tr: pointer to the tree to check
 * @val: value to check against
 *
 * Return: 1 if true, 0 if false
 */
int less_than(const binary_tree_t *tr, int val)
{
	int l, r;

	if (tr == NULL)
		return (1);
	if (tr->n < val)
	{
		l = less_than(tr->left, val);
		r = less_than(tr->right, val);
		if (l && r)
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tr: pointer to the root node of the tree to check
 *
 * Return: 1 if tr is a valid BST, and 0 otherwise. If tr is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tr)
{
	if (tr == NULL)
		return (0);
	if (less_than(tr->left, tr->n) && greater_than(tr->right, tr->n))
	{
		if (!tr->left || binary_tree_is_bst(tr->left))
		{
			if (!tr->right || binary_tree_is_bst(tr->right))
				return (1);
		}

	}
	return (0);
}

