#include "binary_trees.h"

size_t height(const binary_tree_t *tr);
int balance(const binary_tree_t *tr);
avl_t *avl_insert_recursive(avl_t **tr, avl_t *p,
		avl_t **new, int val);
avl_t *avl_insert(avl_t **tr, int val);

/**
 * height - Measures the height of a binary tree.
 * @tr: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tr is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tr)
{
	if (tr != NULL)
	{
		size_t l = 0, r = 0;

		l = tr->left ? 1 + height(tr->left) : 1;
		r = tr->right ? 1 + height(tr->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - Measures the balance factor of a binary tree.
 * @tr: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tr is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tr)
{
	return (tr != NULL ? height(tr->left) - height(tr->right) : 0);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tr: A double pointer to the root node of the AVL tree to insert into.
 * @p: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @val: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tr, avl_t *p,
		avl_t **new, int val)
{
	int bfactor;

	if (*tr == NULL)
		return (*new = binary_tree_node(p, val));

	if ((*tr)->n > val)
	{
		(*tr)->left = avl_insert_recursive(&(*tr)->left, *tr, new, val);
		if ((*tr)->left == NULL)
			return (NULL);
	}
	else if ((*tr)->n < val)
	{
		(*tr)->right = avl_insert_recursive(&(*tr)->right, *tr, new, val);
		if ((*tr)->right == NULL)
			return (NULL);
	}
	else
		return (*tr);

	bfactor = balance(*tr);
	if (bfactor > 1 && (*tr)->left->n > val)
		*tr = binary_tree_rotate_right(*tr);
	else if (bfactor < -1 && (*tr)->right->n < val)
		*tr = binary_tree_rotate_left(*tr);
	else if (bfactor > 1 && (*tr)->left->n < val)
	{
		(*tr)->left = binary_tree_rotate_left((*tr)->left);
		*tr = binary_tree_rotate_right(*tr);
	}
	else if (bfactor < -1 && (*tr)->right->n > val)
	{
		(*tr)->right = binary_tree_rotate_right((*tr)->right);
		*tr = binary_tree_rotate_left(*tr);
	}

	return (*tr);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tr: A double pointer to the root node of the AVL tree to insert into.
 * @val: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tr, int val)
{
	avl_t *new = NULL;

	if (tr == NULL)
		return (NULL);
	if (*tr == NULL)
	{
		*tr = binary_tree_node(NULL, val);
		return (*tr);
	}
	avl_insert_recursive(tr, *tr, &new, val);
	return (new);
}

