/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   String.h
 * Author: Jeremie
 *
 * Created on 15. mars 2018, 14:19
 */

#include <string.h>
#include <iostream>
#include <stdio.h>

#ifndef STRING_H
#define STRING_H

class String {
public:
    String();
    String(const String& orig);
    
    String(const char* str){
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
        
    }
    
    virtual ~String(){
        delete[] str;
    };
    
    friend std::ostream& operator <<(std::ostream& lhs, const String& rhs);
    
private:
    char* str;
    size_t len;
    size_t capacity;    
    
};

#endif /* STRING_H */

