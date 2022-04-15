# Embedding Python3 in C++ with CMake  

This project includes several examples of how to embed Python in C++ with CMake. Please be sure that this project was only built and tested on MacOS.  

## Environments  

- MacOS 12.0.1  
- Miniconda 4.12.0  
- CMake 3.22.3

## How to build  

[Miniconda](https://docs.conda.io/en/latest/miniconda.html) or Anaconda is required.

```bash
(base)% conda create -n ep python=3  
(base)% conda activate ep  
(ep)% pip install numpy  
```  

```bash
# before installing gcc, Xcode was already installed which was not sure to affect compilation of the source code. 
(ep)% brew install git cmake gcc

(ep)% git clone EmbeddingPython3inCppwithCMake.git
(ep)% cd EmbeddingPython3inCppwithCMake

(ep)% sh ./build_all.sh
```  

```bash
# python related logs when running cmake 
Python_FOUND:TRUE
Python_VERSION:3.10.4
Python_Development_FOUND:TRUE
Python_LIBRARIES:/usr/local/Caskroom/miniconda/base/envs/ep/lib/libpython3.10.dylib
Python_INCLUDE_DIRS:/usr/local/Caskroom/miniconda/base/envs/ep/include/python3.10
```

Then, go to **./build** directory and run embedding-python-ex1 ~ 8

## Reference  

- [Embedding Python program in a C/C++ code](https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code)  
- [C/C++ 결합, Embedded Python](https://m.blog.naver.com/sogangori/220701662749)  
- [Is there any benefit to using Py_DECREF instead of Py_XDECREF for Python C Extensions?](https://stackoverflow.com/questions/41915305/is-there-any-benefit-to-using-py-decref-instead-of-py-xdecref-for-python-c-exten)  
- [16. Embedding Python in C/C++](https://learning-python.com/class/Workbook/unit16.htm)  
- [Parsing arguments and building values](https://docs.python.org/3/c-api/arg.html)

## License  

MIT  
