#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;

Mat bgr_img, hsv_img;

int main(int argc, char *argv[])
{
	// Load the image
	bgr_img = imread("img.jpg", CV_LOAD_IMAGE_COLOR);
	if (!bgr_img.data) {
		std::cerr << "Failed to load image\n";
		return 1;
	}

	// Convert to HSV colour space
	cvtColor(bgr_img, hsv_img, COLOR_BGR2HSV);

	// Create a control window
	namedWindow("Control", CV_WINDOW_AUTOSIZE);
	int iLowH = 0;
	int iHighH = 179;

	int iLowS = 0;
	int iHighS = 255;

	int iLowV = 0;
	int iHighV = 255;

	// Create trackbars in "Control" window
	cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
	cvCreateTrackbar("HighH", "Control", &iHighH, 179);

	cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	cvCreateTrackbar("HighS", "Control", &iHighS, 255);

	cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
	cvCreateTrackbar("HighV", "Control", &iHighV, 255);

	// Create the display windows
	namedWindow("Display", WINDOW_AUTOSIZE);
	imshow("Display", bgr_img); //show the original image
	namedWindow("Thresholded", WINDOW_AUTOSIZE);

	// Display the result of the current calibration settings
	while (true) {
		Mat thresh_img;
		Mat display_img = bgr_img.clone(); // deep copy because we will modify it below

		// Threshold the image
		inRange(hsv_img, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), thresh_img);

		// Show the thresholded image
		imshow("Thresholded", thresh_img);

		// Draw the final image
		imshow("Display", display_img);

		// Allow openCV to process GUI events
		waitKey(100);
	}

	return 0;
}
