#include "wide_trie.h"
#include "skinny_trie.h"

size_t node_count(wide_node * n);
size_t val_count(wide_node * n);
size_t add_skinny_node(wide_node * n);
size_t add_val(const char * val);


const char * lookup_r(const char * key, size_t node_i)
{
	// printf("0x%lX: %s\n", skinny_trie[node_i], key);
	if (key[0] == '\0') {
		if ((1 << (NUM_CHARS - 1)) & skinny_trie[node_i])
			return vals[skinny_trie[node_i + NUM_CHARS]];
		else
			return "key not found";
	}
	size_t offset = char_to_index(key[0]);
	if ((1 << offset) & skinny_trie[node_i])
		return lookup_r(key+1, skinny_trie[node_i + 1 + offset]);
	else
		return "key not found";
}

const char * lookup_skinny(const char * key)
{
	// this is really just for testing and debugging i guess,
	// refactor it out of this file
	return lookup_r(key, 0);
}

void init_skinny(wide_node * n)
{
	vals = malloc(val_count(n) * sizeof(char *));
	skinny_trie = calloc(node_count(n), sizeof(size_t) * (NUM_CHARS + 1));

	add_skinny_node(n);
}

/* get number of values in a wide trie */
size_t val_count(wide_node * n)
{
	size_t count = (n->children[NUM_CHARS - 1]) ? 1 : 0;
	for (int i = 0; i < NUM_CHARS - 1; i++) { // dont crawl \0 child
		if (n->children[i])
			count += val_count(n->children[i]);
	}
	return count;
}

/* get number of nodes in a wide trie */
size_t node_count(wide_node * n)
{
	size_t count = 1;
	for (int i = 0; i < NUM_CHARS - 1; i++) { // dont crawl \0 child
		if (n->children[i])
			count += node_count(n->children[i]);
	}
	return count;
}

size_t add_skinny_node(wide_node * n)
{
	size_t i;

	/* find appropriately shaped free space */
	for (i = 0; /* this is dumb */; i++) {
		size_t j;
		for (j = 0; j < NUM_CHARS; j++) {
			if (skinny_trie[i])
				break;
			if (n->children[j] && skinny_trie[i+1+j])
				break;
		}
		if (j == NUM_CHARS)
			break;
	}

	/* create mask */
	size_t mask = 0;
	for (size_t j = 0; j < NUM_CHARS; j++) {
		if (n->children[j]) {
			mask |= (1 << j);
		}
	}
	skinny_trie[i] = mask;

	/* reserve space for children */
	for (size_t j = 0; j < NUM_CHARS; j++) {
		if (n->children[j])
			skinny_trie[i+1+j] = 1;
	}

	/* recursively add children */
	for (size_t j = 0; j < NUM_CHARS - 1; j++) {
		if (n->children[j])
			skinny_trie[i+1+j] = add_skinny_node(n->children[j]);
	}

	/* handle terminal nodes */
	if (n->children[NUM_CHARS - 1]) {
		skinny_trie[i + NUM_CHARS] = add_val(n->val);
	}

	return i;
}

size_t add_val(const char * val)
{
	static size_t val_i = -1;
	val_i++;

	vals[val_i] = val;
	return val_i;
}
