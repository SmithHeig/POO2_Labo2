/* POO2:   Labo14
 * File:   cstring.cpp
 * Author: James, Jeremie
 *
 * Created on 15. mars 2018, 14:17
 * 
 * Implémentation de la classe String
 */

#include <cstring>
#include <cstdio>

#include "cstring.h"

String::String() throw (std::bad_alloc){
    init("\0");
}

String::String(const String& orig) throw (std::bad_alloc){
    init(orig.str);
}
String::String(const char* s) throw (std::bad_alloc){
    init(s);
}
String::String(char c) throw (std::bad_alloc){
    char buf[2];
    snprintf(buf, 2, "%c", c); 
    init(buf);
}
 

String::String(bool bln) throw (std::bad_alloc){    
    if(bln)
        init("true");
    else
        init("false");
}

String::String(unsigned int n) throw (std::bad_alloc){
    // Récupération du nombre de paramètre, pas besoin de tester le type de retour car il serat toujours > 0
    int nbChar = snprintf(nullptr, 0, "%u", n );
    char buf[nbChar + 1];
    snprintf(buf, nbChar + 1, "%u", n); 
    init(buf);
}

String::String(int n) throw (std::bad_alloc){
    // Récupération du nombre de paramètre, pas besoin de tester le type de retour car il serat toujours > 0
    int nbChar = snprintf(nullptr, 0, "%d", n );
    char buf[nbChar + 1];
    snprintf(buf, nbChar + 1, "%d", n); 
    init(buf);
} 

String::String(double n) throw (std::bad_alloc){
    // Récupération du nombre de paramètre, pas besoin de tester le type de retour car il serat toujours > 0
    int nbChar = snprintf(nullptr, 0, "%f", n );
    char buf[nbChar + 1];
    snprintf(buf, nbChar + 1, "%f", n);

    // Supression des derniers 0
    size_t i = 0;
    while(buf[nbChar - i - 1] == '0')
        buf[nbChar - (i++) - 1] = '\0';

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

String String::substr(size_t start, size_t end) const throw (std::invalid_argument, std::bad_alloc){
    size_t len = lenght();
    
    if(start >= end || end > len)
        throw std::invalid_argument("invalid_argument substr():  positions not correct");
    
    char tmp[end - start + 1];
    snprintf(tmp, end - start + 1, str + start);
    
    String ret(tmp); 
    return ret;
}

char String::at(size_t pos) const throw (std::invalid_argument){
    
    if(pos >= lenght())
        throw std::invalid_argument("invalid_argument substr():  positions not correct");
    
    return str[pos];
}

char& String::at(size_t pos) throw (std::invalid_argument){
    if(pos >= lenght())
        throw std::invalid_argument("invalid_argument .at(pos): Positon not correct.");
    
    return str[pos];
}

String& String::set(const String& s) throw (std::bad_alloc){
    set(s.str);
    return *this;
}

String& String::set(const char* s) throw (std::bad_alloc){

    if(s != str){
        delete[] str;
        init(s);
    }
    return *this;
}


bool String::equals(const String& s) const{
    return equals(s.str);
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

String& String::append(const String& s) throw (std::bad_alloc){
    append(s.str);
    return *this;
}

String& String::append(const char* s) throw (std::bad_alloc){        
    String tmp = plus(s);
    delete[] str;
    init(tmp.str);
    return *this;
}

String String::plus(const String& s) const throw (std::bad_alloc){
    return plus(s.str);
}

String String::plus(const char* s) const throw (std::bad_alloc){
    size_t tmpLen = lenght();
    char* tmpbuf = new char[tmpLen + strlen(s) + 1];
    
    strcpy(tmpbuf, str);
    strcat(tmpbuf, s);
    
    String ret(tmpbuf);
    return ret;
}

String& String::operator = (const String s) throw (std::bad_alloc){
    return set(s);
}

String& String::operator = (const char* s) throw (std::bad_alloc){
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

String& String::operator += (const String& s) throw (std::bad_alloc){
    return append(s);
}
String& String::operator += (const char* s) throw (std::bad_alloc){
    return append(s);
}

String String::operator + (const String& s) const throw (std::bad_alloc){
    return plus(s);
}
String String::operator + (const char* s) const throw (std::bad_alloc){
    return plus(s);
}

char& String::operator [] (size_t pos){
    return at(pos);
}

char String::operator [] (size_t pos) const{
    return at(pos);
}

String::operator const char*() const{
        return getPtr();
}

std::istream& operator>>(std::istream &is, String& s){
    s.init("");                // reset la string 
    const int buffSz = 255;     // taille objective (standard vu en SYE). 
    char buff[buffSz]; 
     
    while(is.get(buff, buffSz, '\n'))       // lecture jusqu'au \n
        s.append(buff);
    
    
    is.clear();
    fflush(stdin);

    return is;
}

std::ostream& operator << (std::ostream& lhs, const String& rhs){
    lhs << rhs.str;
    return lhs;
}

void String::init(const char* s) throw (std::bad_alloc){
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}