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
    namedWindow("Template", WINDOW_NORMAL);
    imshow("Template", img_template);

    namedWindow("Image", WINDOW_NORMAL);
    imshow("Image", img);

    waitKey(0);
    return 0;
}   