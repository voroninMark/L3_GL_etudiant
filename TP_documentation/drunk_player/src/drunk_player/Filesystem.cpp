#include <drunk_player/Filesystem.hpp>
#include <boost/filesystem.hpp>

using namespace std;
namespace fs = boost::filesystem;

vector<string> getFilesInFolder(const string & pathname) {

    fs::path path(pathname);

    if (not exists(path))
        throw pathname + string(" does not exist");

    if (not is_directory(path))
        throw pathname + string(" is not a directory");

    vector<string> filenames;
    //boost 1.62
    //for (auto&& x : fs::directory_iterator(path))
    //    filenames.push_back(x.path().relative_path().string());
    //boost 1.55
    for (auto it=fs::directory_iterator(path); it!=fs::directory_iterator(); ++it)
        filenames.push_back(it->path().relative_path().string());

    return filenames;
}

