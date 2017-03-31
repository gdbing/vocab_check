#include <Python.h>
#include <stdio.h>
#include "trie.h"
#include "init.h"

static char module_docstring[] = "This module provides an interface to create a static \"skinny\" trie.";
static char insert_docstring[] = "args: (string key, string val) insert a key value pair.";
static char serialize_docstring[] = "args: (string file_path) serialize the trie.";

static PyObject * insert_init(PyObject *self, PyObject *args);
static PyObject * serialize_init(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
	{"insert", insert_init, METH_VARARGS, insert_docstring},
	{"serialize", serialize_init, METH_VARARGS, serialize_docstring},
	{NULL, NULL, 0, NULL}
};

wide_trie * wt;

PyMODINIT_FUNC init_init(void)
{
	PyObject *m = Py_InitModule3("_init", module_methods, module_docstring);

	if (m == NULL)
		return;

	wt = init_trie();
	printf("inited trie\n");
}

static PyObject * insert_init(PyObject *self, PyObject *args)
{
	const char *key;
	const char *val;

	if (!PyArg_ParseTuple(args, "ss", &key, &val))
		return NULL;

	insert(key, val, wt);

	PyObject *ret = Py_BuildValue( "s", "inserted" );
	return ret;
}

static PyObject * serialize_init(PyObject *self, PyObject *args)
{
	const char *file;

	if (!PyArg_ParseTuple(args, "s", &file))
		return NULL;

	skinny_trie * st = pack_trie(wt);
	printf("%s\n", file);
	FILE * fp = fopen(file, "w");
	serialize_trie(st, fp);

	PyObject *ret = Py_BuildValue( "s", "serialized" );
	return ret;
}
