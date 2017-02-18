program: trietest.o wide_trie.o skinny_trie.o
	gcc -o program trietest.o wide_trie.o skinny_trie.o

trietest.o: trietest.c wide_trie.h skinny_trie.h
	gcc -c trietest.c

wide_trie.o: wide_trie.c wide_trie.h
	gcc -c wide_trie.c

skinny_trie.o: skinny_trie.c skinny_trie.h wide_trie.h
	gcc -c skinny_trie.c

binaries=program wide_trie.o skinny_trie.o trietest.o

all: clean $(binaries)

clean:
	rm -f $(binaries) *.o
