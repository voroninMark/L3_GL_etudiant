#include "Mediatheque.hpp"
#include "Utilisateur.hpp"

#include <iostream>

std::unique_ptr<Utilisateur> creerUtilisateur(const std::string & login)
{
    if (login == "utilisateur")
        return std::make_unique<Utilisateur>();
    else if (login == "gestionnaire")
        return std::make_unique<Gestionnaire>();
    else 
        throw std::string("login inconnu");
}

int main()
{
    Mediatheque mediatheque;

    while (true)
    {
        std::unique_ptr<Utilisateur> utilisateur;

        // authentifie un utilisateur
        std::string login = saisir("\nLogin (utilisateur, gestionnaire, quitter) ? ");
        if (login == "quitter")
            break;
        try
        {
            utilisateur = creerUtilisateur(login);
        }
        catch (const std::string & e)
        {
            std::cout << "erreur : " << e << std::endl;
            continue;
        }

        // gère les opérations de l'utilisateur
        auto operations = utilisateur->getOperations();
        while (true)
        {
            std::cout << "Opération (";
            for (const std::string & o : operations)
                std::cout << o << ", ";
            std::cout << "deconnexion) ? ";
            std::string operation = saisir("");
            if (operation == "deconnexion")
                break;
            try
            {
                bool ok = utilisateur->gererOperation(operation, mediatheque);
                if (not ok)
                    throw std::string("operation inconnue");
            }
            catch (const std::string & e)
            {
                std::cout << "erreur : " << e << std::endl;
            }
        }
    }

    return 0;
}

