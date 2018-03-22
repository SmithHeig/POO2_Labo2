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



/*
char* String::getPtr(size_t begin, size_t end){
    if(begin == 0 || begin > this->lenght() || begin > end){
        std::cout << "\nError: Invalid argument\n";
        throw std::invalid_argument("Matrix size not equal");
    }
    
    return str[pos - 1];
}
 * */
const char* String::getPtr(){
    return str;
}


String String::substr(size_t start, size_t end) {
    size_t len = this->lenght();
    
    if(start > end || end > len || start >= len)
        throw std::invalid_argument("Matrix size not equal");
    
    char tmp[end - start + 1];
    snprintf(tmp, end - start, str + start);
    
    String ret(tmp); 
            
    return ret;
}


char& String::getPtr(size_t pos){
    if(pos >= this->lenght()){
        std::cout << "\nError: Invalid argument\n";
        throw std::invalid_argument("Matrix size not equal");
    }
    
    return str[pos];
}

/*
 char const * String::getPtr(int pos){
    if(pos == 0 || pos > this->lenght()){
        std::cout << "\nError: Invalid argument\n";
        throw std::invalid_argument("Matrix size not equal");
    }
    
    return str + pos - 1;
}
 */

void String::set(const String& s){
    if(&s != this)
        set(s.str);
}

void String::set(const char* s){
    
    char buf[strlen(s) + 1];
    strcpy(buf, s);
    delete[] str;
    init(buf);
}

size_t String::lenght() const{
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
        
    size_t tmpLen = this->lenght();
    char* tmpbuf = new char[tmpLen + strlen(s) + 1];
    
    strncpy(tmpbuf, str, tmpLen);
    strcpy(tmpbuf + tmpLen, s);
    delete[] str;
    str = tmpbuf;
    return *this;
}

String  String::plus(const String& s){
    return this->plus(s.str);
}

String String::plus(const char* s){
    size_t tmpLen = this->lenght();
    char* tmpbuf = new char[tmpLen + strlen(s) + 1];
    
    strncpy(tmpbuf, str, tmpLen);
    strcpy(tmpbuf + tmpLen, s);
    String ret = String(tmpbuf);
    return ret;
}

bool String::cmp(const String& s){
    return (this == &s);
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

