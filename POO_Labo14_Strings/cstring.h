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

/**
 *  ==  copie ref ou valeurs? Comment comparer 2 ref de string et String char*
 *  gérer tout les types primitifs?
 *  appels ambigus pour les long long long numbers
 *  si on fait 2 delete sur le même objet?
 *  opérateur = avec quels types?
 *  Bien de faire une copie local du buff pour init?
 
 */

#include <cstring>
#include <iostream>

#include <cstdio>
#include <stdexcept>


#ifndef STRING_H
#define STRING_H

class String {
public:
    String();;
    
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
    
    String(unsigned int n){
        initUnisigned((unsigned long long int) n);
    }
      
    String(short n){
        initPrimitvInteger((long long int) n);
    }
    
    String(int n){
        initPrimitvInteger((long long int) n);
    }
    
        
    String(long int n){
        initPrimitvInteger((long long int)n);
    }
    
    String(long long int n){
        initPrimitvInteger(n);
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
    
    size_t lenght() const;
    
    const char* getPtr();
    char& getPtr(size_t pos);
    
    bool equals(const String& s) const;
    bool equals(const char* s) const;
    
    String substr(size_t start, size_t end);
    
    String& append(const String& s);
    String& append(const char* s);
    
    String plus(const String& s);
    String plus(const char* s);
    //String plusInvert();
    
    bool cmp(const String& s);
    
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
        int nbChar = snprintf(tmp, 0, "%lld", n );
        char buf[nbChar + 1];
        snprintf(buf, nbChar + 1, "%lld", n); 
        init(buf);
    }
    
    void initPrimitivReal(const long double n){
        char tmp[0];
        int nbChar = snprintf(tmp, 0, "%f", n );
        char buf[nbChar + 1];
         snprintf(buf, nbChar + 1, "%f", n); 
         init(buf);
    }
    
    void initUnisigned(unsigned long long int n){
        char tmp[0];
        int nbChar = snprintf(tmp, 0, "%llu", n );
        char buf[nbChar + 1];
        snprintf(buf, nbChar + 1, "%llu", n); 
        init(buf);
    }
    
    
private:
    char* str;
    
};

#endif /* STRING_H */

