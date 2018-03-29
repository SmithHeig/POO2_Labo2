/* POO2:   Labo14
 * File:   main.cpp
 * Author: James, Jeremie
 *
 * Created on 15. mars 2018, 14:17
 * 
 * Main de test pour a classe String.
 */


#include <iostream>
#include <stdexcept>
#include <limits>
#include <cstdlib>

#include "cstring.h"

using namespace std;

int main(int argc, char** argv) {   
    
    try{ // En cas d'échéc d'inialisation de sting
    /* TESTS CONSTRUCTORS */
        cout << "\nTESTS CONSTRUCTORS" << endl;
        String sNull;
        cout << "sNull: " << sNull << "(" << sNull.lenght() << ")" << endl;
        
        String sIntPos(123);
        cout << "sIntPos: " << sIntPos << "(" << sIntPos.lenght() << ")" << endl;
        String sIntPos2 = 123;
        cout << "sIntPos2: " << sIntPos2 << "(" << sIntPos2.lenght() << ")" << endl;
        
        String sIntNeg(-123);
        cout << "sIntNeg: " << sIntNeg << "(" << sIntNeg.lenght() << ")" << endl;
        String sIntNeg2 = -123;
        cout << "sIntNeg2: " << sIntNeg2 << "(" << sIntNeg2.lenght() << ")" << endl;
        
        String sBool(true);
        cout << "sBool: " << sBool << "(" << sBool.lenght() << ")" << endl;
        String sBool2 = true;
        cout << "sBool2: " << sBool2 << "(" << sBool2.lenght() << ")" << endl;
        
        String sRealPos(2.123);
        cout << "sRealPos: " << sRealPos << "(" << sRealPos.lenght() << ")" << endl;
        String sRealPos2 = 2.123456;
        cout << "sRealPos2: " << sRealPos2 << "(" << sRealPos2.lenght() << ")" << endl;
        double inf = std::numeric_limits<double>::infinity();
        String sRealPos3(inf);
        cout << "sRealPos3: " << sRealPos3 << "(" << sRealPos3.lenght() << ")" << endl;
        String sRealSci(3.14e-50);
        cout << "sRealSci: " << sRealSci << "(" << sRealSci.lenght() << ")" << endl;
        
        String sRealNeg(-2.1234);
        cout << "sRealNeg: " << sRealNeg << "(" << sRealNeg.lenght() << ")" << endl;
        String sRealNeg2 = -2.1234;
        cout << "sRealNeg2: " << sRealNeg2 << "(" << sRealNeg2.lenght() << ")" << endl;
        
        String sUnsignPos((unsigned int) 1234);
        cout << "sUnsignPos: " << sUnsignPos << "(" << sUnsignPos.lenght() << ")" << endl;
        String sUnsignPos2 = (unsigned int) 1234;
        cout << "sUnsignPos2: " << sUnsignPos2 << "(" << sUnsignPos2.lenght() << ")" << endl;
        
        String sUnsignNeg((unsigned int) -1234);
        cout << "sUnsignNeg: " << sUnsignNeg << "(" << sUnsignNeg.lenght() << ")" << endl;
        String sUnsignNeg2 = (unsigned int) -1234;
        cout << "sUnsignNeg2: " << sUnsignNeg2 << "(" << sUnsignNeg2.lenght() << ")" << endl;
        
        String sChar('Q');
        cout << "sChar: " << sChar << "(" << sChar.lenght() << ")" << endl;
        String sChar2 = 'Q';
        cout << "sChar2: " << sChar2 << "(" << sChar2.lenght() << ")" << endl;
        
        String sCharPtr("Test CharPtr");
        cout << "sCharPtr: " << sCharPtr << "(" << sCharPtr.lenght() << ")" << endl;
        String sCharPtr2 = "Test CharPtr";
        cout << "sCharPtr2: " << sCharPtr2 << "(" << sCharPtr2.lenght() << ")" << endl;


        // constructeur par copie
        String cString(sCharPtr);
        cout << "cString: " << cString << "(" << cString.lenght() << ")" << endl;
        String cString2 = sCharPtr2;
        cout << "cString2: " << cString2 << "(" << cString2.lenght() << ")" << endl;

        // Test chaines vides
        String strNullChar('\0');
        cout << "strNullChar: " << strNullChar << "(" << strNullChar.lenght() << ")" << endl;
        String strNullCharPtr1("");
        cout << "strNullCharPtr1: " << strNullCharPtr1 << "(" << strNullCharPtr1.lenght() << ")" << endl;
        String strNullCharPtr2("\0");
        cout << "strNullCharPtr2: " << strNullCharPtr2 << "(" << strNullCharPtr2.lenght() << ")" << endl;

    /* TESTS String constant */
        cout << endl << "TESTS String constant" << endl;
        const String S_CONST("Hello");
        // S_CONST.append(" ERROR");            // Opéatation impossible car const
        // S_CONST.set(" ERRROR");              // Opéatation impossible car const
        cout << "S_CONST.plus(\" IS OK\"): " << S_CONST.plus(" IS OK") << endl;
        cout << "S_CONST.substr(1,4): " << S_CONST.substr(1,4) << endl;;
        char cConst = S_CONST.at(3);
        cout << "S_CONST.at(3) :" << cConst  << endl;
        cConst++;
        cout << "++S_CONST.at(3) :" << cConst << endl;
        cout << "S_CONST :" << S_CONST << endl;

    /* TESTS .at(), [] */
        cout << endl << "TESTS .at(), []" << endl;
        String sTestAt("Hello");
        cout << "sTestAt: " << sTestAt << "(" << sTestAt.lenght() << ")" << endl;
        sTestAt.at(2)++;
        cout << "sTestAt.at(2)++: " << sTestAt << "(" << sTestAt.lenght() << ")" << endl;
        sTestAt[3]++;
        cout << "sTestAt[3]++: " << sTestAt << "(" << sTestAt.lenght() << ")" << endl;
        try{
            cout << "Test depassement de la fonction .at():" << endl;
            sTestAt.at(sTestAt.lenght() + 1);
        } catch(const exception& e){
            cout << e.what() << endl;
        }


    /* TESTS substr() */
        cout << endl << "TESTS substr()" << endl;
        String sTestSubstr("Hello");
        cout << "sTestSubstr: " << sTestSubstr << "(" << sTestSubstr.lenght() << ")" << endl;
        String sTestSubstr1 = sTestSubstr.substr(0, sTestSubstr.lenght());
        cout << "sTestSubstr1: " << sTestSubstr1 << "(" << sTestSubstr1.lenght() << ")" << endl;
        String sTestSubstr2 = sTestSubstr.substr(1, sTestSubstr.lenght() - 1);
        cout << "sTestSubstr2: " << sTestSubstr2 << "(" << sTestSubstr2.lenght() << ")" << endl;
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
        cout << "testEq1.equals(): " << testEq1.equals(testEq2) << " "  << testEq1.equals("HELLO") << endl;
        cout << "testEq1 ==: " << (testEq1 == testEq2) << " "  << (testEq1 == "HELLO") << endl;
        cout << "testEq1.notEquals(): " << testEq1.notEquals(testEq2) << " "  << testEq1.notEquals("HELLO") << endl;
        cout << "testEq1 ==: " << (testEq1 != testEq2) << " " << (testEq1 != "HELLO") << endl;


    /* TESTS append(), += */
        cout << endl << "TESTS append(), +=" << endl;
        String testApp;
        String testApp2(" + ");
        cout << "testApp: " << testApp << endl;
        cout << "testApp2: " << testApp2 << endl;
        cout << "testApp.append(testApp2): " << testApp.append(testApp2) << endl;
        cout << "testApp.append(\"2\"): " << testApp.append("2") << endl;
        cout << "testApp += testApp2 : " << (testApp += testApp2) << endl;
        cout << "testApp +=\"3\": " << (testApp += "3") << endl;

    /* TESTS plus(), + */
        cout << endl << "TESTS plus(), +" << endl;
        String testPlus("1");
        String testPlus2(" + ");
        cout << "testPlus: " << testPlus << endl;
        cout << "testPlus2: " << testPlus2 << endl;
        cout << "testPlus.plus(testPlus2): " << testPlus.plus(testPlus2) << endl;
        cout << "testPlus.plus(\"2\"): " << testPlus.plus("2") << endl;
        cout << "testPlus + testPlus2 : " << (testPlus + testPlus2) << endl;
        cout << "testPlus +\"3\": " << (testPlus + "3") << endl;
        cout << "testPlus +\"3\" + 1 + \'c\': " << (testPlus + "3" + 1 + 'c') << endl;   
        
    /* TESTS set(), = */
        cout << endl << "TESTS set(), =" << endl;
        String sSet;
        String sSet2("hello");
        cout << "sSet: " << sSet << endl;
        cout << "sSet2: " << sSet2 << endl;
        cout << "sSet.set(sSet2): " << sSet.set(sSet2) << endl;
        cout << "sSet.set(\"re-hello\"): " << sSet.set("re-hello") << endl;
        cout << "sSet = sSet2: " << (sSet = sSet2) << endl;
        cout << "sSet = \"re-hello\": " << (sSet = "re-hello") << endl;
        cout << "sSet = sSet: " << (sSet = sSet) << endl;
        cout << "sSet = sSet.getPtr(): " << (sSet = sSet.getPtr()) << endl;
        cout << "sSet = sSet: " << (sSet = sSet) << endl;
        cout << "sSet = sSet.at(2): " << (sSet = sSet.at(2)) << endl;
        cout << "sSet = '1': " << (sSet = '1') << endl;
        
    /* TESTS enchainement opérateur += +*/
        cout << endl << "TEST enchainement operateur += +" << endl;
        String sEnch("HELLO");
        String sEnch2(" comment ");
        String sEnch3("tu");
        String sEnch4("?");
        sEnch += sEnch2 + "vas-" + sEnch3 + sEnch4 + ':' + 3;
        cout << "sEnch += sEnch2 + \"vas-\" + sEnch3 + sEnch4 + ':' + 3: " << sEnch << endl;

    /* TESTS opérateur cast */
        cout << endl << "TEST operateur cast" << endl;
        String strToCast("Cast me");
        const char* cTestCast = (const char*) strToCast;
        cout << "Cast me == " << cTestCast << endl;
        // const char* cTestCast2 = strToCast;      // Ne compile volontairement pas car l'opérateur est explicite (pas de cast implicite)
        
        
    /* TESTS operateurs flux >>  << */
        cout << endl << "TEST operateurs flux >>  <<" << endl;
        String sFlux, sFlux2;
        cout << "Enter two string: ";
        cin >> sFlux >> sFlux2;
        cout << "You enter1: " << sFlux << endl;
        cout << "You enter2: " << sFlux2 << endl;
        cout << "Re-enter1 a string: ";
        cin >> sFlux;
        cout << "You re-enter: " << sFlux << endl;
        
        
    } catch (const exception& e){
        cout << e.what();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}