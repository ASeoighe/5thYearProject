#include <vector>
#include <stdio.h>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/core/core.hpp"

using namespace cv;
Mat myBlur(Mat input, int numberOfTimes);
std::string dirName;
String outputDirectory;
void getDirName(const String& str)
{
	size_t found;
	//cout << "Splitting: " << str << endl;
	found = str.find_last_of("/\\");
	dirName = str.substr(0, found + 1);
	//std::cout << " folder: " << str.substr(0, found) << std::endl;
	//return fileName = str.substr(found + 1);
	//std::cout << " file: " << dirName << std::endl;
}
void setOutputFile()
{
	//std::cout << " Output: " << dirName << std::endl;
	outputDirectory = dirName.append("B.png");
}
int main(int argc, char *argv[])
{
	//"C:\\Users\\G00314077\\OneDrive - GMIT\\5thYearProject-Threshold-ObjectDetection\\testImages\\PlateImages\\IrishPlates\\1.png"
	//String outDir = "C:\\Users\\G00314077\\OneDrive - GMIT\\5thYearProject-Threshold-ObjectDetection\\testImages\\PlateImages\\croppedimages\\cropped2.png";
	//String imgDir = "C:\\Users\\G00314077\\OneDrive - GMIT\\5thYearProject-Threshold-ObjectDetection\\testImages\\PlateImages\\croppedimages\\2.png";
	std::string imgDir = argv[1];
	getDirName(imgDir);
	setOutputFile();
	cv::Mat img = cv::imread(imgDir, 0);
	std::cout << "Original image size: " << img.size() << std::endl;

	// Convert RGB Mat to GRAY
	cv::Mat gray;
	//cv::cvtColor(img, gray, CV_BGR2GRAY);
	threshold(img, gray, 135, 255, THRESH_BINARY);
	gray = myBlur(gray, 2);
	//cv::imshow("Whats Going In", gray);
	//std::cout << "Gray image size: " << gray.size() << std::endl;

	// Erode image to remove unwanted noises
	int erosion_size = 5;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_CROSS,
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));
	cv::erode(gray, gray, element);

	// Scan the image searching for points and store them in a vector
	std::vector<cv::Point> points;
	cv::Mat_<uchar>::iterator it = gray.begin<uchar>();
	cv::Mat_<uchar>::iterator end = gray.end<uchar>();
	for (; it != end; it++)
	{
		if (*it)
			points.push_back(it.pos());
	}

	// From the points, figure out the size of the ROI
	int left, right, top, bottom;
	for (int i = 0; i < points.size(); i++)
	{
		if (i == 0) // initialize corner values
		{
			left = right = points[i].x;
			top = bottom = points[i].y;
		}

		if (points[i].x < left)
			left = points[i].x + 15;

		if (points[i].x > right)
			right = (points[i].x) - 3;

		if (points[i].y < top)
			top = points[i].y;

		if (points[i].y > bottom)
			bottom = points[i].y;
	}
	std::vector<cv::Point> box_points;
	box_points.push_back(cv::Point(left, top + 7));
	box_points.push_back(cv::Point(left, bottom));
	box_points.push_back(cv::Point(right, bottom));
	box_points.push_back(cv::Point(right, top + 7));

	// Compute minimal bounding box for the ROI
	// Note: for some unknown reason, width/height of the box are switched.
	RotatedRect box = minAreaRect(cv::Mat(box_points));
	std::cout << "box w:" << box.size.width << " h:" << box.size.height << std::endl;

	/*Draw bounding box in the original image (debugging purposes)*/
	Point2f vertices[4];
	box.points(vertices);
	for (int i = 0; i < 4; ++i)
	{

		line(img, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0), 5, CV_AA);
	}
	//cv::imshow("original", img);
	cv::waitKey(0);
	//waitkey(0);

	// Set the ROI to the area defined by the box
	// Note: because the width/height of the box are switched, 
	// they were switched manually in the code below:
	cv::Rect roi;
	roi.x = box.center.x - (box.size.height / 2);
	roi.y = box.center.y - (box.size.width / 2);
	roi.width = box.size.height;
	roi.height = box.size.width;
	std::cout << "roi @ " << roi.x << "," << roi.y << " " << roi.width << "x" << roi.height << std::endl;

	// Crop the original image to the defined ROI
	cv::Mat crop = img(roi);

	// Display cropped ROI
	//cv::imshow("Cropped ROI", crop);
	std::vector<int> saveType;
	saveType.push_back(CV_IMWRITE_PNG_COMPRESSION);
	saveType.push_back(9);
	imwrite(outputDirectory, crop, saveType);
	cv::waitKey(0);

	return 0;
}
Mat myBlur(Mat input, int numberOfTimes) {
	Mat sourceImage;
	Mat destImage = input.clone();
	for (int i = 0; i<numberOfTimes; i++) {
		sourceImage = destImage.clone();
		GaussianBlur(sourceImage, destImage, Size(3.0, 3.0), 0);
	}
	return destImage;
}