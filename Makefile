bake: baked_trie.o wide_trie.o skinny_trie.o
	gcc -o bake baked_trie.o wide_trie.o skinny_trie.o -ggdb

baked_trie.o: baked_trie.c wide_trie.h skinny_trie.h
	gcc -c baked_trie.c -ggdb

wide: widetest.o wide_trie.o
	gcc -o wide widetest.o wide_trie.o -ggdb

widetest.o: widetest.c wide_trie.h
	gcc -c widetest.c -ggdb

wide_trie.o: wide_trie.c wide_trie.h
	gcc -c wide_trie.c -ggdb

skinny: skinnytest.o skinny_trie.o wide_trie.o
	gcc -o skinny skinnytest.o skinny_trie.o wide_trie.o -ggdb

skinnytest.o: skinnytest.c skinny_trie.h wide_trie.h
	gcc -c skinnytest.c -ggdb

skinny_trie.o: skinny_trie.c skinny_trie.h wide_trie.h
	gcc -c skinny_trie.c -ggdb

binaries=bake wide skinny baked_trie.o wide_trie.o skinny_trie.o

all: clean $(binaries)

clean:
	rm -f $(binaries) *.o
