#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tr);
int is_avl_helper(const binary_tree_t *tr, int l, int h);
int binary_tree_is_avl(const binary_tree_t *tr);

/**
 * height - Measures the height of a binary tree.
 * @tr: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tr is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tr)
{
	if (tr)
	{
		size_t l = 0, r = 0;

		l = tr->left ? 1 + height(tr->left) : 1;
		r = tr->right ? 1 + height(tr->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tr: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tr, int lo, int hi)
{
	size_t lh, rh, diff;

	if (tr != NULL)
	{
		if (tr->n < lo || tr->n > hi)
			return (0);
		lh = height(tr->left);
		rh = height(tr->right);
		diff = lh > rh ? lh - rh : rh - lh;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tr->left, lo, tr->n - 1) &&
			is_avl_helper(tr->right, tr->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tr: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tr is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tr)
{
	if (tr == NULL)
		return (0);
	return (is_avl_helper(tr, INT_MIN, INT_MAX));
}

