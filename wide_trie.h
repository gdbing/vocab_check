#include <stdlib.h>
#include <string.h>

#define NUM_CHARS 28 // a-z + ' ' + 'other'

typedef struct w_node {
	struct w_node * children[NUM_CHARS];
	size_t val; // index for wide_trie->vals
} wide_node;

typedef struct w_trie {
	// the root node of the trie itself
	wide_node * root;
	// variable length array of char* to store vals
	char ** vals;
	size_t size;
	size_t count;
} wide_trie;

wide_node * init_wide();
int insert_wide(const char * key, const char * val, wide_trie * t);
int insert_dup_wide(const char * new_key, const char * key, wide_trie * t);
const char* lookup_wide(const char * key, wide_node * n);

int char_to_index(char c); /* node->children[index] */
