#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <string>

using namespace cv;


String face_xml = "C:/Users/Michael Dalton/Desktop/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;

//Program start
int main(void)
{
	VideoCapture feed(0);
	Mat frame;

	if (!feed.isOpened()) { std::cerr << "Error opening webcam\n"; return -1; }

	double width = feed.get(CV_CAP_PROP_FRAME_WIDTH);
	double height = feed.get(CV_CAP_PROP_FRAME_HEIGHT);

	std::cout << "size:" << width << "x" << height << std::endl;

	namedWindow("Test", CV_WINDOW_AUTOSIZE);

	while (true)
	{
		bool capture = feed.read(frame);

		if (!capture)
		{
			std::cout << "Can't read from feed" << std::endl;
			break;
		}

		imshow("Test", frame);


		//Manual way to break our loop if stuck
		char c = (char)waitKey(10);
		if (c == 27) { break; } 
	}
	return 0;
}
