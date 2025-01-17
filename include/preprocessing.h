#ifndef MYPROJECT_PREPROCESSING_H
#define MYPROJECT_PREPROCESSING_H

#include <opencv2/opencv.hpp>
#include <string>

cv::Mat loadImage(const std::string& filePath);
cv::Mat preprocessImage(const cv::Mat& inputImage);
void saveImage(const std::string& filePath, const cv::Mat& image);
void computeCanny(const cv::Mat& inputImage, cv::Mat& cannyOutput, int lowThreshold, int highThreshold);
void computeGradients(const cv::Mat& inputImage, cv::Mat& dx, cv::Mat& dy, int ksize, double scale);

#endif // MYPROJECT_PREPROCESSING_H