program: trietest.o trie.o
	gcc -o program trietest.o trie.o

trietest.o: trietest.c trie.h
	gcc -c trietest.c

trie.o: trie.c trie.h
	gcc -c trie.c
