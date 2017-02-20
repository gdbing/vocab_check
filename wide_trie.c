#include "wide_trie.h"

int char_to_index(char c)
{
	// if (c == '\0')
	// 	return NUM_CHARS - 1;
	if (c >= 'a' && c <= 'z')
		return (c - 'a');
	if (c >= 'A' && c <= 'Z')
		return ((int)c - (int)'A');
	if (c == ' ')
		return 26;
	return 27;
}

wide_node * new_trie_node()
{
	return calloc(1, sizeof(wide_node));
}

wide_node * init_wide()
{
	return new_trie_node();
}

int insert(const char * key, const char * val, wide_node * n)
{
	if (key[0] == '\0') {
		if (n->val)
			free(n->val);
		n->val = malloc((strlen(val) + 1) * sizeof(char));
		strcpy(n->val, val);
		return 1;
	}

	unsigned int i = char_to_index(key[0]);

	if (!(n->children[i])) {
		n->children[i] = new_trie_node();
	}

	return insert(key+1, val, n->children[i]);
}

const char* lookup_wide(const char * key, wide_node * n)
{
	unsigned int i = char_to_index(key[0]);

	if (key[0] == '\0') {
		if (n->val)
			return n->val;
		else
			return "key not found";
	}

	if (!(n->children[i]))
		return "key not found";

	return lookup_wide(key+1, n->children[i]);
}
