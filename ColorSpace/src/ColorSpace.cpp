#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Color Space Transformations
int main( int argc, char** argv )
{
	char imageName[] = "/home/omajul/workspace/images/lions.jpg";
	Mat imgBGR, imgHSV;
	imgBGR = imread( imageName, 1 );

	if(!imgBGR.data )
	{
		cout << " No image data \n " << endl;
		return -1;
	}

	// Define the vector of matrix for both cases
	vector<Mat> bgr_planes;
	vector<Mat> hsv_planes;

	//Split the image in BGR components
	split(imgBGR, bgr_planes);

	// Compute the color transformation
	cvtColor(imgBGR, imgHSV, CV_BGR2HSV);

	//Split the image in HSI components
	split(imgHSV, hsv_planes);

	namedWindow( "HSV", CV_WINDOW_AUTOSIZE );
	imshow( "HSV", imgHSV );
	namedWindow( "H", CV_WINDOW_AUTOSIZE );
	imshow( "H", hsv_planes[0] );
	namedWindow( "S", CV_WINDOW_AUTOSIZE );
	imshow( "S", hsv_planes[1] );
	namedWindow( "V", CV_WINDOW_AUTOSIZE );
	imshow( "V", hsv_planes[2] );

	waitKey(0);
	return 0;
}
