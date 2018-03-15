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

#include "cstring.h"

String::String() {
}

String::String(const String& orig) {
}

std::ostream& operator << (std::ostream& lhs, const String& rhs){
    size_t i = 0;
    while(rhs.str[i] != '\0'){
        lhs << rhs.str[i++];
    }
    return lhs;
}
