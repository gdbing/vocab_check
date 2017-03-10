#include <string.h>
#include "wide_trie.h"

wide_node * new_trie_node();
int insert_key(const char * key, size_t val_i, wide_node * n);
int insert_val(const char * val, wide_trie * t);
size_t lookup(const char * key, wide_node * n);

size_t char_to_index(char c)
{
	// if (c == '\0')
	// 	return NUM_CHARS - 1;
	if (c >= 'a' && c <= 'z')
		return (c - 'a');
	if (c >= 'A' && c <= 'Z')
		return ((size_t)c - (size_t)'A');
	if (c == ' ')
		return 26;
	return 27;
}

/*****************************************************************************/
/**********************************  init  ***********************************/
/*****************************************************************************/

wide_trie * init_wide()
/** create a wide_trie and assign initial property values
	create the root wide_node and dynamic length array for vals

	returns the new wide_trie */
{
	wide_trie * t = malloc(sizeof(wide_trie));

	t->root = new_trie_node();

	t->val_size = 32;
	t->val_count = 0;
	t->vals = malloc(sizeof(char*) * t->val_size);

	insert_val("key not found", t); // assign t->vals[0] to failure state, so lookup can return 0 for failure

	return t;
}

wide_node * new_trie_node()
{
	return calloc(1, sizeof(wide_node));
}

/*****************************************************************************/
/**********************************  insert  *********************************/
/*****************************************************************************/

int insert(const char * key, const char * val, wide_trie * t)
/** insert new key and value pair
	modifies: t->root, t->vals, t->val_count, t->val_size

	return	1 for success
			0 if key already exists */
{
	if (insert_key(key, t->val_count, t->root))
		return insert_val(val, t);

	return 0;
}

int insert_dup(const char * new_key, const char * old_key, wide_trie * t)
/** insert new key with the same value as a pre-existing old key
	modifies: t->root

	return	1 for success
			0 if old_key doesn't exist, or new_key already exists */
{
	size_t val_i = lookup(old_key, t->root);
	if (val_i != 0)
		return insert_key(new_key, val_i, t->root);

	return 0;
}

int insert_key(const char * key, size_t val_i, wide_node * n)
/** recursively make nodes to insert key, add val_i to final node
	modifies: n->children, n->val

	return	count of new nodes created
			0 if key already exists */
{
	if (key[0] == '\0') {
		if (n->bit_map & (1 << NUM_CHARS)) // key already exists
			return 0;

		n->bit_map |= (1 << NUM_CHARS);
		n->val_i = val_i;
		return 1;
	}

	size_t i = char_to_index(key[0]);

	if (!(n->children[i])) {
		n->children[i] = new_trie_node();
		n->bit_map |= (1 << i);
	}

	return insert_key(key+1, val_i, n->children[i]);
}

int insert_val(const char * val, wide_trie * t)
/** copy and add reference to val
	modifies: t->vals, t->val_count, t->val_size

	return	1 for success */
{
	if (t->val_size == t->val_count) {
		t->val_size *= 2;
		char ** new_arr = malloc(sizeof(char *) * t->val_size);
		for (size_t i = 0; i < t->val_count; i++)
			new_arr[i] = t->vals[i];
		free(t->vals);
		t->vals = new_arr;
	}

	t->vals[t->val_count] = malloc((strlen(val) + 1) * sizeof(char));
	strcpy(t->vals[t->val_count], val);
	t->val_count++;

	return 1;
}

/*****************************************************************************/
/*******************************  lookup  ************************************/
/*****************************************************************************/

const char * lookup_wide(const char * key, wide_trie * t)
/** return	value for key */
{
	return t->vals[lookup(key, t->root)];
}

size_t lookup(const char * key, wide_node * n)
/** recursively follow nodes to lookup key

	return	index of value for key
			0 if key does not exist */
{
	if (key[0] == '\0')
		return n->val_i;

	size_t i = char_to_index(key[0]);
	if (n->children[i])
		return lookup(key+1, n->children[i]);
	else
		return 0;
}
