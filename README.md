# vocab_check

Vocab checker is a sublime text 3 plugin which works like a reverse spell checker. A spell checker finds combinations of letters which are not found in a dictionary; vocab checker finds words which are in a given list of words which the author wishes to avoid using.

Meant to help writers catch words which make their writing less clear. eg. George Orwell advised to avoid words of non-English origin, Strunk and White offer a list of words and phrases to avoid, eliminating adjectives and adverbs.

TODO:
* mouseover underlined words reveals an explanation
* handle different conjugations of words
* handle affixes

* parse json vocab to trie
* serialize trie to static data

* call functions in C library from python plugin


////////////
for every ' ' in text:
	if c_lib_trie_lookup finds a match
		add the range (' '.position, ' '.position + length) and definition to an array

for every range and definition in an array
	underline the range
	popup definition on hover over range



questions:
	when to run.
		track as you type, like modern spellcheck. it would be nice if we didn't have to run it on the whole text with every keystroke, just relookup the changed part. that seems tricky. also, i hate when spellcheck tries to mess with shit i'm in the middle of working with
		or at invocation

	when to parse JSON vocab list
		as part of running - more dynamic
		as part of compiling C lib


done
trie insert
trie lookup

todo
* parse JSON vocab file. use JSMN https://github.com/zserge/jsmn
* handle some different "types" (nouns, verbs, etc) with different conjugations



// scratch

Trie is especially good at matching arbitrary length sequences of chars
ie if checking "not so fast!", wordkith has to check "not", "not so", "not so fast", "not so fast!", "so", "so fast", "so fast!", "fast" and "fast!"
This makes it trivially easy to check arbitrary length phrases as well as words.

Trie can be a very space inefficient structure. How inefficient it is depends in part on its branching factor, which depends on the character set it is using. A trie which just uses the english alphabet, without cases, has 27 branches (1 per letter and 1 terminal) and a tree may have an average of <2 branches per node, depending on the vocab set. This is super inefficient.

But if we're baking the data anyway, we can pack it together so that nodes overlap, so that they are written in the empty spaces between other nodes.

"packing" is done with a depth first traversal so the skinny trie will be cache friendly for lookups

baking
"const char *" + word_with_underscores_for_spaces_and_symbols = "definition";


http://nullprogram.com/blog/2016/11/15/
