#include "trie.h"

size_t char_to_index(char c)
{
	if (c == '\0')
		return NUM_CHARS;
	if (c >= 'a' && c <= 'z')
		return (c - 'a');
	if (c >= 'A' && c <= 'Z')
		return ((size_t)c - (size_t)'A');
	if (c == ' ')
		return 26;
	return 27;
}
