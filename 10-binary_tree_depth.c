#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @node: Pointer to the node to measure the depth of
 *
 * Return: Depth of a node in a binary tree. If node is NULL, return 0
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	if (node == NULL)
		return (depth);

	while (node->parent != NULL)
	{
		depth++;
		node = node->parent;
	}

	return (depth);
}
