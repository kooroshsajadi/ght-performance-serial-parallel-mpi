#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/core/mat.hpp>

int main()
{
    std::string image_path = "./image.png";
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);

    if (img.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    cv::imshow("Display window", img);
    int k = cv::waitKey(0); // Wait for a keystroke in the window
    return 0;
}
