#include "binary_trees.h"

/**
 * is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if @node is a leaf, and 0 otherwise. If @node is NULL, return 0
 */
int is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * measure_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If @tree is NULL, return 0
 */
size_t measure_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = measure_height(tree->left);
	right_height = measure_height(tree->right);
	if (left_height >= right_height)
		return (1 + left_height);
	return (1 + right_height);
}

/**
 * measure_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor of
 *
 * Description: If @tree is NULL, return 0
 *
 * Return: balance factor of a binary tree
 */
int measure_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = measure_height(tree->left);
	right_height = measure_height(tree->right);
	return (left_height - right_height);
}

