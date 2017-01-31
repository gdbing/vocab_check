#include <stdlib.h>
#include <string.h>

#define NUM_CHARS 28 // a-z + ' ' + 'other'

struct node {
	intptr_t childmask; // should change this type to ensure that it is the same width as struct node * and char *
	struct node * children[NUM_CHARS];
	char * desc;
};

int insert(const char * key, const char * desc, struct node * n);
char* lookup(const char * key, struct node * n);
struct node * trie_init();
