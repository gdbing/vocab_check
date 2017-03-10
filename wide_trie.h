#include <stdlib.h>

#define NUM_CHARS 28 // a-z + ' ' + 'other'

typedef struct w_node {
	size_t bit_map;
	struct w_node * children[NUM_CHARS];
	size_t val_i; // index for wide_trie->vals
} wide_node;

typedef struct w_trie {
	// the root node of the trie itself
	wide_node * root;
	// variable length array of char* to store vals
	char ** vals;
	size_t val_size;
	size_t val_count;
} wide_trie;

wide_trie * init_wide();
int insert(const char * key, const char * val, wide_trie * t);
int insert_dup(const char * new_key, const char * key, wide_trie * t);
const char * lookup_wide(const char * key, wide_trie * t);

size_t char_to_index(char c); /* node->children[index] */
