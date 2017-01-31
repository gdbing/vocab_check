#include "trie.h"
#include <stdio.h>

int print_tree(struct node * root);

int main (int argc, char ** argv)
{
	struct node * root = trie_init();
	insert("dog", "furry dumb", root);
	insert("do", "or do not, there is no trie", root);
	insert("tamra", "hot wife", root);
	insert("dogsbody", "person who performs boring menial tasks", root);
	insert("ke$ha", "popstar", root);

	char * key = malloc (256 * sizeof(char));
	scanf("%s", key);

	printf("%s: %s\n", key, lookup(key, root));

	printf("intptr_t: %ld, node*: %ld, int: %ld, size_t: %ld, void*: %ld",
		sizeof(intptr_t), sizeof(struct node*), sizeof(int), sizeof(size_t), sizeof(void*));
	// print_tree(root);
}

int print_tree(struct node * root)
{
	struct node * n = root;
	int mask = 1;
	for (int i = 0; i < NUM_CHARS; i++) {
		if (n->childmask & mask) {
			printf("%c", 'a' + i);
			print_tree(n->children[i]);
		}
		mask <<= 1;
	}
	return 1;
}

