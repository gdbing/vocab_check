#include "trie.h"
#include "init.h"
#include <string.h>

/*****************************************************************************/
/**********************************  wide  ***********************************/
/*****************************************************************************/

wide_node *new_trie_node();
int insert_key(const char *key, size_t val_i, wide_node *wn);
int insert_val(const char *val, wide_trie *wt);

wide_trie *init_trie()
/* create a wide_trie and assign initial property values
 * create the root wide_node and dynamic length array for vals
 *
 *  returns the new wide_trie */
{
	wide_trie *wt = malloc(sizeof(wide_trie));

	wt->root = new_trie_node();

	wt->val_size = 32;
	wt->val_count = 0;
	wt->vals = malloc(sizeof(char*) * wt->val_size);

	// assign t->vals[0] to failure msg, so lookup can return 0 for failure
	insert_val("key not found", wt);

	return wt;
}

wide_node *new_trie_node()
{
	return calloc(1, sizeof(wide_node));
}

int insert(const char *key, const char *val, wide_trie *wt)
/** insert new key and value pair
	modifies: t->root, t->vals, t->val_count, t->val_size

	return	1 for success
			0 if key already exists */
{
	if (insert_key(key, wt->val_count, wt->root))
		return insert_val(val, wt);

	return 0;
}

int insert_key(const char *key, size_t val_i, wide_node *wn)
/** recursively create nodes to insert key, assign val_i of terminal node */
{
	if (key[0] == '\0') {
		if (wn->bit_map & (1 << NUM_CHARS)) // key already exists
			return 0;

		wn->bit_map |= (1 << NUM_CHARS);
		wn->val_i = val_i;
		return 1;
	}

	size_t i = char_to_index(key[0]);

	if (!(wn->children[i])) {
		wn->children[i] = new_trie_node();
		wn->bit_map |= (1 << i);
	}

	return insert_key(key+1, val_i, wn->children[i]);
}

int insert_val(const char *val, wide_trie *wt)
/** copy and add reference to val
	modifies: t->vals, t->val_count, t->val_size

	return	1 for success */
{
	if (wt->val_size == wt->val_count) {
		wt->val_size *= 2;
		char ** new_arr = malloc(sizeof(char *) * wt->val_size);
		for (size_t i = 0; i < wt->val_count; i++)
			new_arr[i] = wt->vals[i];
		free(wt->vals);
		wt->vals = new_arr;
	}

	wt->vals[wt->val_count] = malloc((strlen(val) + 1) * sizeof(char));
	strcpy(wt->vals[wt->val_count], val);
	wt->val_count++;

	return 1;
}

/*****************************************************************************/
/********************************  skinny  ***********************************/
/*****************************************************************************/

size_t count_nodes(wide_node *wn);
size_t pack_node(wide_node *wn, skinny_trie *st);

skinny_trie *pack_trie(wide_trie *wt)
{
	skinny_trie *st = malloc(sizeof(skinny_trie));

	size_t node_count = count_nodes(wt->root);
	printf("count_nodes: %ld\n", node_count); // DEBUG

	st->key_data = calloc(node_count, sizeof(skinny_node));
	st->data_len = node_count * sizeof(skinny_node) / sizeof(size_t);
	printf("data_len: %ld\n", st->data_len); // DEBUG

	pack_node(wt->root, st);
	st->root = (skinny_node *)(st->key_data);

	st->vals = wt->vals;
	st->val_count = wt->val_count;

	return st;
}

size_t count_nodes(wide_node *wn)
{
	size_t count = 1;
	for (size_t i = 0; i < NUM_CHARS; i++) {
		if (wn->children[i])
			count += count_nodes(wn->children[i]);
	}
	return count;
}

size_t pack_node(wide_node *wn, skinny_trie *st)
{
	skinny_node *sn;
	size_t i;

	/* find appropriately shaped free space */
	for (i = 0; /* this is dumb */; i++) {
		sn = (skinny_node *)(&st->key_data[i]);

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
			sn->children[j] = pack_node(wn->children[j], st);
	}

	return i;
}

/*****************************************************************************/
/********************************  baked  ************************************/
/*****************************************************************************/

void serialize_trie(skinny_trie *st, FILE *fp)
{
	size_t len;
	for (len = st->data_len - 1; len > 0; len--) {
		if (st->key_data[len]) {
			len += sizeof(skinny_node) / sizeof(size_t);
			break;
		}
	}
	if (len == 0) // there is no data
		len = sizeof(skinny_node) / sizeof(size_t);

	printf("serialized data len: %ld\n", len); // DEBUG
	fprintf(fp, "#include \"trie.h\"\n\n");

	fprintf(fp, "size_t baked_trie[] = { ");
	for (size_t i = 0; i < len; i++) {
		fprintf(fp, "%ld", st->key_data[i]);
		if (i+1 < len)
			fprintf(fp, ", ");
	}
	fprintf(fp, " };\n\n");

	fprintf(fp, "const char * baked_vals[] = {\n");
	for (size_t i = 0; i < st->val_count; i++) {
		fprintf(fp, "\t\"%s\"", st->vals[i]);
		if (i+1 < st->val_count)
			fprintf(fp, ",\n");
	}
	fprintf(fp, " };\n");
}

