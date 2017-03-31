from distutils.core import setup, Extension

setup(
	ext_modules=[Extension("_init", ["_init.c", "init.c", "trie.c"]),
	             Extension("_lookup", ["_lookup.c", "lookup.c", "trie.c"])
	]
)

# python setup.py build_ext --inplace
