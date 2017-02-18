#include <stdlib.h>
#include <string.h>

#define NUM_CHARS 28 // a-z + ' ' + 'other'

typedef struct w_node {
	struct w_node * children[NUM_CHARS];
	char * val;
} wide_node;

wide_node * init_wide(); /* creates a root node to build trie on */
int insert(const char * key, const char * val, wide_node * root);
const char* lookup_wide(const char * key, wide_node * n);

int char_to_index(char c); /* node->children[index] */
