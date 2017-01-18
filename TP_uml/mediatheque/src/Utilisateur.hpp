#ifndef UTILISATEUR_HPP_
#define UTILISATEUR_HPP_

#include "Mediatheque.hpp"

std::string saisir(const std::string & message);

struct Utilisateur 
{
    // Retourne les operations disponibles.
    virtual std::vector<std::string> getOperations() const;

    // Essaie de gérer l'operation.
    // Retourne true si l'operation a bien été gérée.
    virtual bool gererOperation(const std::string & operation, 
            Mediatheque & mediatheque);
};

struct Gestionnaire : Utilisateur
{
    std::vector<std::string> getOperations() const;

    bool gererOperation(const std::string & operation, 
            Mediatheque & mediatheque);
};

#endif

