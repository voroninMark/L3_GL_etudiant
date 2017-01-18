#include "Mediatheque.hpp"

#include <cassert>
#include <iostream>

void Mediatheque::ajouterLivre(const std::string & titre, 
        const std::string & auteur, int nbPages)
{
    _media.push_back(std::make_unique<Livre>(titre, auteur, nbPages));
    _emprunteurs.push_back("");
}

void Mediatheque::ajouterDvd(const std::string & titre, 
        const std::string & auteur, int duree)
{
    _media.push_back(std::make_unique<Dvd>(titre, auteur, duree));
    _emprunteurs.push_back("");
}

void Mediatheque::afficherMediatheque() const
{
    assert(_media.size() == _emprunteurs.size());

    for (unsigned i=0; i<_media.size(); ++i)
    {
        _media[i]->afficher();

        const std::string & emprunteur = _emprunteurs[i];
        if (emprunteur != "")
            std::cout << ", emprunté par " << emprunteur << std::endl;
        else
            std::cout << ", disponible" << std::endl;
    }
}

void Mediatheque::emprunter(const std::string & titre, 
        const std::string & auteur, const std::string & nomEmprunteur)
{
    for (unsigned i=0; i<_media.size(); ++i)
    {
        if (_media[i]->_titre == titre and _media[i]->_auteur == auteur
                and _emprunteurs[i] == "")
        {
            _emprunteurs[i] = nomEmprunteur;
            return;
        }
    }

    throw std::string("ce media n'est pas disponible");
}

void Mediatheque::rendre(const std::string & titre, 
        const std::string & auteur, const std::string & nomEmprunteur)
{
    for (unsigned i=0; i<_media.size(); ++i)
    {
        if (_media[i]->_titre == titre and _media[i]->_auteur == auteur
                and _emprunteurs[i] == nomEmprunteur)
        {
            _emprunteurs[i] = "";
            return;
        }
    }

    throw std::string("emprunt inconnu");
}

