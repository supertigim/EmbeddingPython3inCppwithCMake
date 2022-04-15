#ifndef PYHELPER_H
#define PYHELPER_H
#pragma once

#include <Python.h>

class CPyInstance {
public:
	CPyInstance() : _wargv(nullptr) { Py_Initialize(); }
	CPyInstance(int argc, char* argv[]) { 
		_wargv = new wchar_t*[argc];
		for (int i = 0; i < argc; ++i) {
			wchar_t* arg = Py_DecodeLocale(argv[i], nullptr);
			_wargv[i] = arg;
		}
		Py_SetProgramName(_wargv[0]); // optional but strongly recommended 
		Py_Initialize(); 
	}
	~CPyInstance() { 
		if(_wargv) {
			delete[] _wargv;
			_wargv = nullptr;
		}
		Py_Finalize(); 
	}

	wchar_t** argv() const { return _wargv;}
private:
	wchar_t** _wargv;
};

class CPyObject {
public:
	CPyObject() : _obj(nullptr) {}
	CPyObject(PyObject* obj) : _obj(obj) {}

	~CPyObject() { Release(); }

	void setObject(PyObject* obj) noexcept { _obj = obj; }
	PyObject* getObject() const noexcept { return _obj; }
	
	bool is() const noexcept { return _obj? true : false; }
	operator bool() const noexcept { return _obj? true : false; }

	PyObject* AddRef() {
		if(_obj) Py_INCREF(_obj);	
		return _obj;
	}

	void Release() {
		if(_obj) Py_DECREF(_obj);
		_obj = nullptr;
	}

	inline PyObject* operator ->() const noexcept { return _obj; }
	inline operator PyObject* () const noexcept { return _obj; }

	PyObject* operator = (PyObject* obj) {
		_obj = obj;
		return _obj;
	}

private:
	PyObject* _obj;
};

#endif /* PYHELPER_H */