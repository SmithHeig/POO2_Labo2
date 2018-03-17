/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   String.cpp
 * Author: Jeremie
 * 
 * Created on 15. mars 2018, 14:19
 */
#include <iostream>
#include "cstring.h"




const char* String::getPtr(size_t begin, size_t end){
    if(begin == 0 || begin > this->lenght() || begin > end){
        std::cout << "\nError: Invalid argument\n";
        throw std::invalid_argument("Matrix size not equal");
    }
    
    return str[pos - 1];
}
char& String::getPtr(int pos){
    if(pos == 0 || pos > this->lenght()){
        std::cout << "\nError: Invalid argument\n";
        throw std::invalid_argument("Matrix size not equal");
    }
    
    return str[pos - 1]
}

void String::set(const String& s){
    set(s.str);
}

void String::set(const char* s){
    delete[] str;
    init(s);
}

unsigned String::lenght() const{
    int len = 0;
    while(str[len] != '\0')
        ++len;
    
    return len;
}

bool String::equals(const String& s) const{
    return this->equals(s.str);
}

bool String::equals(const char* s) const{
    return !((bool) strcmp(str, s));
}


String& String::append(const String& s){
    this->append(s.str);
    return *this;
}

String& String::append(const char* s){
        
    unsigned tmpLen = this->lenght();
    char* tmpbuf = new char[tmpLen + strlen(s) + 1];
    
    strncpy(tmpbuf, str, tmpLen);
    strcpy(tmpbuf + tmpLen, s);
    delete[] str;
    str = tmpbuf;
    return *this;
}


std::ostream& operator << (std::ostream& lhs, const String& rhs){
    /*
    size_t i = 0;
    while(rhs.str[i] != '\0'){
        
        lhs << rhs.str[i++];
    }
    return lhs;
     */
    

    size_t i = 0;
    while(i <= rhs.lenght()){
        if (rhs.str[i]) {
            lhs << rhs.str[i];
        } else {
            lhs << "\\0" << ' ';
        }
     ++i;
    }
    return lhs;
}

