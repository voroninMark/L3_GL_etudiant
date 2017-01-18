#ifndef COMPAGNIE_HPP_
#define COMPAGNIE_HPP_

#include "Bateau.hpp"

class Compagnie
{
    private:
        std::vector<Passager> _passagers;
        std::vector<Port> _ports;
        std::vector<Bateau> _bateaux;

    public:
        // Enregistre un Passager/Port/Bateau dans la compagnie, s'il n'est pas
        // déjà enregistré.
        void enregistrerPassager(const std::string & nom, 
                const std::string & prenom);
        void enregistrerPort(const std::string & nom);
        void enregistrerBateau(const std::string & nom, 
                unsigned capacitePassagers);

        // Initialise les ports de départ/arrivée et vide les passagers.
        // Lance une exception si bateau ou ports non enregistrés.
        void preparerBateau(const std::string & nomBateau, 
                const std::string & nomPortDepart, 
                const std::string & nomPortArrivee);

        // Ajoute un passager dans un bateau. Lance une exception si passager
        // inconnu, déjà dans le bateau, ou si le bateau est déjà plein.
        void reserverBateau(const std::string & nomBateau,
                const std::string & nomPassager, 
                const std::string & prenomPassager); 

        void afficherBateaux() const;

    private:
        Passager * trouverPassager(const std::string & nom, 
                const std::string & prenom);
        Port * trouverPort(const std::string & nom);
        Bateau * trouverBateau(const std::string & nom);
};

#endif

