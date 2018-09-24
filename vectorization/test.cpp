#include "test.hpp"
#include "functions.h"
void IsConnectedTest() {
	Test<bool> t;
	cv::Vec4i A{ 0,0,100,100 };
	cv::Vec4i B{ 0,99,98,101 };
	t.test("Test  for IsConnected method", IsConnected(A, B, 4), true);
	t.report();
}