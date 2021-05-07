#include "binary_trees.h"

/**
 * swap_node - Swap a node while node->n > parent->n
 * @node: Pointer to the node to swap
 */
void swap_node(heap_t *node)
{
	int tmp = 0;

	for (; node->parent; node = node->parent)
	{
		if (node->n > node->parent->n)
		{
			tmp = node->parent->n;
			node->parent->n = node->n;
			node->n = tmp;
		}
	}
}

/**
 * position - Find the position to insert a node
 * @node: Tree's root
 * @pos: Position to insert a node
 * @flag: Bool to keep recursion
 * @depth: Tree's depth
 * @level: Position in the Tree (0 == root)
 * Return: @pos
 */
heap_t *position(heap_t *node, heap_t *pos, int *flag, int *depth, int level)
{
	if (*flag)
	{
		if (!node->left || !node->right)
		{
			if (!pos)
			{
				*depth = level;
				pos = node;
			}
			else if (level < *depth)
			{
				*flag = 0;
				pos = node;
			}
		}
		else
		{
			pos = position(node->left, pos, flag, depth, level + 1);
			pos = position(node->right, pos, flag, depth, level + 1);
		}
	}

	return (pos);
}

/**
 * heap_insert - Max HEAP insertion function.
 * @root: pointer to the first node of the tree
 * @value: number to be inserted
 * Return: Pointer to the new created node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = NULL, *parent = NULL;
	int flag = 1, depth = 0;

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = position(*root, parent, &flag, &depth, 0);
	node = binary_tree_node(parent, value);

	if (!parent->left)
		parent->left = node;
	else
		parent->right = node;

	swap_node(node);
	return (node);
}
