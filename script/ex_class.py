# -*- coding: utf-8 -*-
import numpy as np

class MyClass:
    def __init__(self):            
        self.model = np.random.rand(4,4)*100
        print ("[Python] MyClass instantiated")
        print("[Python] The model is ... ")
        print (self.model)

    def __del__(self):
        print ("[Python] MyClass deleted")
    
    def Sum(self):
        res = np.sum(self.model)
        print("[Python] Sum is ", res)
        return res
    
    def Avr(self, count):      
        res = np.sum(self.model)/count
        print("[Python] Avr is ", res)
        return res

    def Predict(self, markingPatch):
        print("[Python] Predict arg", markingPatch)    
        data = np.asarray( markingPatch)
        print("[Python] arg to numpy array : ", data)
        res = np.dot( data, self.model )
        print("[Python] Predict is ", res)
        return res

def main():
    myclass = MyClass()
    print("[Python] instance", myclass)
    print("[Python] The result of MyClass::Sum is ", myclass.Sum())
    print("[Python] The result of MyClass::Avr is ", myclass.Avr(2))
    print("[Python] The result of MyClass::Predict is ", myclass.Predict([10,11,12,13]))
    del myclass
    
    print('program end')

if __name__ == "__main__":
    main()
