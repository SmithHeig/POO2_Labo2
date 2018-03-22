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
    
    unsigned int i = 21;
    String s(i);
    
    cout << s << "\n";
    
    s.append("FINAL  ");
    cout << s << "\n";
    
    s.append(s.getPtr());cout << s << "\nFIXME\n";
    // fixme
    //s.set(s);
    //s.set(s.getPtr());
    s.set(s.getPtr(1));
    cout << s << "\n\n";
    
    cout << s.plus(s) << "\n";
    cout << s << "\n";
    
    String s2 = s;
    cout << s2 << " " << s << "\n";
    String s3("Hello");
    cout << s2.cmp(s) << "\n";
    cout << s2.cmp(s3) << "\n";
    /*
    String s2("Hello");
    
    cout << s << s2 << s.lenght() << "  " << *s.getPtr(2);
    *s.getPtr(2) = 'a';
    cout << "  "  << s.equals(s2);;
    */
    char& ch = s.getPtr(3);
    cout << ch << "\n";
    ch++;
    cout << ch << "\n";
    
    
    string ser = "Hello";
    ser = ser.c_str();
    
    
    
    
    cout << ser << "\n";
    
    return 0;
}

