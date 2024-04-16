#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @arr: pointer to the first element of the array to be converted
 * @sz: number of element in the array
 *
 * Description: If a value of the array already exists, this value is ignored
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *arr, size_t sz)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; i < sz; i++)
	{
		bst_insert(&root, arr[i]);
	}
	return (root);
}

