#ifndef _INIT_TRIE_H_
#define _INIT_TRIE_H_

#include <stdio.h>

wide_trie * init_trie();
skinny_trie * pack_trie(wide_trie *wt);
void serialize_trie(skinny_trie *st, FILE *fp);
int insert(const char *key, const char *val, wide_trie *wt);
// int insert_dup(const char * new_key, const char * key, wide_trie * wt);

#endif
