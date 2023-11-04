#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
// Tri � bulle
void triABulle(list<int>& liste) {
    bool estTrie = false;
    while (!estTrie) {
        estTrie = true;
        for (auto it = liste.begin(); it != prev(liste.end()); ++it) {
            if (*it > *next(it)) {
                swap(*it, *next(it));
                estTrie = false;
            }
        }
    }
}

// Tri par s�lection
void triParSelection(list<int>& liste) {
    for (auto it = liste.begin(); it != prev(liste.end()); ++it) {
        auto minElement = min_element(it, liste.end());
        iter_swap(it, minElement);
    }
}

// Tri par insertion
void triParInsertion(list<int>& liste) {
    for (auto it = next(liste.begin()); it != liste.end(); ++it) {
        auto valeurCourante = *it;
        auto position = upper_bound(liste.begin(), it, valeurCourante);
        liste.insert(position, valeurCourante);
        liste.erase(it);
    }
}

int main() {
    list<int> liste;

    int nombre;
    char continuer;

    do {
        cout << "Entrez un entier : ";
        cin >> nombre;

        liste.push_back(nombre);

        cout << "Voulez-vous continuer (o/n) ? ";
        cin >> continuer;
    } while (continuer == 'o' || continuer == 'O');

    cout << "Liste initiale : ";
    for (const auto& element : liste) {
        cout << element << " ";
    }
    cout << endl;

    // Tri � bulle
    list<int> listeTrieeABulle = liste;
    triABulle(listeTrieeABulle);
    cout << "Liste tri�e avec le tri � bulle : ";
    for (const auto& element : listeTrieeABulle) {
        cout << element << " ";
    }
    cout << endl;

    // Tri par s�lection
    list<int> listeTrieeParSelection = liste;
    triParSelection(listeTrieeParSelection);
    cout << "Liste tri�e avec le tri par s�lection : ";
    for (const auto& element : listeTrieeParSelection) {
        cout << element << " ";
    }
    cout << endl;

    // Tri par insertion
    list<int> listeTrieeParInsertion = liste;
    triParInsertion(listeTrieeParInsertion);
    cout << "Liste tri�e avec le tri par insertion : ";
    for (const auto& element : listeTrieeParInsertion) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
