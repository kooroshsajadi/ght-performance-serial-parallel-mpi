#include <iostream>
#include "../include/preprocessing.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    try {
        cv::Mat image = loadImage("../image.jpg");
        cv::Mat template_image = loadImage("../template_small_2.jpg");

        Mat canny, canny_template;
        int cannLow = 150, cannHigh = 230;
        computeCanny(image, canny, cannLow, cannHigh);
        computeCanny(template_image, canny_template, cannLow, cannHigh);

        Mat dx, dy, dx_template, dy_template;
        int sobelKernelSize = 5;
        double sobelScale = 0.05;
        computeGradients(image, dx, dy, sobelKernelSize, sobelScale);
        computeGradients(template_image, dx_template, dy_template, sobelKernelSize, sobelScale);

    } catch (const std::runtime_error& error) {
        std::cerr << "Error: " << error.what() << std::endl;
    }
    return 0;
}
