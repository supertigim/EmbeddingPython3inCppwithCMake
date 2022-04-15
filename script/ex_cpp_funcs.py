# -*- coding: utf-8 -*-
import arnav

def main():
    print('[Python] function main(...) ')
    val = arnav.foo()
    print("[Python] arnav.foo() returned ", val)

    val = arnav.show(val*20+80)
    print("[Python] arnav.show(val*20+80): return value is ", val)
    

if __name__ == "__main__":
    main()

