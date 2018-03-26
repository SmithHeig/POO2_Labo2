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

String::String(){
    init("\0");
    // str = new char[1];
    // str[0] = '\0';
}


String::String(const String& orig){
 //       std::cout << "C: String(const String& orig)\n";
        init(orig.str);
}
String::String(const char* s){
        init(s);
 //       std::cout << "C: String(const char* str)\n";
}
String::String(char c){
    char buf[2];
    snprintf(buf, 2, "%c", c); 
    init(buf);
}
 

String::String(bool bln){    
        if(bln)
            init("true");
        else
            init("false");
}

String::String(unsigned int n){
        char tmp[0];
        int nbChar = snprintf(tmp, 0, "%u", n );
        char buf[nbChar + 1];
        snprintf(buf, nbChar + 1, "%u", n); 
        init(buf);
}

String::String(int n){
    char tmp[0];
    int nbChar = snprintf(tmp, 0, "%d", n );
    char buf[nbChar + 1];
    snprintf(buf, nbChar + 1, "%d", n); 
    init(buf);
} 

String::String(double n){
        char tmp[0];
        int nbChar = snprintf(tmp, 0, "%lf", n );
        char buf[nbChar + 1];
        snprintf(buf, nbChar + 1, "%lf", n);
        
        for(int i = 0; i < nbChar; ++i){
            if( buf[nbChar - i - 1] == '0')
                buf[nbChar - i - 1] = '\0';
            else
                break;
        }
        
        init(buf);
}

String::~String(){
    delete[] str;
}

size_t String::lenght() const{
    return strlen(str);
}

const char* String::getPtr() const{
    return str;
}

String String::substr(size_t start, size_t end) const {
    size_t len = this->lenght();
    
    if(start > end || end > len || start >= len)
        throw std::invalid_argument("invalid_argument substr():  positions not correct");
    
    char tmp[end - start + 1];
    snprintf(tmp, end - start + 1, str + start);
    
    String ret(tmp); 
            
    return ret;
}

char String::at(size_t pos) const{
    
     if(pos >= this->lenght()){
        std::cout << "\nError: Invalid argument\n";
        throw std::invalid_argument("Matrix size not equal");
    }
    
    std::cout << "\nAt ASDSASDD\n";
    return str[pos];
}

char& String::at(size_t pos){
    std::cout << "\nAt pas const\n";
    if(pos >= lenght()){
        throw std::invalid_argument("invalid_argument .at(pos): Positon not correct.");
    }
    
    return str[pos];
}

String& String::set(const String& s){
    if(&s != this)
        set(s.str);
    return *this;
}

String& String::set(const char* s){

    if(s != str){
        //std::cout << "JE t'ai set\n";

        delete[] str;
        init(s);
    }
    return *this;
}


bool String::equals(const String& s) const{
    return this->equals(s.str);
}

bool String::equals(const char* s) const{
    return !((bool) strcmp(str, s));
}

bool String::notEquals(const String& s) const{
    return notEquals(s.str);
}
bool String::notEquals(const char* s) const{
    return !equals(s);
}

String& String::append(const String& s){
    this->append(s.str);
    return *this;
}

String& String::append(const char* s){
           
    String tmp = plus(s);
    delete[] str;
    init(tmp.str);
 
    return *this;
}

String String::plus(const String& s) const{
    return this->plus(s.str);
}

String String::plus(const char* s) const{
    
    size_t tmpLen = this->lenght();
    char* tmpbuf = new char[tmpLen + strlen(s) + 1];
    
    strcpy(tmpbuf, str);
    strcat(tmpbuf, s);
    
    String ret(tmpbuf);
    return ret;
}

String& String::operator = (const String s){
    return set(s);
}

String& String::operator = (const char* s){
    return set(s);
}

bool String::operator == (const String& s) const{
    return equals(s);
}
bool String::operator == (const char* s) const{
    return equals(s);
}

bool String::operator != (const String& s) const{
    return notEquals(s);
}
bool String::operator != (const char* s) const{
    return notEquals(s);
}

String& String::operator += (const String& s){
    return append(s);
}
String& String::operator += (const char* s){
    return append(s);
}

String String::operator + (const String& s) const{
    return plus(s);
}
String String::operator + (const char* s) const{
    return plus(s);
}

char& String::operator [] (size_t pos){
    return at(pos);
}

char String::operator [] (size_t pos) const{
    return at(pos);
}


std::istream& operator>>(std::istream &is, String& s){
    /*
    s.init("");                 // reset la string
    const int buffSz = 255;     // taille subjective.
    char buff[buffSz];
    
    while(is.get(buff, buffSz, '\n' ) )// call will fail if '\n' is next. ie. it won't return just '\0'
    {
        s.append(buff);
    }
    return is;
     */
    return is >> s.str;
}

std::ostream& operator << (std::ostream& lhs, const String& rhs){
    
    
    
#if defined TEST_ENABLE && TEST_ENABLE==1
    lhs << rhs.str;
#else
    
       size_t i = 0;
    while(i <= rhs.lenght()){
        if (rhs.str[i]) {
            lhs << rhs.str[i];
        } else {
            lhs << "\\0" << ' ';
        }
     ++i;
    }
#endif
    return lhs;
}



void String::init(const char* s){
    len = strlen(s);
    str = new char[strlen(s) + 1];
    strcpy(this->str, s);
}