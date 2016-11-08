#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')


struct TrieNode {
	struct TrieNode * children[26 + 1]; // a-z and ' '
	char * desc;
};

int insert(const char * key, const char * desc, struct TrieNode * n);
char* lookup(const char * key, struct TrieNode * n);
struct TrieNode * new_trie_node();

char* knf = "key not found";

struct TrieNode myTrie[] = {
	{ { 0,0,0,myTrie+1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 0 },
	{ { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,myTrie+2,0,0,0,0,0,0,0,0,0,0,0 }, 0 },
	{ { 0,0,0,0,0,0,myTrie+3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, "or do not, there is no trie" },
	{ { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, "bark bark" }
};

int main (int argc, char ** argv)
{
	struct TrieNode * root = new_trie_node();
	insert("dog", "furry dumb", root);
	insert("tamra", "hot wife", root);
	insert("dogsbody", "person who performs boring menial tasks", root);

	char * key = malloc (256 * sizeof(char));
	scanf("%s", key);

	printf("%s\n", key);
	printf("%s\n", lookup(key, myTrie));
}

int insert(const char * key, const char * desc, struct TrieNode * n)
{
	if (*key == '\0') {
		n->desc = malloc(strlen(desc)*sizeof(char));
		strcpy(n->desc, desc);
		return 1;
	}

	unsigned int i = CHAR_TO_INDEX(key[0]);
	if (i > 25) {
		return 0;
	} else if (key[0] == ' ') {
		i = 26;
	}

	printf ("%d: 0x%X\n", i, (int)n->children[i]);

	if (!n->children[i]) {
		n->children[i] = new_trie_node();
	}
	return insert(key+1, desc, n->children[i]);
}


char * lookup(const char * key, struct TrieNode * n)
{
	if (*key == '\0' && n->desc) {
		return n->desc;
	} else if (*key == '\0') {
		return knf;
	}

	unsigned int i = CHAR_TO_INDEX(key[0]);
	if (i > 25) {
		return knf;
	} else if (key[0] == ' ') {
		i = 26;
	}

	if (n->children[i]) {
		return lookup(key+1, n->children[i]);
	} else {
		return knf;
	}
}

struct TrieNode * new_trie_node()
{
	struct TrieNode * n = malloc(sizeof(struct TrieNode));
	for (int i = 0; i < 26 + 1; i++) {
		n->children[i] = (struct TrieNode *)0;
	}
	n->desc = (char *)0;
	return n;
}
