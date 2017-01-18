# mediatheque

## Description

Gestion d'une médiathèque (livre et dvd) avec plusieurs rôles (utilisateur, gestionnaire).

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
$ ./mediatheque.out 

Login (utilisateur, gestionnaire, quitter) ? gestionnaire
Opération (afficher, emprunter, rendre, livre, dvd, deconnexion) ? livre
Titre du livre ? Guerre et Paix
Auteur du livre ? Tolstoi
Nombre de pages ? 1617
Opération (afficher, emprunter, rendre, livre, dvd, deconnexion) ? dvd
Titre du dvd ? Rocky III
Auteur du dvd ? Stallone-Shire
Duree en minutes ? 99
Opération (afficher, emprunter, rendre, livre, dvd, deconnexion) ? deconnexion

Login (utilisateur, gestionnaire, quitter) ? utilisateur
Opération (afficher, emprunter, rendre, deconnexion) ? emprunter
Titre ? Rocky III
Auteur ? Stallone-Shire
Nom de l'emprunteur ? Fabien
Opération (afficher, emprunter, rendre, deconnexion) ? afficher
Livre "Guerre et Paix" de Tolstoi (1617 pages), disponible
Dvd "Rocky III" de Stallone-Shire (99 minutes), emprunté par Fabien
Opération (afficher, emprunter, rendre, deconnexion) ? deconnexion

Login (utilisateur, gestionnaire, quitter) ? quitter
```

