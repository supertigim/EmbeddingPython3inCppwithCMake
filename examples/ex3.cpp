#include <iostream>
#include <Python.h>

int main(int argc, char* argv[]){
	wchar_t** wargv = new wchar_t*[argc];
	for (int i = 0; i < argc; ++i) {
		wchar_t* arg = Py_DecodeLocale(argv[i], nullptr);
		wargv[i] = arg;
	}

	Py_Initialize();
	
	if(Py_IsInitialized()){

		PyRun_SimpleString("import sys");
		PyRun_SimpleString("sys.path.append(\".\")");

		PyObject* mydef = PyImport_ImportModule("ex_python_funcs");
		if(mydef){
			PyObject* pFunc = PyObject_GetAttrString(mydef, "getInteger");
			if(pFunc && PyCallable_Check(pFunc)){
				PyObject* pValue = PyObject_CallObject(pFunc, nullptr);
				if(pValue){
					std::cout << "C++: getInteger() = " << PyLong_AsLong(pValue) << std::endl;
					Py_XDECREF(pValue);
				}
				Py_XDECREF(pFunc);
			}
			else{
				std::cout << "ERROR: function getInteger()" << std::endl;
			}

			Py_XDECREF(mydef);
		}
		
		Py_Finalize();
	}
	delete[] wargv;
    wargv = nullptr;
	return 0;
}