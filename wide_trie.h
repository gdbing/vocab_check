#include <stdlib.h>
#include <string.h>

#define NUM_CHARS 29 // a-z + ' ' + 'other' + '\0'

struct node {
	struct node * children[NUM_CHARS]; // \0 child is 1 if its a terminal node
	char * val;
};

struct node * init_wide(); /* creates a root node to build trie on */
int insert(const char * key, const char * val, struct node * root);
const char* lookup_wide(const char * key, struct node * n);

int char_to_index(char c); /* node->children[index] */
