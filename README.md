# Devoir-TD3-Cpp
STL et concepts avancés
                 //Exercice 7
Le programme affichera les résultats suivants :

Construction objet A : 2 0.0
Construction objet B : 0.0
Construction objet C : -1 12
                 //Exercice 9 
a. Avec les instructions `point<char> p(60, 65);` et `p.affiche();`, une erreur de compilation se produira car les coordonnées `60` et `65` sont des entiers et non des caractères (`char`). Pour résoudre ce problème.
b.
template <class T>
class point {
    T x, y; // coordonnees

public:
    point(T x, T y) : x(x), y(y) {}

    void affiche() {
        cout << "Coordonnees : " << x << " " << y << "\n";
    }
};
                 //Exercice 10
Ce programme donnera les résultats suivants :

"dans f 999"
"dans main 999"
"suite main"


