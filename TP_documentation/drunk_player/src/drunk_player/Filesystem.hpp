#ifndef FILESYSTEM_HPP_
#define FILESYSTEM_HPP_

#include <string>
#include <vector>

// Retourne la liste des fichiers contenus dans un dossier.
// Les fichiers sont donnés avec leur chemin relatif.
std::vector<std::string> getFilesInFolder(const std::string & pathname);

#endif

