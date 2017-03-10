#include <stdio.h>
#include "wide_trie.h"
#include "skinny_trie.h"
#include "baked_data.c"

extern size_t baked_trie[];
extern const char * baked_vals[];

size_t char_to_index(char c)
{
	// if (c == '\0')
	// 	return NUM_CHARS - 1;
	if (c >= 'a' && c <= 'z')
		return (c - 'a');
	if (c >= 'A' && c <= 'Z')
		return ((size_t)c - (size_t)'A');
	if (c == ' ')
		return 26;
	return 27;
}

size_t lookup_r(const char * key, skinny_node * n)
{
	size_t i = char_to_index(key[0]);
	if (i == 26 || i == 27) {
		if ((1 << NUM_CHARS) & n->mask)
			return n->val_i;
	}

	if ((1 << i) & n->mask)
		return lookup_r(key+1, (skinny_node *)&baked_trie[n->children[i]]);
	else
		return 0;
}

const char * lookup(const char * key)
{
	return baked_vals[lookup_r(key, (skinny_node *)&baked_trie[0])];
}


int main(int argc, char ** argv)
{
	char * key = malloc (256 * sizeof(char));
	scanf("%s", key);

	printf("%s: %s\n", key, lookup(key));

}
