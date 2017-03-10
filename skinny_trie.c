#include "wide_trie.h"
#include "skinny_trie.h"

size_t add_node(wide_node * wn, skinny_trie * t);
size_t lookup_s(const char * key, skinny_trie * st, skinny_node * n);

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
	st->key_data = calloc(wt->node_count, sizeof(skinny_node));
	st->data_len = wt->node_count * sizeof(skinny_node) / sizeof(size_t);

	add_node(wt->root, st);
	st->root = (skinny_node *)(st->key_data);

	st->vals = wt->vals;
	st->val_count = wt->val_count;

	return st;
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

		if (sn->mask)
			continue;
		if (wn->val && sn->val_i)
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
	if (wn->val) {
		sn->val_i = wn->val;
		sn->mask |= (1 << NUM_CHARS);
	}

	/* reserve space for children */
	for (size_t j = 0; j < NUM_CHARS; j++) {
		if (wn->children[j]) {
			sn->children[j] = 1;
			sn->mask |= (1 << j);
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
		if ((1 << NUM_CHARS) & n->mask)
			return n->val_i;
		else
			return 0;
	}

	size_t i = char_to_index(key[0]);
	if ((1 << i) & n->mask)
		return lookup_s(key+1, st, (skinny_node *)&st->key_data[n->children[i]]);
	else
		return 0;
}
