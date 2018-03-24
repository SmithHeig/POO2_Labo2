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

    
    
    String s222;
    std::cout << "Type your string : ";
    std::cin >> s222;
    std::cout << std::endl << "IS" << s222 << endl << endl;
    
   
    
    String swswrdrew("");
    cout << swswrdrew << endl << endl;
    String sal('h');
    cout << sal << endl;
    sal = 'w';
    cout << sal << endl << endl;
    
    String s2("HELLO");
    cout << s2 << endl;
    s2 = "SALUT";
    cout << s2 << endl << endl;
    
    char& tmp = s2.at(2);
    cout << tmp << endl;
    tmp ++;
    cout << tmp << endl;
    cout << s2 << endl;
    
    s2 = tmp;
    cout << s2 << endl;

    int i = 21;
    String s(i);
    
    cout << s << "\n";
    
    s.append("FINAL  ");
    cout << s << "\n";
    
    //s.append(s.getPtr());
    cout << s << "\n\nFIXME\n";
    // fixme
    s.set(s);
    cout << s << "\n";
    s.set(s.at(1));
    
    //s.set(s.getPtr(1));
    cout << s << "\n";
    /*
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
    
    char& ch = s.at(3);
    cout << ch << "\n";
    ch++;
    cout << ch << "\n";
    
    
    string ser = "Hello";
    ser = ser.c_str();
    
    
    
    
    cout << ser << "\n";
    */
    return 0;
}

