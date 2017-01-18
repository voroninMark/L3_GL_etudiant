#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char ** argv) {

  if (argc != 2) {
    std::cerr << "usage: " << argv[0] << " <filename>\n";
    exit(-1);
  }

  cv::Mat image = cv::imread(argv[1]);
  if (image.empty()) {
    std::cerr << "error: failed to load " << argv[1] << std::endl;
    exit(-1);
  }

  cv::imshow(argv[0], image);
  cv::waitKey(0);

  return 0;
}

