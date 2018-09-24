#pragma once
#include <iostream>
#include <opencv2\opencv.hpp>
#include "functions.h"
#include "test.h"


int main(int argc, char** argv)
{
	// Declare the output variables
	cv::Mat cdst;

	//Input kép elérési útvonala
	const char* imgPath = "Images/Squere.jpg";
	const char* imgName = argc >= 2 ? argv[1] : imgPath;

	// Kép beolvasása szürkeárnyalatos képként
	cv::Mat src = imread(imgName, cv::IMREAD_GRAYSCALE);

	// Beolvasás ellenőrzése
	if (src.empty()) {
		std::cout << "Error opening image: " << imgName << std::endl;
		return -1;
	}
	
	//Színes kép
	cv::Mat resultC3 = cv::Mat::zeros(src.size(), CV_8UC3);
	cv::Scalar colorC3(255, 0, 255);  //magenta
	LineVectorization(src, resultC3, colorC3);

	//Szürkeárnyalatos kép
	cv::Mat result = cv::Mat::zeros(src.size(), CV_8UC1);
	int color = 255; //fehér
	LineVectorization(src, result, color);

	//Eredmény megjelenítése
	imshow("Source", src);
	imshow("Colored lines", resultC3);
	imshow("White lines", result);

	IsConnectedTest();

	// Wait and Exit
	cv::waitKey();
	return 0;
}