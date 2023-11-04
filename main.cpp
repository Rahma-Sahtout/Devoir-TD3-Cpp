//exercice 1
#include<iostream>
#include <cmath>
#include <complex>
using namespace std;

class Complex{
private:
   double reel;
    double imag;
public:
    Complex(double re,double im ): reel(re) , imag(im){}
    Complex addition(Complex autre){
        return Complex(reel + autre.reel , imag + autre.imag);
    }
    Complex soustraction(Complex autre){
        return Complex(reel-autre.reel , imag-autre.reel);
    }
    Complex multiplication(Complex autre){
        double nmbreel=(reel*autre.reel) + (imag*autre.imag);
        double nmbimag= (reel*autre.imag) + (imag*autre.reel);
        return Complex(nmbreel,nmbimag);
    }
    Complex division(Complex autre ){
        double denom= pow(autre.reel, 2)+ pow(autre.imag, 2);
        double nmbreel=(reel*autre.reel + imag*autre.imag)/denom;
        double nmbimag= (reel*autre.imag + imag*autre.reel)/denom;
        return Complex(nmbreel,nmbimag);
    }
    void display (){
        cout<<reel<<"+"<<imag<<"i"<<endl;
    }
};
int main (){
    double reel1,reel2,imag1,imag2;
    cout<< "entrez la partie reel du premier nombre complex ";
    cin>>reel1;
    cout<< "entrez la partie imaginaire du premier nombre complex ";
    cin>>imag1;
    cout<< "entrez la partie reel du deuxieme nombre complex ";
    cin>>reel2;
    cout<< "entrez la partie imaginaire du deuxieme nombre complex ";
    cin>>imag2;
    Complex results(0,0);
    Complex nombrecomplex1(reel1,imag1);
    Complex nombrecomplex2(reel2,imag2);
   char choix;
    cout<<"entre loperation que vous souhaitez";
    cin>>choix;
    switch (choix) {
        case'1':
            results= nombrecomplex1.addition(nombrecomplex2);break;
        case'2':
            results= nombrecomplex1.soustraction(nombrecomplex2);break;
        case'3':
            results= nombrecomplex1.multiplication(nombrecomplex2);break;
        case'4':
            results= nombrecomplex1.division(nombrecomplex2);break;

        default:
            cout<<"choix invalide"<<endl;
            return 1;
    }
    cout<<"\nresults"<<endl;

   results.display();
    return 0;
}



//Exercice2
#include <iostream>
#include <list>
#include <algorithm>

// Tri à bulle
void triABulle(std::list<int>& liste) {
    bool estTrie = false;
    while (!estTrie) {
        estTrie = true;
        for (auto it = liste.begin(); it != std::prev(liste.end()); ++it) {
            if (*it > *std::next(it)) {
                std::swap(*it, *std::next(it));
                estTrie = false;
            }
        }
    }
}

// Tri par sélection
void triParSelection(std::list<int>& liste) {
    for (auto it = liste.begin(); it != std::prev(liste.end()); ++it) {
        auto minElement = std::min_element(it, liste.end());
        std::iter_swap(it, minElement);
    }
}

// Tri par insertion
void triParInsertion(std::list<int>& liste) {
    for (auto it = std::next(liste.begin()); it != liste.end(); ++it) {
        auto valeurCourante = *it;
        auto position = std::upper_bound(liste.begin(), it, valeurCourante);
        liste.insert(position, valeurCourante);
        liste.erase(it);
    }
}

int main() {
    std::list<int> liste;

    int nombre;
    char continuer;

    do {
        std::cout << "Entrez un entier : ";
        std::cin >> nombre;

        liste.push_back(nombre);

        std::cout << "Voulez-vous continuer (o/n) ? ";
        std::cin >> continuer;
    } while (continuer == 'o' || continuer == 'O');

    std::cout << "Liste initiale : ";
    for (const auto& element : liste) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Tri à bulle
    std::list<int> listeTrieeABulle = liste;
    triABulle(listeTrieeABulle);
    std::cout << "Liste triée avec le tri à bulle : ";
    for (const auto& element : listeTrieeABulle) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Tri par sélection
    std::list<int> listeTrieeParSelection = liste;
    triParSelection(listeTrieeParSelection);
    std::cout << "Liste triée avec le tri par sélection : ";
    for (const auto& element : listeTrieeParSelection) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Tri par insertion
    std::list<int> listeTrieeParInsertion = liste;
    triParInsertion(listeTrieeParInsertion);
    std::cout << "Liste triée avec le tri par insertion : ";
    for (const auto& element : listeTrieeParInsertion) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}






//Exercice 3
#include <iostream>
#include <list>
#include <algorithm>

struct Personne {
    std::string nom;
    std::string prenom;
    int age;
};

bool comparerPersonnes(const Personne& personne1, const Personne& personne2) {
    if (personne1.nom == personne2.nom) {
        return personne1.prenom < personne2.prenom;
    }
    return personne1.nom < personne2.nom;
}

int main() {
    std::list<Personne> listePersonnes;

    char continuer;

    do {
        Personne personne;

        std::cout << "Entrez le nom : ";
        std::cin >> personne.nom;

        std::cout << "Entrez le prénom : ";
        std::cin >> personne.prenom;

        std::cout << "Entrez l'âge : ";
        std::cin >> personne.age;

        listePersonnes.push_back(personne);

        std::cout << "Voulez-vous ajouter une autre personne (o/n) ? ";
        std::cin >> continuer;
    } while (continuer == 'o' || continuer == 'O');

    listePersonnes.sort(comparerPersonnes);

    std::cout << "Liste triée des personnes :\n";
    for (const auto& personne : listePersonnes) {
        std::cout << personne.nom << " " << personne.prenom << ", " << personne.age << " ans\n";
    }

    return 0;
}





//Exercice 4
//1
#include <set>

int main() {
    std::set<int> monSet;
    for (int i = 1; i <= 100; ++i) {
        monSet.insert(i);
    }
    
    // Maintenant, monSet contient tous les entiers de 1 à 100
    
    return 0;
}
//2
#include <set>

bool recherche(const std::set<int>& monSet, int valeur) {
    return monSet.count(valeur) > 0;
}

int main() {
    std::set<int> monSet = {1, 2, 3, 4, 5}; // Exemple d'un ensemble (set) avec quelques valeurs
    
    int valeurRecherchee = 3;
    bool resultat = recherche(monSet, valeurRecherchee);
    
    if (resultat) {
        // La valeur recherchée est présente dans l'ensemble (set)
        // Faites quelque chose ici...
    } else {
        // La valeur recherchée n'est pas présente dans l'ensemble (set)
        // Faites quelque chose ici...
    }
    
    return 0;
}
//3
#include <set>

bool recherche(std::set<int>::const_iterator debut, std::set<int>::const_iterator fin, int valeur) {
    return std::find(debut, fin, valeur) != fin;
}

int main() {
    std::set<int> monSet = {1, 2, 3, 4, 5}; // Exemple d'un ensemble (set) avec quelques valeurs
    
    int valeurRecherchee = 3;
    bool resultat = recherche(monSet.begin(), monSet.end(), valeurRecherchee);
    
    if (resultat) {
        // La valeur recherchée est présente dans l'ensemble (set)
        // Faites quelque chose ici...
    } else {
        // La valeur recherchée n'est pas présente dans l'ensemble (set)
        // Faites quelque chose ici...
    }
    
    return 0;
}
//4
#include <iostream>
#include <algorithm>

template<typename Iterator, typename T>
bool recherche(Iterator debut, Iterator fin, const T& valeur) {
    return std::find(debut, fin, valeur) != fin;
}

int main() {
    std::vector<std::string> monVector = {"Bonjour", "Salut", "Hello", "Hi"};
    std::list<int> maListe = {1, 2, 3, 4, 5};
    float monTableau[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    bool resultatVector = recherche(monVector.begin(), monVector.end(), std::string("Hello"));
    bool resultatListe = recherche(maListe.begin(), maListe.end(), 3);
    bool resultatTableau = recherche(std::begin(monTableau), std::end(monTableau), 4.4);

    if (resultatVector) {
        std::cout << "La valeur recherchée est présente dans le vecteur." << std::endl;
    } else {
        std::cout << "La valeur recherchée n'est pas présente dans le vecteur." << std::endl;
    }

    if (resultatListe) {
        std::cout << "La valeur recherchée est présente dans la liste." << std::endl;
    } else {
        std::cout << "La valeur recherchée n'est pas présente dans la liste." << std::endl;
    }

    if (resultatTableau) {
        std::cout << "La valeur recherchée est présente dans le tableau." << std::endl;
    } else {
        std::cout << "La valeur recherchée n'est pas présente dans le tableau." << std::endl;
    }

    return 0;
}





//Exercice 5 
#include <iostream>

using namespace std;

class Test {
public:
    static int tableau[];

public:
    static int division(int indice, int diviseur) {
        if (indice < 0 || indice >= 10) {
            throw out_of_range("Indice hors limites !");
        }
        if (diviseur == 0) {
            throw runtime_error("Division par zéro !");
        }
        return tableau[indice] / diviseur;
    }
};

int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 8, 5};

int main() {
    int x, y;

    cout << "Entrez l'indice de l'entier à diviser : ";
    cin >> x;

    cout << "Entrez le diviseur : ";
    cin >> y;

    try {
        int resultat = Test::division(x, y);
        cout << "Le résultat de la division est : " << resultat << endl;
    } catch (const out_of_range& e) {
        cout << "Erreur : " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    return 0;
}




//Exercice 6
class vectok : public vect {
public:
    vectok(int nelen) : vect(nelen) {}
    vectok(const vectok& other) : vect(other.nelen) {
        for (int i = 0; i < nelen; i++) {
            adr[i] = other.adr[i];
        }
    }
    vectok& operator=(const vectok& other) {
        if (this != &other) {
            delete[] adr;
            nelen = other.nelen;
            adr = new int[nelen];
            for (int i = 0; i < nelen; i++) {
                adr[i] = other.adr[i];
            }
        }
        return *this;
    }
    int taille() const {
        return nelen;
    }
};

int main() {
    vectok v1(5);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v1[3] = 4;
    v1[4] = 5;

    vectok v2 = v1;
    vectok v3(3);
    v3 = v2;

    cout << "Taille de v1 : " << v1.taille() << endl;
    cout << "Taille de v2 : " << v2.taille() << endl;
    cout << "Taille de v3 : " << v3.taille() << endl;

    return 0;
}




//Exercice 8 
#include <iostream>

template <typename T>
T carre(T valeur) {
    return valeur * valeur;
}

int main() {
    int entier = 5;
    float reel = 2.5;
    
    std::cout << "Le carré de " << entier << " est : " << carre(entier) << std::endl;
    std::cout << "Le carré de " << reel << " est : " << carre(reel) << std::endl;
    
    return 0;
}




//
