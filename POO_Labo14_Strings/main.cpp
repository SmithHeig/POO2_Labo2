/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jeremie
 *
 * Created on 15. mars 2018, 14:17
 */

#include <cstdlib>
#include "cstring.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    String s(42);
    
    cout << s << "\n";
    
    s.append("final");
    cout << s << "\n";
    
    s.append(s);
    cout << s << "\n";
    /*
    String s2("Hello");
    
    cout << s << s2 << s.lenght() << "  " << *s.getPtr(2);
    *s.getPtr(2) = 'a';
    cout << "  "  << s.equals(s2);;
    */
    
    
    
    
    return 0;
}

