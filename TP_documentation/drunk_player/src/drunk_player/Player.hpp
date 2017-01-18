#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <drunk_player/Random.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

// Lecteur de video (classe abstraite).
// todo : implémenter un lecteur classique qui lit toutes les vidéos à la suite
// bug : le son n'est pas géré
class AbstractPlayer {

    protected:
        std::vector<cv::VideoCapture> _captures; 
        int _size;

    public:
        // Classe abstraite de base pour des lecteurs vidéo.
        AbstractPlayer();

        // Lit tous les fichiers d'un dossier.
        // precondition : considère que les fichiers sont tous des vidéos
        // exception : std::string si pas de fichiers valides
        virtual void loadFolder(const std::string & folderName);

        // Retourne la taille maximale des vidéos.
        // Ne distingue pas largeur/hauteur.
        int getImageSize() const;

        // Retourne si toutes les vidéos ont été lues entièrement.
        virtual bool isFinished() const = 0;

        // Lit une image du flux vidéo.
        virtual void operator>>(cv::Mat & image) = 0;
};

// Lecteur vidéo qui lit des vidéos par morceaux désordonnés et transformés.
class DrunkPlayer : public AbstractPlayer {

    private:
        bool _isTranspose;
        unsigned _nbCurrentFrames;
        Random _random;
        std::mt19937 _engine;
        bool _isFinished;

    public:
        // Constructeur.
        DrunkPlayer();

        // Lit tous les fichiers d'un dossier.
        void loadFolder(const std::string & folderName) override;

        // Retourne si toutes les vidéos ont été lues entièrement.
        bool isFinished() const override;

        // Lit une image du flux vidéo.
        void operator>>(cv::Mat & image) override;
};

#endif

