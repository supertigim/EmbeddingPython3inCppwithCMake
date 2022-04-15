#include <iostream>
#include "pyhelper.h"

int main(int argc, char* argv[]) {
	CPyInstance pInstance(argc, argv);
	
	if(Py_IsInitialized()) {

		// set current directory
		PySys_SetArgv(argc, pInstance.argv());	
		
		CPyObject pName = PyUnicode_FromString("ex_python_funcs");
		CPyObject pModule = PyImport_Import(pName);

		if(pModule) {
			CPyObject pFunc = PyObject_GetAttrString(pModule, "getInteger");
			if(pFunc && PyCallable_Check(pFunc)){
				CPyObject pValue = PyObject_CallObject(pFunc, NULL);

				std::cout << "C: getInteger() = " << PyLong_AsLong(pValue) << std::endl;
			}
			else {
				std::cout << "ERROR: function getInteger()" << std::endl;
			}
		}
		else {
			std::cout << "ERROR: Module not imported" << std::endl;
		}
	}

	return 0;
}