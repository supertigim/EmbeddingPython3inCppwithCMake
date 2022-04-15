#include <iostream>
#include "pyhelper.h"

int main(int argc, char* argv[]) {
	CPyInstance pInstance(argc, argv);

	char filename[] = "ex_script_run.py";

	if(Py_IsInitialized()) {

		// PySys_SetArgv(argc, pInstance.argv());
		
		CPyObject obj = Py_BuildValue("s", filename);
		if(obj){
			FILE *fp = _Py_fopen_obj(obj, "r+");
			if (fp != nullptr) {
				PyRun_SimpleFile(fp, filename);
			}
		}
	}
	return 0;
}