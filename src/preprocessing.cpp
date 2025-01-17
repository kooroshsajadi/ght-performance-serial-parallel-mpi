#include "../include/preprocessing.h"
#include <stdexcept>

using namespace std;
using namespace cv;

cv::Mat loadImage(const std::string& filePath) {
    Mat image = imread(filePath, IMREAD_GRAYSCALE);
    if (image.empty()) {
        throw std::runtime_error("Failed to load image from: " + filePath);
    }
    return image;
}

cv::Mat preprocessImage(const cv::Mat& inputImage) {
    // ... (implementation from our previous discussion)
}

void saveImage(const std::string& filePath, const cv::Mat& image) {
    // ... (implementation from our previous discussion)
}

void computeCanny(const cv::Mat& inputImage, cv::Mat& cannyOutput, int lowThreshold, int highThreshold) {
    cv::Canny(inputImage, cannyOutput, lowThreshold, highThreshold); 
}

void computeGradients(const cv::Mat& inputImage, cv::Mat& dx, cv::Mat& dy, int ksize, double scale) {
    cv::Sobel(inputImage, dx, CV_32F, 1, 0, ksize, scale);
    cv::Sobel(inputImage, dy, CV_32F, 0, 1, ksize, scale);
}