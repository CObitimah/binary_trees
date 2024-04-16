#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @r: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @r.
 */
bst_t *inorder_successor(bst_t *r)
{
	while (r->left != NULL)
		r = r->left;
	return (r);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @r: A pointer to the root node of the BST.
 * @n: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *r, bst_t *n)
{
	bst_t *parent = n->parent, *successor = NULL;

	/* No children or right-child only */
	if (n->left == NULL)
	{
		if (parent != NULL && parent->left == n)
			parent->left = n->right;
		else if (parent != NULL)
			parent->right = n->right;
		if (n->right != NULL)
			n->right->parent = parent;
		free(n);
		return (parent == NULL ? n->right : r);
	}

	/* Left-child only */
	if (n->right == NULL)
	{
		if (parent != NULL && parent->left == n)
			parent->left = n->left;
		else if (parent != NULL)
			parent->right = n->left;
		if (n->left != NULL)
			n->left->parent = parent;
		free(n);
		return (parent == NULL ? n->left : r);
	}

	/* Two children */
	successor = inorder_successor(n->right);
	n->n = successor->n;

	return (bst_delete(r, successor));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @r: A pointer to the root node of the BST to remove a node from.
 * @n: A pointer to the current node in the BST.
 * @v: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *r, bst_t *n, int v)
{
	if (n != NULL)
	{
		if (n->n == v)
			return (bst_delete(r, n));
		if (n->n > v)
			return (bst_remove_recursive(r, n->left, v));
		return (bst_remove_recursive(r, n->right, v));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @r: A pointer to the root node of the BST to remove a node from.
 * @v: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *r, int v)
{
	return (bst_remove_recursive(r, r, v));
}

