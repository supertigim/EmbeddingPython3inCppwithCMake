#include <iostream>
#include <random>

#include "pyhelper.h"

void myClass(int i_size, int* inputs) {
    CPyObject mydef = PyImport_ImportModule("ex_class");

    if (mydef) {
        CPyObject myClass = PyObject_GetAttrString(mydef, "MyClass");

        if (myClass) {
            CPyObject instance = PyObject_CallObject(myClass, nullptr);

            if (instance) {
                CPyObject returnSum = PyObject_CallMethod(instance, "Sum", nullptr);
                if (returnSum) {
                    //double result = PyFloat_AS_DOUBLE(returnSum.getObject()); //find using Search . Type this "PyFloat_"
                    double result = PyFloat_AS_DOUBLE((PyObject*)returnSum); //find using Search . Type this "PyFloat_"
                    std::cout << "[C++] sum = " << result << std::endl;
                }
                else std::cout << "[C++] No Sum Method or Error" << std::endl;

                CPyObject returnAvr = PyObject_CallMethod(instance, "Avr","i", 4);
                if (returnAvr) {
                    double result = PyFloat_AS_DOUBLE((PyObject*)returnAvr); //find using Search . Type this "PyFloat_"
                    std::cout << "[C++] Avr = " << result << std::endl;
                }
                else std::cout << "[C++] No Avr Method or Error" << std::endl;

                CPyObject nParam = PyTuple_New(i_size);
                for (int i = 0; i < i_size; ++i) {
                    PyObject *item = Py_BuildValue("i", inputs[i]);
                    PyTuple_SetItem(nParam, i, item);
                }

                if (nParam) {
                    CPyObject returnPredict = PyObject_CallMethod(instance, "Predict", "(O)", (PyObject*)nParam);
                    if (returnPredict) {
                        int m_numCols = PyObject_Length(returnPredict);
                        std::cout << "[C++] the size of the array returned = " << m_numCols << std::endl;
                        for (int j = 0; j < m_numCols; ++j) {
                            CPyObject piItem = PySequence_GetItem(returnPredict, j);
                            if(piItem) {
                                double value = PyFloat_AS_DOUBLE(piItem.getObject());
                                std::cout << "[C++] Predict[" << j << "] : " << value << std::endl;
                            }
                        }
                    }
                    else std::cout << "[C++] No Predict Method or Error" << std::endl;
                }
                else std::cout << "[C++] No nParam or Error" << std::endl;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    CPyInstance pInstance(argc, argv);

    std::wcout << "GetProgramName: " << Py_GetProgramName() << std::endl;

    if (Py_IsInitialized()) {
        PySys_SetArgv(argc, pInstance.argv());
        std::wcout << "GetPath: " << Py_GetPath() << std::endl;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, 99);

        const int i_size = 4;
        int inputs[i_size];
        for (int i = 0; i < i_size; ++i) {
            inputs[i] = dis(gen);
        }
        myClass(i_size, inputs);
    }

    return 0;
}