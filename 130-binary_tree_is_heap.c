#include "binary_trees.h"

int get_total_nodes(const binary_tree_t *tree);
int is_b_heap(const binary_tree_t *tree, int index,
			  int max_index, int max_val);

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int nodes;

	if (!tree)
		return (0);
	nodes = get_total_nodes(tree);
	return (is_b_heap(tree, 0, nodes - 1, tree->n));
}

/**
 * get_total_nodes - Counts the total number of nodes in a binary tree
 *
 * @tree: Pointer to the root node of the tree to count the number of nodes
 *
 * Return: The total number of nodes in the tree
 */
int get_total_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_total_nodes(tree->left) + get_total_nodes(tree->right));
}

/**
 * is_b_heap - Checks if a binary tree is a valid Max Binary Heap
 * Description: A binary tree is Max Binary Heap if:
 * - It is a complete tree (All levels are completely filled except possibly
 *   the last level and the last level has all keys as left as possible).
 * - Every node is greater than or equal to its children.
 *
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @max_index: Max index of the tree
 * @max_val: Max value of the tree
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int is_b_heap(const binary_tree_t *tree, int index,
			  int max_index, int max_val)
{
	if (!tree)
		return (1);
	if (index > max_index || tree->n > max_val)
		return (0);
	return (is_b_heap(tree->left, 2 * index + 1, max_index, tree->n) &&
			is_b_heap(tree->right, 2 * index + 2, max_index, tree->n));
}
