#include "Bateau.hpp"

#include <algorithm>
#include <iostream>

Bateau::Bateau(const std::string & nom, unsigned capacitePassagers) :
    _nom(nom), _capacitePassagers(capacitePassagers),
    _ptrPortDepart(nullptr), _ptrPortArrivee(nullptr)
{}

void Bateau::afficher() const
{
    // affiche les infos sur le bateau
    std::cout << _nom << " : "; 
    std::cout << (_ptrPortDepart ? _ptrPortDepart->_nom : "?") << " -> ";
    std::cout << (_ptrPortArrivee ? _ptrPortArrivee->_nom : "?") << ", ";
    std::cout << _ptrPassagers.size() << "/" << _capacitePassagers << std::endl;

    // affiche les réservations
    for (const Passager * p : _ptrPassagers)
        std::cout << "  - " << p->_nom << " " << p->_prenom << std::endl;
}

bool Bateau::estPlein() const
{
    return _ptrPassagers.size() >= _capacitePassagers;
}

void Bateau::preparer(Port * ptrPortDepart, Port * ptrPortArrivee)
{
    _ptrPortDepart = ptrPortDepart;
    _ptrPortArrivee = ptrPortArrivee;
    _ptrPassagers.clear();
}

void Bateau::ajouterPassager(Passager * ptrPassager)
{
    if (not ptrPassager)
        throw std::string("passager inconnu");

    if (estPlein())
        throw std::string(_nom + " déjà plein");

    if (std::find(_ptrPassagers.begin(), _ptrPassagers.end(), ptrPassager)
            != _ptrPassagers.end())
        throw std::string(ptrPassager->_nom + " " + ptrPassager->_prenom 
                + " déjà dans " + _nom);

    _ptrPassagers.push_back(ptrPassager);
}

