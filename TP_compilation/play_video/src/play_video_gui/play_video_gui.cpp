#include "PlayerWindow.hpp"
#include <play_video/Filesystem.hpp>
#include <iostream>

int main (int argc, char ** argv) {

    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " <folder>\n";
        exit(-1);
    }

    try {
        std::vector<std::string> filenames = getFilesInFolder(argv[1]);
        Gtk::Main app(argc, argv);
        PlayerWindow win(filenames);
        app.run(win);
    }
    catch (const std::string & err) {
        std::cerr << "error: " << err << std::endl;
        exit(-1);
    }

    return 0;
}

