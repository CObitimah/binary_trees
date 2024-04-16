#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tr: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tr is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tr)
{
	size_t lft, rgt;

	if (tr == NULL)
		return (0);
	lft = binary_tree_height(tr->left);
	rgt = binary_tree_height(tr->right);
	if (lft >= rgt)
		return (1 + lft);
	return (1 + rgt);
}

/**
 * binary_tree_level - perform a function on a specific level of a binary tree
 * @tr: pointer to the root of the tree
 * @lvl: level of the tree to perform a function on
 * @f: function to perform
 *
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tr, size_t lvl, void (*f)(int))
{
	if (tr == NULL)
		return;
	if (lvl == 1)
		f(tr->n);
	else if (lvl > 1)
	{
		binary_tree_level(tr->left, lvl - 1, f);
		binary_tree_level(tr->right, lvl - 1, f);
	}
}

/**
 * binary_tree_levelorder - traverses a binary tree using level-order traversal
 * @tr: pointer to the root node of the tree to traverse
 * @f: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tr, void (*f)(int))
{
	size_t height, i;

	if (tr == NULL || f == NULL)
		return;
	height = binary_tree_height(tr);
	for (i = 1; i <= height; i++)
		binary_tree_level(tr, i, f);
}

