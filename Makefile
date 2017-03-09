program: trietest.o wide_trie.o skinny_trie.o
	gcc -o program trietest.o wide_trie.o skinny_trie.o -ggdb

wide: widetest.o wide_trie.o
	gcc -o wide widetest.o wide_trie.o -ggdb

skinny: skinnytest.o skinny_trie.o wide_trie.o
	gcc -o skinny skinnytest.o skinny_trie.o wide_trie.o -ggdb

skinnytest.o: skinnytest.c skinny_trie.h wide_trie.h
	gcc -c skinnytest.c -ggdb

widetest.o: widetest.c wide_trie.h
	gcc -c widetest.c -ggdb

trietest.o: trietest.c wide_trie.h skinny_trie.h
	gcc -c trietest.c -ggdb

wide_trie.o: wide_trie.c wide_trie.h
	gcc -c wide_trie.c -ggdb

skinny_trie.o: skinny_trie.c skinny_trie.h wide_trie.h
	gcc -c skinny_trie.c -ggdb

binaries=wide skinny program wide_trie.o skinny_trie.o trietest.o

all: clean $(binaries)

clean:
	rm -f $(binaries) *.o
