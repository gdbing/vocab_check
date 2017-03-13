#ifndef TRIE_H
#define TRIE_H

#include <stdlib.h>

#define NUM_CHARS 28 // a-z + ' ' + 'other'

size_t char_to_index(char c);

typedef struct w_node {
	size_t bit_map;
	struct w_node * children[NUM_CHARS];
	size_t val_i;
} wide_node;

typedef struct {
	wide_node * root;
	char ** vals; /* variable length array of char* to store vals */
	size_t val_size;
	size_t val_count;
} wide_trie;

typedef struct {
	size_t bit_map; /* denotes which children exist, whether val exists */
	size_t children[NUM_CHARS]; /* index location of child in key_data */
	size_t val_i; /* index of val in vals */
} skinny_node;

typedef struct {
	skinny_node * root;
	size_t * key_data;
	size_t data_len;
	char ** vals;
	size_t val_count;
} skinny_trie;

#endif
