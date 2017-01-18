#include "Utilisateur.hpp"

#include <iostream>

std::string saisir(const std::string & message)
{
    std::cout << message;
    std::string reponse;
    std::getline(std::cin, reponse);
    return reponse;
}

//////////////////////////////////////////////////////////////////////
// Utilisateur
//////////////////////////////////////////////////////////////////////

std::vector<std::string> Utilisateur::getOperations() const
{
    return {"afficher", "emprunter", "rendre"};
}

bool Utilisateur::gererOperation(const std::string & operation, 
        Mediatheque & mediatheque)
{
    if (operation == "afficher")
    {
        mediatheque.afficherMediatheque();
        return true;
    }

    if (operation == "emprunter")
    {
        std::string titre = saisir("Titre ? ");
        std::string auteur = saisir("Auteur ? ");
        std::string emprunteur = saisir("Nom de l'emprunteur ? ");
        mediatheque.emprunter(titre, auteur, emprunteur);
        return true;
    }

    if (operation == "rendre")
    {
        std::string titre = saisir("Titre du livre ? ");
        std::string auteur = saisir("Auteur du livre ? ");
        std::string emprunteur = saisir("Nom de l'emprunteur ? ");
        mediatheque.rendre(titre, auteur, emprunteur);
        return true;
    }

    return false;
}

std::vector<std::string> Gestionnaire::getOperations() const
{
    auto operations = Utilisateur::getOperations();
    operations.push_back("livre");
    operations.push_back("dvd");
    return operations;
}

//////////////////////////////////////////////////////////////////////
// Gestionnaire
//////////////////////////////////////////////////////////////////////

bool Gestionnaire::gererOperation(const std::string & operation, 
        Mediatheque & mediatheque)
{
    if (Utilisateur::gererOperation(operation, mediatheque))
        return true;

    if (operation == "livre")
    {
        std::string titre = saisir("Titre du livre ? ");
        std::string auteur = saisir("Auteur du livre ? ");
        int nbPages = std::stoi(saisir("Nombre de pages ? "));
        mediatheque.ajouterLivre(titre, auteur, nbPages);
        return true;
    }

    if (operation == "dvd")
    {
        std::string titre = saisir("Titre du dvd ? ");
        std::string auteur = saisir("Auteur du dvd ? ");
        int duree = std::stoi(saisir("Duree en minutes ? "));
        mediatheque.ajouterDvd(titre, auteur, duree);
        return true;
    }

    return false;
}

