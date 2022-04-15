//#include <stdio.h>
#include <iostream>
#include <Python.h>

int main(int argc, char* argv[]){
	wchar_t** wargv = new wchar_t*[argc];
	for (int i = 0; i < argc; ++i) {
		wchar_t* arg = Py_DecodeLocale(argv[i], nullptr);
		wargv[i] = arg;
	}
	Py_SetProgramName(wargv[0]);
	Py_Initialize();

	if(Py_IsInitialized()){
	
		PyObject* pValue = PyLong_FromLong(5);

		if(!pValue){
			std::cout << "Error" << std::endl;
		}
		else{
			std::cout << "Value = " << PyLong_AsLong(pValue) << std::endl;
			Py_DECREF(pValue);
		}

		Py_Finalize();
	}

	delete[] wargv;
    wargv = nullptr;
	return 0;
}