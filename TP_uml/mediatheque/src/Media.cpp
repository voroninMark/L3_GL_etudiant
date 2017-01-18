#include "Media.hpp"

#include <iostream>

//////////////////////////////////////////////////////////////////////
// Media
//////////////////////////////////////////////////////////////////////

Media::Media(const std::string & titre, const std::string & auteur) :
    _titre(titre), _auteur(auteur)
{}

//////////////////////////////////////////////////////////////////////
// Livre
//////////////////////////////////////////////////////////////////////

Livre::Livre(const std::string & titre, const std::string & auteur, 
        int nbPages) :
    Media(titre, auteur), _nbPages(nbPages)
{}

void Livre::afficher() const 
{
    std::cout << "Livre \"" << _titre << "\" de " << _auteur 
        << " (" << _nbPages << " pages)";
}

//////////////////////////////////////////////////////////////////////
// Dvd
//////////////////////////////////////////////////////////////////////

Dvd::Dvd(const std::string & titre, const std::string & auteur, int duree) :
    Media(titre, auteur), _duree(duree)
{}

void Dvd::afficher() const 
{
    std::cout << "Dvd \"" << _titre << "\" de " << _auteur 
        << " (" << _duree << " minutes)";
}

