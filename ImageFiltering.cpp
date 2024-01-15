#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // Read the input image
    Mat image = imread("/InterArmy/mustafaPic.jpg");

    // Check if the image is loaded successfully
    if (image.empty()) {
        std::cerr << "Error: Unable to read the image file\n";
        return -1;
    }

    // Convert the image to grayscale
    Mat grayscale;
    cvtColor(image, grayscale, COLOR_BGR2GRAY);

    // Apply a blur filter
    Mat blurred;
    GaussianBlur(grayscale, blurred, Size(5, 5), 0);

    // Apply a sharpening filter
    Mat sharpened;
    Mat kernel = (Mat_<float>(3,3) <<  0, -1,  0,
                                       -1,  5, -1,
                                        0, -1,  0);
    filter2D(blurred, sharpened, -1, kernel);

    // Save the modified image
    imwrite("output_image.jpg", sharpened);

    return 0;
}
