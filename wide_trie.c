#include "wide_trie.h"

int char_to_index(char c)
{
	if (c == '\0')
		return NUM_CHARS - 1;
	if (c >= 'a' && c <= 'z')
		return (c - 'a');
	if (c >= 'A' && c <= 'Z')
		return ((int)c - (int)'A');
	if (c == ' ')
		return 26;
	return 27;
}

struct node * new_trie_node()
{
	return calloc(1, sizeof(struct node));
}

struct node * init_wide()
{
	return new_trie_node();
}

int insert(const char * key, const char * val, struct node * n)
{
	unsigned int i = char_to_index(key[0]);

	if (key[0] == '\0') {
		n->val = malloc(strlen(val)*sizeof(char));
		strcpy(n->val, val);
		n->children[i] = (struct node *)1;
		return 1;
	}

	if (!(n->children[i])) {
		n->children[i] = new_trie_node();
	}

	return insert(key+1, val, n->children[i]);
}

const char* lookup_wide(const char * key, struct node * n)
{
	unsigned int i = char_to_index(key[0]);

	if (!(n->children[i]))
		return "key not found";

	if (key[0] == '\0')
		return n->val;

	return lookup_wide(key+1, n->children[i]);
}
