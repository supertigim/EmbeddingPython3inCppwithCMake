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

		PyRun_SimpleString("print('Hello World from Embedded Python!!!')");
		
		Py_Finalize();
	}

	std::cout << "C++ is terminated" << std::endl;
	delete[] wargv;
    wargv = nullptr;
	return 0;
}