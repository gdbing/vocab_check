init: trie.o init.o init_test.o
	gcc -o init trie.o init.o init_test.o -ggdb

lookup: trie.o lookup.o lookup_test.o
	gcc -o lookup trie.o lookup.o lookup_test.o -ggdb

trie.o: trie.h trie.c
	gcc -c trie.c -ggdb

init.o: init.h init.c trie.h
	gcc -c init.c -ggdb

lookup.o: lookup.h lookup.c trie.h baked_data.c
	gcc -c lookup.c baked_data.c -ggdb

init_test.o: init_test.c trie.h init.h
	gcc -c init_test.c -ggdb

lookup_test.o: lookup_test.c trie.h lookup.h
	gcc -c lookup_test.c -ggdb

binaries=init lookup

all: clean $(binaries)

clean:
	rm -f $(binaries) *.o
