#ifndef LOOKUP_TRIE_H
#define LOOKUP_TRIE_H

extern size_t baked_trie[];
extern const char *baked_vals[];

size_t lookup_key(const char *key);
const char *lookup_val(size_t val_i);

#endif
