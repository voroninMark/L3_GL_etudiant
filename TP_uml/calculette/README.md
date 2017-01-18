# calculette

## Description

Une calculette toute simple pour faire des additions, soustractions,
multiplications et divisions sur des entiers.

## Compilation

Installer g++ et cmake puis :

```
mkdir build
cd build
cmake ..
make
```

## Utilisation

```
$ ./calculette2.out 

Entrez l'opération à réaliser (+, -, *, /, quitter) : +
Entrez le premier nombre : 37
Entrez le second nombre : 5
37 + 5 = 42

Entrez l'opération à réaliser (+, -, *, /, quitter) : /
Entrez le premier nombre : toto
Erreur: nombre invalide

Entrez l'opération à réaliser (+, -, *, /, quitter) : supprimer la faim dans le monde
Entrez le premier nombre : 0
Entrez le second nombre : 0
Erreur: operation inconnue

Entrez l'opération à réaliser (+, -, *, /, quitter) : quitter
Au revoir
```

Idem pour `calculette1.out` mais sans gestion d'erreur.

