#include <stdio.h>
#include "wide_trie.h"
#include "skinny_trie.h"

void serialize_trie(skinny_trie * st)
{
	size_t len;
	for (len = st->data_len; len > 0; len--) {
		if (st->key_data[len]) {
			len += sizeof(skinny_node)/sizeof(size_t);
			break;
		}
	}

	printf("size_t baked_trie[] = { ");
	for (size_t i = 0; i < len; i++) {
		printf("%ld", st->key_data[i]);
		if (i+1 < len)
			printf(", ");
	}
	printf(" };\n\n");

	printf("const char * baked_vals[] = {\n");
	for (size_t i = 0; i < st->val_count; i++) {
		printf("\t\"%s\"", st->vals[i]);
		if (i+1 < st->val_count)
			printf(",\n");
	}
	printf("};\n");

}

int main(int argc, char** argv)
{
	wide_trie * trie = init_wide();

	insert("dog", "furry dumb", trie);
	insert("do", "or do not, there is no trie", trie);
	insert("dogsbody", "person who performs boring menial tasks", trie);
	insert("ke$ha", "popstar", trie);
	insert("!@#$", "cusses", trie);
	insert("!@#$", "crusses", trie);
	insert("waz crakin", "not much", trie);
	insert("tamra", "hot wife", trie);

	skinny_trie * st = init_skinny(trie);

	serialize_trie(st);
}
