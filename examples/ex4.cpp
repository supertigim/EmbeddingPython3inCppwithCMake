#include <iostream>
#include "pyhelper.h"

int main(int argc, char* argv[]) {	
	CPyInstance pInstance(argc, argv);

	if(Py_IsInitialized()){
	
		CPyObject p = PyLong_FromLong(50);
		std::cout << "Value =  " << PyLong_AsLong(p) << std::endl;
	}

	return 0;
}