// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include “stdafx.h”

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*static void ShowImg(int argc, char** argv) {
	string imageName("images/pic.jpg"); // by default
	if (argc > 1) // run with argument
		imageName = argv[1];
	Mat image = imread(imageName.c_str(), IMREAD_COLOR); // Read the file
	if (image.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
//	return -1;
	}
	namedWindow("Display window", WINDOW_KEEPRATIO); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window
}*/

static void ShowImg(void) {
	string imageName("images/pic.jpg"); // by default
	Mat image = imread(imageName.c_str(), IMREAD_COLOR); // Read the file
	if (image.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
	}
	namedWindow("Display window", WINDOW_KEEPRATIO); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window
}

static int getphoto(void) {
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;

	Mat edges;
	namedWindow("edges", 1);
	for (;;) {
		Mat frame;
		cap >> frame; // get a new frame from camera
		cvtColor(frame, edges, COLOR_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges);
		if (waitKey(30) >= 0)
			break;
	}
	return 0;
}

int main(int argc, char** argv) {
	ShowImg();
	getphoto();
	return 0;
}
