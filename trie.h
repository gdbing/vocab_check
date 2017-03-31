#ifndef _TRIE_H_
#define _TRIE_H_

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
	skinny_node * root; // should be at &key_data[0]
	size_t * key_data;  // overlapping skinny nodes
	size_t data_len;    // len of key_data
	char ** vals;
	size_t val_count;
} skinny_trie;

#endif
