#ifndef MEDIATHEQUE_HPP_
#define MEDIATHEQUE_HPP_

#include "Media.hpp"

#include <memory>
#include <string>
#include <vector>

class Mediatheque
{
    private:
        std::vector<std::unique_ptr<Media>> _media;
        std::vector<std::string> _emprunteurs;

    public:
        void ajouterLivre(const std::string & titre, const std::string & auteur,
                int nbPages);
        void ajouterDvd(const std::string & titre, const std::string & auteur,
                int duree);

        void afficherMediatheque() const;

        void emprunter(const std::string & titre, const std::string & auteur,
                const std::string & nomEmprunteur);
        void rendre(const std::string & titre, const std::string & auteur,
                const std::string & nomEmprunteur);
};

#endif

