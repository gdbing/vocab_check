#include "wide_trie.h"

wide_node * new_trie_node();
int insert_key(const char * key, size_t val_i, wide_node * n);
int insert_val(const char * val, wide_trie t);
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
{
	wide_trie * t = malloc(sizeof(wide_trie));

	t->root = new_trie_node();
	t->size = 32;
	t->count = 0;
	t->vals = malloc(sizeof(char*) * t->size);

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

int insert_wide(const char * key, const char * val, wide_trie * t)
/** insert new key and value pair
	modifies: t->root, t->vals, t->count, t->size

	return	1 for success
			0 if key already exists */
{
	if (insert_key(key, t->count, t->root)) {
		return insert_val(val, t);
	}
	return 0;
}

int insert_dup_wide(const char * new_key, const char * key, wide_trie * t)
/** insert new key assigned to same value as a pre-existing key
	modifies: t->root

	return	1 for success
			0 if key doesn't exist, or new_key already exists */
{
	size_t val_i = lookup_wide(key, t);
	if (val_i != 0) {
		return insert_key(new_key, val_i, t);
	} else {
		return 0;
	}
}

int insert_key(const char * key, size_t val_i, wide_node * n)
/** recursively make nodes to insert key, add val_i to final node
	modifies: n->children, n->val

	return	1 for success,
			0 if key already exists */
{
	if (key[0] == '\0') {
		if (n->val) // don't overwrite existing key:val relations
			return 0;
		n->val = val_i;
		return 1;
	}

	unsigned int i = char_to_index(key[0]);

	if (!(n->children[i])) {
		n->children[i] = new_trie_node();
	}

	return insert_key(key+1, val_i, n->children[i]);
}

int insert_val(const char * val, wide_trie t)
/** copy and add reference to val
	modifies: t->vals, t->count, t->size

	return	1 for success */
{
	if (t->size == t->count) {
		t->size *= 2;
		char ** new_arr = malloc(sizeof(char *) * t->size);
		for (size_t i = 0; i < t->count; i++) {
			new_arr[i] = t->vals[i];
		}
		free(t->vals);
		t->vals = new_arr;
	}

	t->vals[t->count] = malloc((strlen(val) + 1) * sizeof(char));
	strcpy(t->vals[t->count], val);
	t->count++;

	return 1;
}

/*****************************************************************************/
/*******************************  lookup  ************************************/
/*****************************************************************************/

const char * lookup_wide(const char * key, wide_trie * t)
/** return	value for key */
{
	return t->vals[lookup_r(key, t->root)];
}

size_t lookup(const char * key, wide_node * n)
/** return	index of value for key
			0 if key does not exist */
{
	if (key[0] == '\0') {
		return n->val;

	size_t i = char_to_index(key[0]);
	if (n->children[i])
		return lookup(key+1, n->children[i]);
	else
		return 0;
}
