#ifndef MEDIA_HPP_
#define MEDIA_HPP_

#include <string>

struct Media
{
    std::string _titre;
    std::string _auteur;

    Media(const std::string & titre, const std::string & auteur);

    virtual void afficher() const = 0;
};

struct Livre : Media
{
    int _nbPages;

    Livre(const std::string & titre, const std::string & auteur, int nbPages);

    void afficher() const override;
};

struct Dvd : Media
{
    int _duree;

    Dvd(const std::string & titre, const std::string & auteur, int duree);

    void afficher() const override;
};

#endif

