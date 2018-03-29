/* POO2:   Labo14
 * File:   cstring.h
 * Author: James, Jeremie
 *
 * Created on 15. mars 2018, 14:17
 * 
 * Header classe String.
 */


#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <stdexcept>

/**
 * Classe permettant l'initalisation de string (chaine de caractères).
 * Elle offre certaintaines fonctionalités de manipulation.
 * Elle est implémentée suivnt la même logique que la classe std::string (\0 en fin de chaine de caractère.
 * Touts lés opérateurs ont leur équivalent en méthodes public.
 * Nous avons jugé nécéssaire de créer un équivalent de chaque méthode et opérateur sur un String avec un char* pour éviter 
 *  de récréer une String avec l'appelle implicite du constructeur de const char*. Cepandant nous n'avons pas jugé nécéssaire de le faire pour les autres types (appelleau constructeur)
 *  
*/
class String {
        
private:
    char* str;      // Chaine de caractère contenue dans la string (sse términe toujours par un '\0'

public:
//** CONSTUCTORS **//
// Aucun constreur n'est explicite pour permettre de construire facilement et appeler des méthodes depuis les types primitifs de ceux-ci
    
    /**
     * Constructeur sans paramètre. Initalise une chaine avec seulement un '\0'
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String() throw (std::bad_alloc);
    
    /**
     * Constructeur de copie par référence, alloue et set le char* 
     * Fait une copie des valeurs de la string dans une nouvelle string
     * @param orig String à copier
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String(const String& orig) throw (std::bad_alloc);
    
    /**
     * Constructeur avec une chaine de caractère, alloue et set le char* 
     * Attention, initaliser avec '\0' revient au même résultat que d'utiliser le constructeur sans paramètre
     * @param s
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String(const char* s) throw (std::bad_alloc);
    
    /**
     * Contructeur à l'aide d'un caractère, alloue et set le char* 
     * Attention, initaliser avec '\0' revient au même résultat que d'utiliser le constructeur sans paramètre.
     * @param c
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String(char c) throw (std::bad_alloc);
    
    /**
     * Contructeur boolean en text (true, false), alloue et set le char* 
     * @param c
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String(bool bln) throw (std::bad_alloc);
    
    /**
     * Contructeur entier non signé, alloue et set le char* 
     * @param n
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String(unsigned int n) throw (std::bad_alloc);
    
    /**
     * Constucteur entier, alloue et set le char* 
     * @param n
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String(int n) throw (std::bad_alloc);
    
    /**
     * Contructeur réel, alloue et set le char* 
     * N'affiche que les caractères nécéssaire (pas de 0 en trop)
     * @param n
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String(double n) throw (std::bad_alloc);
    
    /**
     * Destructeur,
     * Désaloue le char*
     */
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
    char& at(size_t pos) throw (std::invalid_argument);
    /**
     * Obtient un caratère de la String
     * @param pos Position du caractère (de 0 à length -1)
     * @return valeur du caractère
     * @throw invalid_argument si la position n'est pas correcte
     */
    char at(size_t pos) const throw(std::invalid_argument);
    
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
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String substr(size_t start, size_t end) const throw (std::invalid_argument, std::bad_alloc);
    
    /**
     * Concatène une string à la fin de la string courante (la modifie)
     * @param s string à ajouter à la string courrante
     * @return réference sur la string courrante (modifiée)
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String& append(const String& s) throw (std::bad_alloc);
    /**
     * Concatène une chaine de caractères à la fin de la string courante (la modifie)
     * @param s chaine de caractères à ajouter à la string courrante
     * @return réference sur la string courrante (modifiée)
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String& append(const char* s) throw (std::bad_alloc);
    
    /**
     * Concatène une string à la fin de la string courante dans une nouvelle string
     * @param s string à ajouter à la string courrante
     * @return une nouvelle string avec les valeurs des 2 elements concaténés
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String plus(const String& s) const throw (std::bad_alloc);
    /**
     * Concatène une chaine de caractères à la fin de la string courante dans une nouvelle string
     * @param s chaine de caractères à ajouter à la string courrante
     * @return une nouvelle string avec les valeurs des 2 elements concaténés
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String plus(const char* s) const throw (std::bad_alloc);
    
    /**
     * Affecte une nouvelle valeur à la string courante à partir d'une string
     * @param s valeur afectée à la string courante
     * @return réference sur la string courrante (modifiée)
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String& set(const String& s) throw (std::bad_alloc);
    /**
     * Affecte une nouvelle valeur à la string courante à partir d'une chaine de caractère
     * @param s valeur afectée à la string courante
     * @return réference sur la string courrante (modifiée)
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String& set(const char* s) throw (std::bad_alloc);
    
//** SURCHARGE OPERATEURS **//
    /**
     * Surcharge opérateur =
     * Affecte une nouvelle valeur à la string courante à partir d'une string
     * @param s valeur afectée à la string courante
     * @return réference sur la string courrante (modifiée)
     */
    String& operator =(const String s) throw (std::bad_alloc);
    /**
     * Surcharge opérateur =
     * Affecte une nouvelle valeur à la string courante à partir d'une chaine de caractère
     * @param s valeur afectée à la string courante
     * @return réference sur la string courrante (modifiée)
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String& operator =(const char* s) throw (std::bad_alloc);

    /**
     * Compare lexicographiquement si la string est égal à une autre string
     * @param s element à comparer
     * @return true si c'est égal autement false
     */
    bool operator ==(const String& s) const;
    /**
     * Compare lexicographiquement si la string est égal à une autre chaine de caractères
     * @param s element à comparer
     * @return true si c'est égal autement false
     */
    bool operator ==(const char* s) const;
    /**
     * Compare lexicographiquement si la string est diffrente à une autre string
     * @param s element à comparer
     * @return false si c'est égal autement true
     */
    bool operator !=(const String& s) const;

    /**
     * Compare lexicographiquement si la string est diffrente à une autre chaine de caractères
     * @param s element à comparer
     * @return false si c'est égal autement true
     */
    bool operator !=(const char* s) const;

    /**
     * Concatène une string à la fin de la string courante (la modifie)
     * @param s string à ajouter à la string courrante
     * @return réference sur la string courrante (modifiée)
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String& operator +=(const String& s) throw (std::bad_alloc);
    /**
     * Concatène une chaine de caractères à la fin de la string courante (la modifie)
     * @param s chaine de caractères à ajouter à la string courrante
     * @return réference sur la string courrante (modifiée)
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String& operator +=(const char* s) throw (std::bad_alloc);

    /**
     * Concatène une string à la fin de la string courante dans une nouvelle string
     * @param s string à ajouter à la string courrante
     * @return une nouvelle string avec les valeurs des 2 elements concaténés
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String operator +(const String& s) const throw (std::bad_alloc);
    /**
     * Concatène une chaine de caractères à la fin de la string courante dans une nouvelle string
     * @param s chaine de caractères à ajouter à la string courrante
     * @return une nouvelle string avec les valeurs des 2 elements concaténés
     * @throw Erreur à l'initalisation mémoire du char*
     */
    String operator +(const char* s) const throw (std::bad_alloc);

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
    
    /**
     * Surcharfe de l'opérateur de cast de la string pour obtenir un char*
     * @return la sting en char*
     * @explicit  Doit être appleé explicitement pour ne pas faire de cast non voulus.
     */
    explicit operator const char*() const;
     
    
    /**
     * Ecriture de la string dans le flux
     * @param s flux d'écriture
     */
    friend std::ostream& operator <<(std::ostream& lhs, const String& rhs);
    /**
     * Lecture du flux et affectation d'une ligne dans une string (lecture jusqu'au premier \n)
     * Le contenu de la string est remplacé.
     * Le flux est nettoyé après lécture.
     * Accèpte une string vide (si on appuie directement sur enter
     * @param s flux de lecure
     */
    friend std::istream& operator>>(std::istream &is, String& s);

private:
    /**
     * alloue et set la variable str (char*) à une valeur avec le dernier caractère à '\0'
     * @param s Valeur que prend str
     * @throw Erreur à l'initalisation mémoire du char*
     */
    void init(const char* s) throw (std::bad_alloc);
    
    
};

#endif /* STRING_H */

