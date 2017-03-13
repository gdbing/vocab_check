#include "trie.h"
#include "lookup.h"
#include "baked_data.c"

size_t lookup_r(const char * key, skinny_node * n)
{
	size_t i = char_to_index(key[0]);
	if (i >= 26 && (1 << NUM_CHARS) & n->bit_map)
		return n->val_i;

	if ((1 << i) & n->bit_map)
		return lookup_r(key+1, (skinny_node *)&baked_trie[n->children[i]]);

	return 0;
}

size_t lookup_key(const char * key)
{
	return lookup_r(key, (skinny_node *)&baked_trie[0]);
}

const char * lookup_val(size_t val_i)
{
	return baked_vals[val_i];
}
