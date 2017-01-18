# compagnie_maritime

## Description

Gestion d'une compagnie maritime : bateaux, ports, passagers, réservations.

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
$ ./compagnie_maritime.out

Opération (port, bateau, passager, preparer, reserver, afficher, quitter) ? port
Nom du nouveau port ? Calais

...

Opération (port, bateau, passager, preparer, reserver, afficher, quitter) ? preparer
Nom du bateau à préparer ? Pen Duick III
Nom du port de départ ? Calais
Nom du port d'arrivée ? Bora-Bora

...

Opération (port, bateau, passager, preparer, reserver, afficher, quitter) ? reserver
Nom du bateau à réserver ? Pen Duick III
Nom du passager ? Dehos
Prénom du passager ? Julien

...

Opération (port, bateau, passager, preparer, reserver, afficher, quitter) ? afficher
Pen Duick III : Calais -> Bora-Bora, 1/4
  - Dehos Julien
Titanic : Calais -> Triangle des Bermudes, 1/800
  - Teytaud Fabien
```

