#include "Compagnie.hpp"

#include <iostream>

std::string saisir(const std::string & message)
{
    std::cout << message;
    std::string reponse;
    std::getline(std::cin, reponse);
    return reponse;
}

int main()
{
    Compagnie compagnie;

    while (true)
    {
        try
        {
            std::string operation = 
                saisir("\nOpération (port, bateau, passager, preparer, reserver, afficher, quitter) ? ");

            if (operation == "quitter") 
                break;
            else if (operation == "afficher")
            {
                compagnie.afficherBateaux();
            }
            else if (operation == "port")
            {
                std::string nom = saisir("Nom du nouveau port ? ");
                compagnie.enregistrerPort(nom);
            }
            else if (operation == "bateau")
            {
                std::string nom = saisir("Nom du nouveau bateau ? ");
                unsigned capacite = std::stoi(saisir("Capacité ? "));
                compagnie.enregistrerBateau(nom, capacite);
            }
            else if (operation == "passager")
            {
                std::string nom = saisir("Nom du nouveau passager ? ");
                std::string prenom = saisir("Prénom ? ");
                compagnie.enregistrerPassager(nom, prenom);
            }
            else if (operation == "preparer")
            {
                std::string nomBateau = saisir("Nom du bateau à préparer ? ");
                std::string nomDepart = saisir("Nom du port de départ ? ");
                std::string nomArrivee = saisir("Nom du port d'arrivée ? ");
                compagnie.preparerBateau(nomBateau, nomDepart, nomArrivee);
            }
            else if (operation == "reserver")
            {
                std::string nomBateau = saisir("Nom du bateau à réserver ? ");
                std::string nom = saisir("Nom du passager ? ");
                std::string prenom = saisir("Prénom du passager ? ");
                compagnie.reserverBateau(nomBateau, nom, prenom);
            }
        }
        catch (const std::string & e)
        {
            std::cout << "erreur : " << e << std::endl;
        }
    }

    return 0;
}


int main_vieux()
{
    Compagnie compagnie;

    // quelques ports
    compagnie.enregistrerPort("Calais");
    compagnie.enregistrerPort("Triangle des Bermudes");
    compagnie.enregistrerPort("Bora-Bora");

    // quelques bateaux
    compagnie.enregistrerBateau("Titanic", 800);
    compagnie.enregistrerBateau("Pen Duick III", 4);

    // quelques passagers
    compagnie.enregistrerPassager("Teytaud", "Fabien");
    compagnie.enregistrerPassager("Dehos", "Julien");

    // quelques réservations
    try
    {
        compagnie.preparerBateau("Titanic", "Calais", "Triangle des Bermudes");
        compagnie.preparerBateau("Pen Duick III", "Calais", "Bora-Bora");

        compagnie.reserverBateau("Titanic", "Teytaud", "Fabien");
        compagnie.reserverBateau("Pen Duick III", "Dehos", "Julien");

        compagnie.afficherBateaux();
    }
    catch (const std::string & e)
    {
        std::cerr << "Erreur lors des réservations : " << e << std::endl;
    }

    return 0;
}

