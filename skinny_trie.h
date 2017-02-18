const char ** vals;
size_t * skinny_trie;

typedef struct s_node {
	size_t bitmap;
	size_t children[NUM_CHARS];
	size_t value;
} skinny_node;

void init_skinny(wide_node * root);
const char * lookup_skinny(const char * key);
