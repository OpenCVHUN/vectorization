#include "functions.h"

void LineVectorization(const cv::Mat& src, cv::Mat& result, cv::Scalar color) {
	// Éldetektálás
	cv::Mat dst; //Éldetektálás eredmény Mat-ja
	Canny(src, dst, 50, 200, 3);

	// Probabilistic Line Transform
	std::vector<cv::Vec4i> linesP; // vonalakat fogjuk tárolni a linesP nevű vektorban
	HoughLinesP(dst, linesP, 1, CV_PI / 180, 50, 50, 10); // Hough transzformációval megkeresi az összes vonalat
	cv::Vec4i oneLine;
	for (size_t i = 0; i < linesP.size(); i++) {
		oneLine = linesP[i];  //egyes vonaldarabok
		line(result, cv::Point(oneLine[0], oneLine[1]), cv::Point(oneLine[2], oneLine[3]), color, 3, cv::LINE_AA);  //megrajzolja a vonalakat
	}
}

void LineVectorization(const cv::Mat& src, cv::Mat& result, int color) {
	// Éldetektálás
	cv::Mat dst; //Éldetektálás eredmény Mat-ja
	Canny(src, dst, 50, 200, 3);

	// Probabilistic Line Transform
	std::vector<cv::Vec4i> linesP; // vonalakat fogjuk tárolni a linesP nevű vektorban
	HoughLinesP(dst, linesP, 1, CV_PI / 180, 50, 50, 10); // Hough transzformációval megkeresi az összes vonalat
	cv::Vec4i oneLine;
	for (size_t i = 0; i < linesP.size(); i++) {
		oneLine = linesP[i];  //egyes vonaldarabok
		line(result, cv::Point(oneLine[0], oneLine[1]), cv::Point(oneLine[2], oneLine[3]), color, 3, cv::LINE_AA);  //megrajzolja a vonalakat
	}
}
double LineVectorLenght(const cv::Vec4i& v) {
	return sqrt(pow(v[0] - v[2], 2) + pow(v[1] - v[3], 2));
}
double LineVectorAngle(const cv::Vec4i& v) {
	return asin(abs(v[1] - v[3]) / LineVectorLenght(v));
}

double LineVectorAngle(const cv::Vec4i& v1, const cv::Vec4i& v2) {
	return abs(LineVectorAngle(v1) - LineVectorAngle(v2));
}

bool IsConnected(const cv::Vec4i& v1, const cv::Vec4i& v2, int Epsylon) {
	//#Prosto megoldas, 4 lehetséges kombinációra létrehozok 4 vektort, és kiértékelem a távolságokat.
	//Ha hibahatáron belül van, akkor elfogadom, hogy ők csaktlakoznak egymáshoz.
	cv::Vec4i AC = { v1[2],v1[3],v2[0],v2[1] };
	cv::Vec4i AD = { v1[2],v1[3],v2[2],v2[3] };
	cv::Vec4i BC = { v1[0],v1[1],v2[0],v2[1] };
	cv::Vec4i BD = { v1[0],v1[1],v2[2],v2[3] };
	if (LineVectorLenght(AC) < Epsylon ||
		LineVectorLenght(AD) < Epsylon ||
		LineVectorLenght(BC) < Epsylon ||
		LineVectorLenght(BD) < Epsylon
		) {
		return true;
	}
	else
	{
		return false;
	}
}