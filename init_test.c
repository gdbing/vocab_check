#include "trie.h"
#include "init.h"

int main(int argc, char ** argv)
{
	wide_trie * wt = init_trie();

	// insert("key", "val", wt);
	// insert("dog", "furry dumb", wt);
	// insert("do", "or do not, there is no trie", wt);
	// insert("dogsbody", "one who performs menial tasks", wt);

	// insert("aardvark", "aardvark(n)\\n\\tattested: ant bear, ant-bear, antbear\\n\\tunattested: earthpig, earthswine, earthfarrow)", wt);
	// insert("a Capella", "a Capella(n)\\n\\tunattested: mouthglee", wt);

	for (int i = 1; i+1 < argc; i += 2) {
		insert(argv[i], argv[i+1], wt);
	}

	skinny_trie * st = pack_trie(wt);

	FILE * fp = fopen("/Users/graham/repos/wordkithe/baked_data.c", "w");
	serialize_trie(st, fp);
}
