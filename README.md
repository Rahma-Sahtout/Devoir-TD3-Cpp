# Devoir-TD3-Cpp
STL et concepts avancés
//Exercice 6
Le programme affichera les résultats suivants :

Construction objet A : 2 0.0
Construction objet B : 0.0
Construction objet C : -1 12
//Exercice 9 
a. Avec les instructions `point<char> p(60, 65);` et `p.affiche();`, une erreur de compilation se produira car les coordonnées `60` et `65` sont des entiers et non des caractères (`char`). Pour résoudre ce problème, vous pouvez modifier les coordonnées pour qu'elles correspondent à des caractères valides.
//Exercice 10
Ce programme donnera les résultats suivants :

"dans f 999"
"dans main 999"
"suite main"

Lorsque la fonction `f()` est appelée, elle tente de créer un objet de la classe `A` avec la valeur `1`. Cependant, dans le constructeur de la classe `A`, une exception de la classe `erreur` est levée si la valeur `n` est différente de `1`. Dans ce cas, l'exception est levée et attrapée dans le bloc `catch` de la fonction `f()`, qui affiche "dans f 999".

Ensuite, l'exception est propagée jusqu'au bloc `catch` dans la fonction `main()`, où l'objet `erreur` est attrapé et son attribut `num` est affiché, donnant "dans main 999". Enfin, "suite main" est affiché normalement après la gestion de l'exception.
