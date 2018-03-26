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
        
private:
    char* str;
    size_t len;
    
public:
    //** CONSTUCTORS **//
    String();
    
    String(const String& orig);
    
    String(const char* s);
    
    String(char c);
    
    String(bool bln);
    
    String(unsigned int n);
      
    String(int n);
    
    String(double n);
    
    virtual ~String();
    
    /**
     * Indique la longueur de la chaine de caractère (\0 non compris)
     * @return longueur de la chaine de caractère (\0 non compris)
     */
    size_t lenght() const;
    
    /**
     * Retourne un pointeur sur chaine de caractères non modifiable
     * @return chaien de caractères
     */
    const char* getPtr() const;
    
    /**
     * 
     * @param pos Position du caractère (de 0 à length -1)
     * @return 
     * @throw invalid_argument si la position n'est pas correcte
     */
    char& at(size_t pos);
    char at(size_t pos) const;
    
    bool equals(const String& s) const;
    bool equals(const char* s) const;
    
    String substr(size_t start, size_t end);
    
    String& append(const String& s);
    String& append(const char* s);
    
    String plus(const String& s) const;
    String plus(const char* s) const;
    
    bool cmp(const String& s);
    
    String& set(const String& s);
    String& set(const char* s);
    
    
    String& operator = (const String s);
    String& operator = (const char* s);

    bool operator == (const String& s) const;
    bool operator == (const char* s) const;

    String& operator += (const String& s);
    String& operator += (const char* s);

    String operator + (const String& s) const;
    String operator + (const char* s) const;

    char operator [](size_t pos) const;
    char& operator[](size_t pos);

    
    friend std::ostream& operator <<(std::ostream& lhs, const String& rhs);
    friend std::istream& operator>>(std::istream &is, String& bignum);
private:
    void init(const char* s);
    

};

#endif /* STRING_H */

