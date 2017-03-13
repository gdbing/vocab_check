#include "trie.h"
#include "lookup.h"
#include <stdio.h>

int main(int argc, char ** argv)
{
	char * key = malloc (256 * sizeof(char));
	while (1) {
	scanf("%s", key);

	printf("%s: %s\n", key, lookup_val(lookup_key(key)));
	}
}
