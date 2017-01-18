#include <drunk_player/Chrono.hpp>
#include <drunk_player/Player.hpp>
#include <iostream>

int main(int argc, char ** argv) {

    // check command line arguments
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <folder> <output file>\n";
        exit(-1);
    }
    const std::string progName = argv[0];
    const std::string folderName = argv[1];
    const std::string outputName = argv[2];

    Chrono chrono;
    chrono.start();

    // open files
    DrunkPlayer player;
    try {
        player.loadFolder(folderName);
    }
    catch (const std::string & err) {
        std::cerr << "error: " << err << std::endl;
        exit(-1);
    }

    // open writer
    int size = player.getImageSize();
    cv::VideoWriter video(outputName, CV_FOURCC('M','J','P','G'), 30, 
            cv::Size(size, size));

    // process video
    cv::Mat imgVideo;
    while (true) {
        // get frame
        player >> imgVideo;
        if (player.isFinished())
            break;
        // output frame
        video.write(imgVideo);
    }

    chrono.stop();
    std::cout << "elapsed time: " << chrono.elapsed() << "s\n";

    return 0;
}

