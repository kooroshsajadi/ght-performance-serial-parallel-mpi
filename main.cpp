#include <iostream>
#include "preprocessing.h"
#include "model.h"
#include "voting.h"
#include "detection.h"
#include "visualization.h"

int main(int argc, char** argv) {
    // Step 1: Argument Validation
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <image_path> <template_path>" << std::endl;
        return 1;
    }

    std::string image_path = argv[1];
    std::string template_path = argv[2];

    try {
        // Step 2: Preprocessing
        cv::Mat image = loadImage(image_path);
        cv::Mat template_image = loadImage(template_path);
        cv::Mat edges = detectEdges(image);
        
        // Step 3: Model Initialization
        Accumulator accumulator = initializeAccumulator(template_image);

        // Step 4: Voting Process
        performVoting(edges, accumulator);

        // Step 5: Peak Detection
        std::vector<DetectionResult> results = detectPeaks(accumulator);

        // Step 6: Visualization
        visualizeResults(image, results);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
