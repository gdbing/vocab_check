#include "wide_trie.h"
#include "skinny_trie.h"

size_t add_node(wide_node * wn, skinny_trie * t);
size_t lookup_s(const char * key, skinny_trie * st, skinny_node * n);
size_t count_nodes(wide_node * n);

/*****************************************************************************/
/**********************************  init  ***********************************/
/*****************************************************************************/

skinny_trie * init_skinny(wide_trie * wt)
{
	if (sizeof(size_t) < 4) {
		// size_t must be at least NUM_CHARS + 1 bits wide
		return 0;
	}

	skinny_trie * st = malloc(sizeof(skinny_trie));

	size_t node_count = count_nodes(wt->root);
	st->key_data = calloc(node_count, sizeof(skinny_node));
	st->data_len = node_count * sizeof(skinny_node) / sizeof(size_t);

	add_node(wt->root, st);
	st->root = (skinny_node *)(st->key_data);

	st->vals = wt->vals;
	st->val_count = wt->val_count;

	return st;
}

size_t count_nodes(wide_node * n)
{
	size_t count = 1;
	for (size_t i = 0; i < NUM_CHARS; i++) {
		if (n->children[i])
			count += count_nodes(n->children[i]);
	}
	return count;
}

/*****************************************************************************/
/********************************  insert  ***********************************/
/*****************************************************************************/

size_t add_node(wide_node * wn, skinny_trie * t)
{
	skinny_node *sn;
	size_t i;

	/* find appropriately shaped free space */
	for (i = 0; /* this is dumb */; i++) {
		sn = (skinny_node *)(&t->key_data[i]);

		if (sn->bit_map)
			continue;
		if (wn->val_i && sn->val_i)
			continue;

		size_t j;
		for (j = 0; j < NUM_CHARS; j++) {
			if (wn->children[j] && sn->children[j])
				break;
		}
		if (j == NUM_CHARS)
			break;
	}

	/* handle terminal node */
	if (wn->val_i) {
		sn->val_i = wn->val_i;
		sn->bit_map |= (1 << NUM_CHARS);
	}

	/* reserve space for children */
	for (size_t j = 0; j < NUM_CHARS; j++) {
		if (wn->children[j]) {
			sn->children[j] = 1;
			sn->bit_map |= (1 << j);
		}
	}

	/* recursively add children */
	for (size_t j = 0; j < NUM_CHARS; j++) {
		if (wn->children[j])
			sn->children[j] = add_node(wn->children[j], t);
	}

	return i;
}

/*****************************************************************************/
/*********************************  lookup  **********************************/
/*****************************************************************************/

const char * lookup_skinny(const char * key, skinny_trie * st)
{
	return st->vals[lookup_s(key, st, st->root)];
}

size_t lookup_s(const char * key, skinny_trie * st, skinny_node * n)
{
	if (key[0] == '\0') {
		if ((1 << NUM_CHARS) & n->bit_map)
			return n->val_i;
		else
			return 0;
	}

	size_t i = char_to_index(key[0]);
	if ((1 << i) & n->bit_map)
		return lookup_s(key+1, st, (skinny_node *)&st->key_data[n->children[i]]);
	else
		return 0;
}
