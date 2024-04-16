#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @nd: pointer to the node to check
 *
 * Return: 1 if nd is a leaf, and 0 otherwise. If nd is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *nd)
{
	if (nd != NULL && nd->left == NULL && nd->right == NULL)
		return (1);
	return (0);
}

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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tr: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tr is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tr)
{
	binary_tree_t *l, *r;

	if (tr == NULL)
		return (1);
	l = tr->left;
	r = tr->right;
	if (binary_tree_is_leaf(tr))
		return (1);
	if (l == NULL || r == NULL)
		return (0);
	if (binary_tree_height(l) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tr: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tr is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tr)
{
	size_t l_height, r_height;
	binary_tree_t *l, *r;

	if (tr == NULL)
		return (0);
	if (binary_tree_is_leaf(tr))
		return (1);
	l = tr->left;
	r = tr->right;
	l_height = binary_tree_height(l);
	r_height = binary_tree_height(r);
	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_complete(r))
			return (1);
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}

