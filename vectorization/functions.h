#pragma once
#include <iostream>
#include <opencv2\opencv.hpp>

void LineVectorization(const cv::Mat & src, cv::Mat & result, cv::Scalar color);

void LineVectorization(const cv::Mat & src, cv::Mat & result, int color);

bool IsConnected(const cv::Vec4i& v1, const cv::Vec4i& v2, int Epsylon);
