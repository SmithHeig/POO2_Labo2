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
#define TEST_ENABLE 1
using namespace std;

/* 
 * 
 */
int main(int argc, char** argv) {

    /*
    string test("JELLE");
    
        if(test == "JELLE")
            std::cout << std::endl << "IS";
            if(test == "JELLA")
            std::cout << std::endl << "ISID---";
    */
    
    /* TESTS CONSTRUCTORS */
    
    cout << "\nTESTS CONSTRUCTORS" << endl;
    String sNull;
    std::cout << "sNull: " << sNull << "(" << sNull.lenght() << ")" << endl;
    String sIntPos(123);
    std::cout << "sIntPos: " << sIntPos << "(" << sIntPos.lenght() << ")" << endl;
    String sIntNeg(-123);
    std::cout << "sIntNeg: " << sIntNeg << "(" << sIntNeg.lenght() << ")" << endl;
    String sBool(true);
    std::cout << "sBool: " << sBool << "(" << sBool.lenght() << ")" << endl;
    String sRealPos(2.123);
    std::cout << "sRealPos: " << sRealPos << "(" << sRealPos.lenght() << ")" << endl;
    String sRealNeg(-2.123);
    std::cout << "sRealNeg: " << sRealNeg << "(" << sRealNeg.lenght() << ")" << endl;
    String sUnsignPos((unsigned int) 1234);
    std::cout << "sUnsignPos: " << sUnsignPos << "(" << sUnsignPos.lenght() << ")" << endl;
    String sUnsignNeg((unsigned int) -1234);
    std::cout << "sUnsignNeg: " << sUnsignNeg << "(" << sUnsignNeg.lenght() << ")" << endl;
    String sChar('Q');
    std::cout << "sChar: " << sChar << "(" << sChar.lenght() << ")" << endl;
    String sCharPtr("Test CharPtr");
    std::cout << "sCharPtr: " << sCharPtr << "(" << sCharPtr.lenght() << ")" << endl;
    
    // constructeur par copie
    String cString(sCharPtr);
    std::cout << "cString: " << cString << "(" << cString.lenght() << ")" << endl;
    
    // Test chaines vides
    String strNullChar('\0');
    std::cout << "strNullChar: " << strNullChar << "(" << strNullChar.lenght() << ")" << endl;
    String strNullCharPtr1("");
    std::cout << "strNullCharPtr1: " << strNullCharPtr1 << "(" << strNullCharPtr1.lenght() << ")" << endl;
    String strNullCharPtr2("\0");
    std::cout << "strNullCharPtr2: " << strNullCharPtr2 << "(" << strNullCharPtr2.lenght() << ")" << endl;
    
    /* TESTS .at(), [] */
    cout << endl << "TESTS .at(), []" << endl;
    String sTestAt("Hello");
    std::cout << "sTestAt: " << sTestAt << "(" << sTestAt.lenght() << ")" << endl;
    sTestAt.at(2)++;
    std::cout << "sTestAt: " << sTestAt << "(" << sTestAt.lenght() << ")" << endl;
    sTestAt[3]++;
    std::cout << "sTestAt: " << sTestAt << "(" << sTestAt.lenght() << ")" << endl;
    try{
        cout << "Test depassement de la fonction .at():" << endl;
        sTestAt.at(sTestAt.lenght() + 1);
    } catch(const exception& e){
        cout << e.what() << endl;
    }
    
    
            
    
    
    
    /*
    String s222;
    std::cout << endl << "Type your string : ";
    std::cin >> s222;
    std::cout << std::endl << "IS :: " << s222 << endl << endl;
    const char c = s222.at(1);
    cout << c   << endl;
    cout << s222[1]   << endl;
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

