#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/**
 * struct space_s - Struct to find the space at a Binary tree node.
 * @n: Size of the node
 * @p: Node.
 */
struct space_s
{
	int n;
	heap_t *p;
};

typedef struct space_s space_t;

heap_t *heap_insert(heap_t **root, int value);
heap_t *insert_new_node(heap_t *parent);
heap_t *heap_swap(heap_t *node);
space_t heap_size(heap_t *node);

#endif /* BINARY_TREES_H */
