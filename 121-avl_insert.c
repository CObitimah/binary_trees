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
                                                                2,1        
