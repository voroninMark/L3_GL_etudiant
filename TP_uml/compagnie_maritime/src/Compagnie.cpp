#include "Compagnie.hpp"

void Compagnie::enregistrerPort(const std::string & nom)
{
    if (not trouverPort(nom))
        _ports.push_back({nom});
}

void Compagnie::enregistrerPassager(const std::string & nom, 
        const std::string & prenom)
{
    if (not trouverPassager(nom, prenom))
       _passagers.push_back({nom, prenom});
}

void Compagnie::enregistrerBateau(const std::string & nom, 
        unsigned capacitePassagers)
{
    if (not trouverBateau(nom))
        _bateaux.push_back(Bateau(nom, capacitePassagers));
}

Passager * Compagnie::trouverPassager(const std::string & nom, 
    const std::string & prenom) 
{
    for (Passager & p : _passagers)
        if (p._nom == nom and p._prenom == prenom)
            return std::addressof(p);
    return nullptr;
}

Port * Compagnie::trouverPort(const std::string & nom) 
{
    for (Port & p : _ports)
        if (p._nom == nom)
            return std::addressof(p);
    return nullptr;
}

Bateau * Compagnie::trouverBateau(const std::string & nom) 
{
    for (Bateau & b : _bateaux)
        if (b._nom == nom)
            return std::addressof(b);
    return nullptr;
}

void Compagnie::afficherBateaux() const
{
    for (const Bateau & b : _bateaux)
        b.afficher();
}

void Compagnie::preparerBateau(const std::string & nomBateau, 
        const std::string & nomPortDepart, 
        const std::string & nomPortArrivee)
{
    Port * ptrPortDepart = trouverPort(nomPortDepart);
    if (not ptrPortDepart)
        throw std::string("port de départ inconnu: " + nomPortDepart);

    Port * ptrPortArrivee = trouverPort(nomPortArrivee);
    if (not ptrPortArrivee)
        throw std::string("port d'arrivée inconnu: " + nomPortArrivee);

    Bateau * ptrBateau = trouverBateau(nomBateau);
    if (not ptrBateau)
        throw std::string("bateau inconnu: " + nomBateau);

    ptrBateau->preparer(ptrPortDepart, ptrPortArrivee);
}

void Compagnie::reserverBateau(const std::string & nomBateau, 
        const std::string & nomPassager, 
        const std::string & prenomPassager)
{
    Passager * ptrPassager = trouverPassager(nomPassager, prenomPassager);
    if (not ptrPassager)
        throw std::string(nomPassager + " " + prenomPassager + " inconnu");

    Bateau * ptrBateau = trouverBateau(nomBateau);
    if (not ptrBateau)
        throw std::string(nomBateau + " inconnu");

    ptrBateau->ajouterPassager(ptrPassager);
} 


