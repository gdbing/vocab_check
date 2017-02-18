#include "wide_trie.h"
#include "skinny_trie.h"
#include <stdio.h>

int print_tree(wide_node * root);
void print_skinny();

int main (int argc, char ** argv)
{
	wide_node * root = init_wide();
	insert("dog", "furry dumb", root);
	insert("do", "or do not, there is no trie", root);
	insert("tamra", "hot wife", root);
	insert("dogsbody", "person who performs boring menial tasks", root);
	insert("ke$ha", "popstar", root);
	insert("!@#$", "cusses", root);
	insert("waz crakin", "not much", root);

	init_skinny(root);

	char * key = malloc (256 * sizeof(char));
	scanf("%s", key);
	// print_skinny();
	printf("%s: %s\n", key, lookup_skinny(key));
	// printf("%s: %s\n", key, lookup_wide(key, root));

	// print_tree(root);
}


void print_skinny()
{
	for (size_t i = 0; i < 128; i++) {
		printf("%ld\t", skinny_trie[i]);
		if (!((i+1)%8)) {
			printf("\n");
		}
	}

}
// int print_tree(wide_node * root)
// {
// 	wide_node * n = root;
// 	int mask = 1;
// 	for (int i = 0; i < NUM_CHARS; i++) {
// 		if (n->childmask & mask) {
// 			printf("%c", 'a' + i);
// 			print_tree(n->children[i]);
// 		}
// 		mask <<= 1;
// 	}
// 	return 1;
// }
