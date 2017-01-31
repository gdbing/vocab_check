#include "trie.h"

struct node * new_trie_node();
intptr_t mask(char c);
int char_to_index(char c);

char* knf = "key not found";

int insert(const char * key, const char * desc, struct node * n)
{
	if (key[0] == '\0') {
		n->desc = malloc(strlen(desc)*sizeof(char));
		strcpy(n->desc, desc);
		n->childmask |= mask('\0');
		return 1;
	}

	unsigned int i = char_to_index(key[0]);
	if (!(n->childmask & mask(key[0]))) {
		n->childmask |= mask(key[0]);
		n->children[i] = new_trie_node();
	}
	return insert(key+1, desc, n->children[i]);
}


char * lookup(const char * key, struct node * n)
{
	if (key[0] == '\0') {
		if (mask('\0') & n->childmask)
			return n->desc;

		return knf;
	}

	if (mask(key[0]) & n->childmask) {
		return lookup(key+1, n->children[char_to_index(key[0])]);
	} else {
		return knf;
	}
}

struct node * trie_init()
{
	return new_trie_node();
}


struct node * new_trie_node()
{
	struct node * n = malloc(sizeof(struct node));
	n->childmask = 0;
	for (int i = 0; i < NUM_CHARS; i++) {
		n->children[i] = (struct node *)0;
	}
	n->desc = (char *)0;
	return n;
}

int char_to_index(char c)
{
	if (c == '\0')
		return NUM_CHARS;
	if (c >= 'a' && c <= 'z')
		return ((int)c - (int)'a');
	if (c >= 'A' && c <= 'Z')
		return ((int)c - (int)'A');
	if (c == ' ')
		return 26;
	return 27;
}

intptr_t mask(char c)
{
	return 1 << char_to_index(c);
}
