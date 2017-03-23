#ifndef RANDOM_HPP_
#define RANDOM_HPP_

#include <random>

/// Générateur de nombre pseudo-aléatoire (selon la loi uniforme).
/// Exemple d'utilisation :
/// Random rng;
/// int x = rng(42);
/// double y = rng();
class Random {

    private:
        std::mt19937_64 _engine;
        std::uniform_real_distribution<double> _distribution;

    public:
        /// Constructeur à utiliser.
        Random();

        /// Constructeur par copie interdit.
        /// Pour éviter les suites pseudo-aléatoires identiques.
        Random(const Random &) = delete;

        /// Génère un nombre aléatoire réel dans [0,1).
        double operator()();

        /// Génère un nombre aléatoire entier dans [0,n).
        int operator()(int n);
};

#endif

