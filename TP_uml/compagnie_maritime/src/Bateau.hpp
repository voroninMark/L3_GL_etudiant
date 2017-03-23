#ifndef BATEAU_HPP_
#define BATEAU_HPP_

#include <string>
#include <vector>

struct Passager
{
    std::string _nom;
    std::string _prenom;
};

struct Port
{
    std::string _nom;
};

class Bateau
{
    public:
        std::string _nom;
        unsigned _capacitePassagers;

    public:
        Bateau(const std::string & nom, unsigned capacitePassagers);

        // Initialise les ports de départ/arrivée et vide les passagers.
        void preparer(Port * ptrPortDepart, Port * ptrPortArrivee);

        void ajouterPassager(Passager * ptrPassager);
        bool estPlein() const;

        // Affiche les infos sur le bateau et ses passagers.
        void afficher() const;

    private:
        Port * _ptrPortDepart;
        Port * _ptrPortArrivee;
        std::vector<Passager *> _ptrPassagers;
};

#endif

