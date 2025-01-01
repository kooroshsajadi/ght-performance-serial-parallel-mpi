#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    // Load the teimplate and target images in grayscale.
    Mat img_template = imread("template_small_2.png", IMREAD_GRAYSCALE);
    Mat img = imread("image.png", IMREAD_GRAYSCALE);

    if (img_template.empty() || img.empty()) {
        cerr << "Error: Could not load images." << endl;
        return -1;
    }

    // Display images verify successful loading.
    // namedWindow("Template", WINDOW_NORMAL);
    // imshow("Template", img_template);

    // namedWindow("Image", WINDOW_NORMAL);
    // imshow("Image", img);

    // Processing: Edge detection and gradient computation.
    Mat canny_template, dx_template, dy_template;
    Mat canny, dx, dy;

    int cannLow = 150, cannHigh = 230, sobelKernelSize = 5;
    double sobelScale = 0.05;

    // Apply Canny edge detection.
    Canny(img_template, canny_template, cannLow, cannHigh);
    Canny(img, canny, cannLow, cannHigh);

    // Compute gradients.
    Sobel(img_template, dx_template, CV_32F, 1, 0, sobelKernelSize, sobelScale);
    Sobel(img_template, dy_template, CV_32F, 0, 1, sobelKernelSize, sobelScale);
    Sobel(img, dx, CV_32F, 1, 0, sobelKernelSize, sobelScale);
    Sobel(img, dy, CV_32F, 0, 1, sobelKernelSize, sobelScale);

    // Display preprocessed results.
    namedWindow("Canny Template", WINDOW_NORMAL);
    imshow("Canny Template", canny_template);

    namedWindow("Canny Image", WINDOW_NORMAL);
    imshow("Canny Image", canny);

    namedWindow("Gradient X Template", WINDOW_NORMAL);
    imshow("Gradient X Template", dx_template);

    namedWindow("Gradient Y Template", WINDOW_NORMAL);
    imshow("Gradient Y Template", dy_template);

    namedWindow("Gradient X Image", WINDOW_NORMAL);
    imshow("Gradient X Image", dx);

    namedWindow("Gradient Y Image", WINDOW_NORMAL);
    imshow("Gradient Y Image", dy);

    waitKey(0);
    return 0;
}   