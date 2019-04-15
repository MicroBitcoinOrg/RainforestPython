#include <Python.h>

#include "rainforest.h"
#include "rfv2.h"

#if _MSC_VER >= 1500
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
#endif

void RainforestHashV1(const void *input, void *output, int length)
{
    rf256_ctx_t ctx;
    rf256_init(&ctx);
    rf256_update(&ctx, input, length);
    rf256_final(output, &ctx);
}

void RainforestHashV2(const void *input, void *output, int length)
{
    rfv2_hash(output, input, length, NULL, NULL);
}

static PyObject *rainforest_hash_gethash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    int length;
    if (!PyArg_ParseTuple(args, "Si", &input, &length))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    RainforestHashV1((char *)PyBytes_AsString((PyObject*) input), output, length);
#else
    RainforestHashV1((char *)PyString_AsString((PyObject*) input), output, length);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyObject *rainforest_hash_gethash_v2(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    int length;
    if (!PyArg_ParseTuple(args, "Si", &input, &length))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    RainforestHashV2((char *)PyBytes_AsString((PyObject*) input), output, length);
#else
    RainforestHashV2((char *)PyString_AsString((PyObject*) input), output, length);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef RainforestHashMethods[] = {
    { "get", rainforest_hash_gethash, METH_VARARGS, "Returns the rainforest_hash hash." },
    { "get_v2", rainforest_hash_gethash_v2, METH_VARARGS, "Returns the rainforest_hash v2 hash." },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef RainforestHashModule = {
    PyModuleDef_HEAD_INIT,
    "rainforest_hash",
    "...",
    -1,
    RainforestHashMethods
};

PyMODINIT_FUNC PyInit_rainforest_hash(void) {
    return PyModule_Create(&RainforestHashModule);
}

#else

PyMODINIT_FUNC initrainforest_hash(void) {
    (void) Py_InitModule("rainforest_hash", RainforestHashMethods);
}
#endif
