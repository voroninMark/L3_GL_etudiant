#include <drunk_player/Player.hpp>
#include <drunk_player/Filesystem.hpp>

//////////////////////////////////////////////////////////////////////
// AbstractPlayer
//////////////////////////////////////////////////////////////////////

AbstractPlayer::AbstractPlayer() : 
    _size(0)
{
}

void AbstractPlayer::loadFolder(const std::string & folderName) {
    _size = 0;
    std::vector<std::string> filenames = getFilesInFolder(folderName);
    for (const std::string & f : filenames) {
        cv::VideoCapture cap(f); 
        if (cap.isOpened()) {
            _captures.push_back(std::move(cap));
            
            _size = std::max<int>(_size, cap.get(CV_CAP_PROP_FRAME_WIDTH));
            _size = std::max<int>(_size, cap.get(CV_CAP_PROP_FRAME_HEIGHT));
        }
    }
    if (_captures.empty())
        throw std::string("no valid file");
}

int AbstractPlayer::getImageSize() const {
    return _size;
}

//////////////////////////////////////////////////////////////////////
// DrunkPlayer
//////////////////////////////////////////////////////////////////////

DrunkPlayer::DrunkPlayer() : 
    AbstractPlayer(),
    _engine(std::random_device{}()),
    _isFinished(true)
{
}

void DrunkPlayer::loadFolder(const std::string & folderName) {
    _isTranspose = false;
    _nbCurrentFrames = 0;
    AbstractPlayer::loadFolder(folderName);
    _isFinished = false;
}

bool DrunkPlayer::isFinished() const {
    return _isFinished;
}

void DrunkPlayer::operator>>(cv::Mat & image) {

    cv::Mat frame;
    while (true) {
        if (_captures.empty()) {
            _isFinished = true;
            break;
        }
        _captures.back() >> frame;
        if (not frame.empty()) {
            break;
        }
        _captures.pop_back();
    }

    if (not _isFinished) {

        if (_isTranspose) {
            frame = frame.t();
        } 

        image = cv::Mat::zeros(_size, _size, CV_8UC3);
        frame.copyTo(image(cv::Rect(0, 0, frame.cols, frame.rows)));

        _nbCurrentFrames++;
        if (_nbCurrentFrames >= 30) {
            _isTranspose = _random(2) > 0;
            std::shuffle(_captures.begin(), _captures.end(), _engine);
            _nbCurrentFrames = 0;
        }
    }
}

