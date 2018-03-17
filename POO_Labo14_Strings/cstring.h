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

#include <cstring>
#include <iostream>

#include <cstdio>
#include <stdexcept>


#ifndef STRING_H
#define STRING_H

class String {
public:
    String(){
        str = new char[1];
        str[0]= '\0';
    };
    
    String(const String& orig){
        init(orig.str);
    }
    
    String(const char* str){
        init(str);
    }
    
    String(bool bln){    
        if(bln)
            init("true");
        else
            init("false");
    } 
    
    
    String(int n){
        initPrimitvInteger((long long int) n);
    }
    
    String(short n){
        initPrimitvInteger((long long int) n);
    }
    
    String(double n){
        initPrimitivReal(n);
    }
    
    String(float n){
        initPrimitivReal((long double) n);
    }
    
    virtual ~String(){
        delete[] str;
    };
    
    unsigned lenght() const;
    
    const char* getPtr();
    char* getPtr(int pos);
    
    bool equals(const String& s) const;
    bool equals(const char* s) const;
    
    String& append(const String& s);
    String& append(const char* s);
    
    void set(const String& s);
    void set(const char* s);
    
    
    friend std::ostream& operator <<(std::ostream& lhs, const String& rhs);
private:
    void init(const char* str){
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }
    
    void initPrimitvInteger(const long long int n){
        char tmp[0];
        int nbChar = snprintf(tmp, 0, "%d", n );
        std::cout << "NB" << nbChar << "\n";
        char buf[nbChar + 1];
        snprintf(buf, nbChar + 1, "%d", n); 
        init(buf);
    }
    
    void initPrimitivReal(const long double n){
        char tmp[0];
        int nbChar = snprintf(tmp, 0, "%f", n );
        char buf[nbChar];
         snprintf(buf, nbChar + 1, "%f", n); 
         init(buf);
    }
    
    
    
private:
    char* str;
    
};

#endif /* STRING_H */

