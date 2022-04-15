#include <iostream>
#include "pyhelper.h"

static PyObject* arnav_foo(PyObject* self, PyObject* args) {
	std::cout << "[C++]  arnav_foo() method" << std::endl;
	return PyLong_FromLong(51);
}

static PyObject* arnav_show(PyObject* self, PyObject* args) {
	PyObject *obj;
	if(PyArg_UnpackTuple(args, "", 1, 1, &obj)) {
		std::cout << "[C++] arnav_show(" << PyLong_AsLong(obj) << ")" << std::endl;
	}

	return PyLong_FromLong(0);
}

static struct PyMethodDef methods[] = {
	{ "foo", arnav_foo, METH_VARARGS, "Returns the number"},
	{ "show", arnav_show, METH_VARARGS, "Show a number" },
	{ nullptr, nullptr, 0, nullptr }
};

static struct PyModuleDef modDef = {
	PyModuleDef_HEAD_INIT, "arnav", nullptr, -1, methods, 
	nullptr, nullptr, nullptr, nullptr
};

static PyObject* PyInit_arnav(void) {
	return PyModule_Create(&modDef);
}

int main(int argc, char* argv[]) {
	
	PyImport_AppendInittab("arnav", &PyInit_arnav); // [IMPORTANT] should call this before Py_IsInitialize() 
	
	CPyInstance pInstance(argc, argv);	
	if(Py_IsInitialized()) {
		
		//PySys_SetArgv(argc, pInstance.argv());

		CPyObject obj = Py_BuildValue("s", "ex_cpp_funcs.py");
		if(obj){
			FILE *fp = _Py_fopen_obj(obj, "r+");
			if (fp != nullptr) {
				PyRun_AnyFile(fp, "");
			}
		}
	}

	return 0;
}