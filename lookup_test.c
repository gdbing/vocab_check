#include "trie.h"
#include "lookup.h"
#include <stdio.h>

int main(int argc, char ** argv)
{
	if (argc > 1)
		printf("%s: %s\n", argv[1], lookup_val(lookup_key(argv[1])));
	else
		printf("usage: lookup key\n");

}
