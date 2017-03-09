typedef struct s_node {
	size_t mask; /* denotes which children exist, whether val exists */
	size_t children[NUM_CHARS]; /* index location of child in key_data */
	size_t val_i; /* index of val in vals */
} skinny_node;

typedef struct s_trie {
	skinny_node * root;
	size_t * key_data;
	char ** vals;
} skinny_trie;

skinny_trie * init_skinny(wide_trie * t);
const char * lookup_skinny(const char * key, skinny_trie * t);
