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
    
//** METHODS **//
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
     * Obtient un référence sur un caratère de la String. Sa modification modifie la string
     * @param pos Position du caractère (de 0 à length -1)
     * @return référence sur un caractère de la string
     * @throw invalid_argument si la position n'est pas correcte
     */
    char& at(size_t pos);
    /**
     * Obtient un caratère de la String
     * @param pos Position du caractère (de 0 à length -1)
     * @return valeur du caractère
     * @throw invalid_argument si la position n'est pas correcte
     */
    char at(size_t pos) const;
    
    /**
     * Compare lexicographiquement si la string est égal à une autre string
     * @param s element à comparer
     * @return true si c'est égal autement false
     */
    bool equals(const String& s) const;
    /**
     * Compare lexicographiquement si la string est égal à une autre chaine de caractères
     * @param s element à comparer
     * @return true si c'est égal autement false
     */
    bool equals(const char* s) const;
    
     /**
     * Compare lexicographiquement si la string est diffrente à une autre string
     * @param s element à comparer
     * @return false si c'est égal autement true
     */
    bool notEquals(const String& s) const;
    /**
     * Compare lexicographiquement si la string est diffrente à une autre chaine de caractères
     * @param s element à comparer
     * @return false si c'est égal autement true
     */
    bool notEquals(const char* s) const;
    
    /**
     * Céer une string avec une sous chaine de caractère de la string instanciés délimité par une borne inf et supp inclues (commece à 0 et fini à stlen(), doit avoir au moins 1 caractère)
     * @param start début de la sous chaine de caractères (borne inférieur)
     * @param end fin de la sus chaine de caractère (borne supérieur)
     * @return une nouvelle string avec la sous chaine de caractère
     * @throw invalid_argument si les bornes ne sont pas correcte
     */
    String substr(size_t start, size_t end) const;
    
    /**
     * Concatène une string à la fin de la string courante (la modifie)
     * @param s string à ajouter à la string courrante
     * @return réference sur la string courrante (modifiée)
     */
    String& append(const String& s);
    /**
     * Concatène une chaine de caractères à la fin de la string courante (la modifie)
     * @param s chaine de caractères à ajouter à la string courrante
     * @return réference sur la string courrante (modifiée)
     */
    String& append(const char* s);
    
    /**
     * Concatène une string à la fin de la string courante dans une nouvelle string
     * @param s string à ajouter à la string courrante
     * @return une nouvelle string avec les valeurs des 2 elements concaténés
     */
    String plus(const String& s) const;
    /**
     * Concatène une chaine de caractères à la fin de la string courante dans une nouvelle string
     * @param s chaine de caractères à ajouter à la string courrante
     * @return une nouvelle string avec les valeurs des 2 elements concaténés
     */
    String plus(const char* s) const;
    
    /**
     * Affecte une nouvelle valeur à la string courante à partir d'une string
     * @param s valeur afectée à la string courante
     * @return réference sur la string courrante (modifiée)
     */
    String& set(const String& s);
    /**
     * Affecte une nouvelle valeur à la string courante à partir d'une chaine de caractère
     * @param s valeur afectée à la string courante
     * @return réference sur la string courrante (modifiée)
     */
    String& set(const char* s);
    
//** SURCHARGE OPERATEURS **//
    /**
     * Surcharge opérateur =
     * Affecte une nouvelle valeur à la string courante à partir d'une string
     * @param s valeur afectée à la string courante
     * @return réference sur la string courrante (modifiée)
     */
    String& operator =(const String s);
    /**
     * Surcharge opérateur =
     * Affecte une nouvelle valeur à la string courante à partir d'une chaine de caractère
     * @param s valeur afectée à la string courante
     * @return réference sur la string courrante (modifiée)
     */
    String& operator =(const char* s);

    /**
     * Compare lexicographiquement si la string est égal à une autre string
     * @param s element à comparer
     * @return true si c'est égal autement false
     */
    bool operator == (const String& s) const;
    /**
     * Compare lexicographiquement si la string est égal à une autre chaine de caractères
     * @param s element à comparer
     * @return true si c'est égal autement false
     */
    bool operator == (const char* s) const;
    /**
     * Compare lexicographiquement si la string est diffrente à une autre string
     * @param s element à comparer
     * @return false si c'est égal autement true
     */
    bool operator != (const String& s) const;

    /**
     * Compare lexicographiquement si la string est diffrente à une autre chaine de caractères
     * @param s element à comparer
     * @return false si c'est égal autement true
     */
    bool operator != (const char* s) const;

    /**
     * Concatène une string à la fin de la string courante (la modifie)
     * @param s string à ajouter à la string courrante
     * @return réference sur la string courrante (modifiée)
     */
    String& operator += (const String& s);
    /**
     * Concatène une chaine de caractères à la fin de la string courante (la modifie)
     * @param s chaine de caractères à ajouter à la string courrante
     * @return réference sur la string courrante (modifiée)
     */
    String& operator += (const char* s);

    /**
     * Concatène une string à la fin de la string courante dans une nouvelle string
     * @param s string à ajouter à la string courrante
     * @return une nouvelle string avec les valeurs des 2 elements concaténés
     */
    String operator + (const String& s) const;
    /**
     * Concatène une chaine de caractères à la fin de la string courante dans une nouvelle string
     * @param s chaine de caractères à ajouter à la string courrante
     * @return une nouvelle string avec les valeurs des 2 elements concaténés
     */
    String operator + (const char* s) const;

    /**
     * Obtient un référence sur un caratère de la String. Sa modification modifie la string
     * @param pos Position du caractère (de 0 à length -1)
     * @return référence sur un caractère de la string
     * @throw invalid_argument si la position n'est pas correcte
     */
    char operator [](size_t pos) const;
    /**
     * Obtient un caratère de la String
     * @param pos Position du caractère (de 0 à length -1)
     * @return valeur du caractère
     * @throw invalid_argument si la position n'est pas correcte
     */
    char& operator[](size_t pos);
    
    /*
    operator const char*(){
        std::cout << "\nGET CAST\n";
        return getPtr();
    }
     * */
    
    /**
     * Ecriture de la string dans le flux
     * @param s flux d'écriture
     */
    friend std::ostream& operator <<(std::ostream& lhs, const String& rhs);
    /**
     * Lecture du flux et affectation d'une ligne dans une string (lecture jusqu'au premier \n)
     * @param s flux de lecure
     */
    friend std::istream& operator>>(std::istream &is, String& bignum);
    
private:
    /**
     * Initalise la varialve str à une valeur avec le \0 comme dernier caractère
     * @param s Valeur que prend str
     */
    void init(const char* s);
    

};

#endif /* STRING_H */

