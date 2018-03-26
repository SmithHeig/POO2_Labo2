/* 
 * File:   main.cpp
 * Author: Jeremie
 *
 * Created on 15. mars 2018, 14:17
 */




#include <cstdlib>
#include "cstring.h"
#define TEST_ENABLE 1
using namespace std;

void testChar(const char c){
    std::cout << "THe char caught is: " << c << endl;
}

/* 
 * 
 */
int main(int argc, char** argv) {


/* TESTS CONSTRUCTORS */
    cout << "\nTESTS CONSTRUCTORS" << endl;
    String sNull;
    std::cout << "sNull: " << sNull << "(" << sNull.lenght() << ")" << endl;
    String sIntPos(123);
    std::cout << "sIntPos: " << sIntPos << "(" << sIntPos.lenght() << ")" << endl;
    String sIntNeg(-123);
    std::cout << "sIntNeg: " << sIntNeg << "(" << sIntNeg.lenght() << ")" << endl;
    String sBool(true);
    std::cout << "sBool: " << sBool << "(" << sBool.lenght() << ")" << endl;
    String sRealPos(2.123);
    std::cout << "sRealPos: " << sRealPos << "(" << sRealPos.lenght() << ")" << endl;
    String sRealNeg(-2.123);
    std::cout << "sRealNeg: " << sRealNeg << "(" << sRealNeg.lenght() << ")" << endl;
    String sUnsignPos((unsigned int) 1234);
    std::cout << "sUnsignPos: " << sUnsignPos << "(" << sUnsignPos.lenght() << ")" << endl;
    String sUnsignNeg((unsigned int) -1234);
    std::cout << "sUnsignNeg: " << sUnsignNeg << "(" << sUnsignNeg.lenght() << ")" << endl;
    String sChar('Q');
    std::cout << "sChar: " << sChar << "(" << sChar.lenght() << ")" << endl;
    String sCharPtr("Test CharPtr");
    std::cout << "sCharPtr: " << sCharPtr << "(" << sCharPtr.lenght() << ")" << endl;
    
    // constructeur par copie
    String cString(sCharPtr);
    std::cout << "cString: " << cString << "(" << cString.lenght() << ")" << endl;
    
    // Test chaines vides
    String strNullChar('\0');
    std::cout << "strNullChar: " << strNullChar << "(" << strNullChar.lenght() << ")" << endl;
    String strNullCharPtr1("");
    std::cout << "strNullCharPtr1: " << strNullCharPtr1 << "(" << strNullCharPtr1.lenght() << ")" << endl;
    String strNullCharPtr2("\0");
    std::cout << "strNullCharPtr2: " << strNullCharPtr2 << "(" << strNullCharPtr2.lenght() << ")" << endl;
    
/* TESTS .at(), [] */
    cout << endl << "TESTS .at(), []" << endl;
    String sTestAt("Hello");
    std::cout << "sTestAt: " << sTestAt << "(" << sTestAt.lenght() << ")" << endl;
    sTestAt.at(2)++;
    std::cout << "sTestAt: " << sTestAt << "(" << sTestAt.lenght() << ")" << endl;
    sTestAt[3]++;
    std::cout << "sTestAt: " << sTestAt << "(" << sTestAt.lenght() << ")" << endl;
    try{
        cout << "Test depassement de la fonction .at():" << endl;
        sTestAt.at(sTestAt.lenght() + 1);
    } catch(const exception& e){
        cout << e.what() << endl;
    }
    testChar(sTestAt.at(3));
    testChar(sTestAt.at(4));
    const char c = sTestAt.at(3);
    std::cout << endl;
/* TESTS substr() */
    std::cout << endl << "TESTS substr()" << endl;
    String sTestSubstr("Hello");
    std::cout << "sTestSubstr: " << sTestSubstr << "(" << sTestSubstr.lenght() << ")" << endl;
    String sTestSubstr1 = sTestSubstr.substr(0, sTestSubstr.lenght());
    std::cout << "sTestSubstr1: " << sTestSubstr1 << "(" << sTestSubstr1.lenght() << ")" << endl;
    String sTestSubstr2 = sTestSubstr.substr(1, sTestSubstr.lenght() - 1);
    std::cout << "sTestSubstr2: " << sTestSubstr2 << "(" << sTestSubstr2.lenght() << ")" << endl;
    
    try{
        cout << "Test mauvaise bornes substr():" << endl;
        String sTestSubstr2 = sTestSubstr.substr(1, sTestSubstr.lenght() + 1);
    } catch(const exception& e){
        cout << e.what() << endl;
    }
    
/* TESTS equals(), notEquals(), ==, !=  */
    cout << endl << "TESTS equals(), notEquals(), ==, !=" << endl;
    String testEq1("HELLO");
    String testEq2("hello");
    std::cout << "testEq1.equals(): " << testEq1.equals(testEq2) << " "  << testEq1.equals("HELLO") << endl;
    std::cout << "testEq1 ==: " << (testEq1 == testEq2) << " "  << (testEq1 == "HELLO") << endl;
    std::cout << "testEq1.notEquals(): " << testEq1.notEquals(testEq2) << " "  << testEq1.notEquals("HELLO") << endl;
    std::cout << "testEq1 ==: " << (testEq1 != testEq2) << " " << (testEq1 != "HELLO") << endl;
    
/* TESTS append(), += */
    cout << endl << "TESTS append(), +=" << endl;
    String testApp;
    String testApp2(" + ");
    std::cout << "testApp: " << testApp << endl;
    std::cout << "testApp2: " << testApp2 << endl;
    std::cout << "testApp.append(testApp2): " << testApp.append(testApp2) << endl;
    std::cout << "testApp.append(\"2\"): " << testApp.append("2") << endl;
    std::cout << "testApp += testApp2 : " << (testApp += testApp2) << endl;
    std::cout << "testApp +=\"3\": " << (testApp += "3") << endl;

/* TESTS plus(), + */
    cout << endl << "TESTS plus(), +" << endl;
    String testPlus("1");
    String testPlus2(" + ");
    std::cout << "testPlus: " << testPlus << endl;
    std::cout << "testPlus2: " << testPlus2 << endl;
    std::cout << "testPlus.plus(testPlus2): " << testPlus.plus(testPlus2) << endl;
    std::cout << "testPlus.plus(\"2\"): " << testPlus.plus("2") << endl;
    std::cout << "testPlus + testPlus2 : " << (testPlus + testPlus2) << endl;
    std::cout << "testPlus +\"3\": " << (testPlus + "3") << endl;

/* TESTS set(), = */
    std::cout << endl << "TESTS set(), =" << endl;
    String sSet;
    String sSet2("hello");
    std::cout << "sSet: " << sSet << endl;
    std::cout << "sSet2: " << sSet2 << endl;
    std::cout << "sSet.set(sSet2): " << sSet.set(sSet2) << endl;
    std::cout << "sSet.set(\"re-hello\"): " << sSet.set("re-hello") << endl;
    std::cout << "sSet = sSet2: " << (sSet = sSet2) << endl;
    std::cout << "sSet = \"re-hello\": " << (sSet = "re-hello") << endl;
    
/* TESTS enchainement opérateur += +*/
    std::cout << endl << "TEST enchainement operateur += +" << endl;
    String sEnch("HELLO");
    String sEnch2(" comment ");
    String sEnch3("tu");
    String sEnch4("?");
    sEnch += sEnch2 + "vas-" + sEnch3 + sEnch4;
    std::cout << "sEnch += sEnch2 + \"vas-\" + sEnch3 + sEnch4: " << sEnch << endl;
    
/* TESTS operateurs flux >>  << */
    std::cout << endl << "TEST operateurs flux >>  <<" << endl;
    String sFlux, sFlux2;
    std::cout << "Enter two string: ";
    std::cin >> sFlux >> sFlux2;
    std::cout << "You enter1: " << sFlux << endl;
    std::cout << "You enter2: " << sFlux2 << endl;
    std::cout << "Re-enter a string: ";
    std::cin >> sFlux;
    std::cout << "You re-enter: " << sFlux << endl;
    
  
    return EXIT_SUCCESS;
}

