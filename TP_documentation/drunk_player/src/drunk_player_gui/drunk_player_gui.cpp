#include <drunk_player/Player.hpp>
#include <iostream>

int main(int argc, char ** argv) {

    //// check command line arguments
    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " <folder>\n";
        exit(-1);
    }
    const std::string progName = argv[0];
    const std::string folderName = argv[1];

    //// open files
    DrunkPlayer player;
    try {
        player.loadFolder(folderName);
    }
    catch (const std::string & err) {
        std::cerr << "error: " << err << std::endl;
        exit(-1);
    }

    //// init display
    cv::namedWindow(progName);
    bool isPlaying = true;

    //// process video
    cv::Mat imgVideo;
    while (true) {

        //// get frame
        if (isPlaying) {
            player >> imgVideo;
            if (player.isFinished())
                break;
        }

        //// display frame 
        cv::imshow(progName, imgVideo);

        //// handle time and keyboard
        int k = cv::waitKey(33);    
        if (k % 0x100 == 27)
            break; //// quit if "esc"
        if (k % 0x100 == 32) 
            isPlaying = not isPlaying; //// play/pause if "space"
    }

    return 0;
}

