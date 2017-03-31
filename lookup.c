#include "trie.h"
#include "lookup.h"
#include "baked_data.c"

size_t lookup_r(const char *key, size_t node_i)
{
	skinny_node *n = (skinny_node *)&baked_trie[node_i];
	size_t i = char_to_index(key[0]);

	if (i >= 26 && (1 << NUM_CHARS) & n->bit_map)
		return n->val_i;

	if ((1 << i) & n->bit_map)
		return lookup_r(key+1, n->children[i]);

	return 0;
}

size_t lookup_key(const char *key)
{
	return lookup_r(key, 0);
}

const char *lookup_val(size_t val_i)
{
	return baked_vals[val_i];
}
