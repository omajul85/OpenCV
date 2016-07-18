#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Transformation using LUT (Look Up Table)
int main( int argc, char** argv )
{
	char imageName[] = "/home/omajul/workspace/images/margarita.jpg";
	Mat src;
	src = imread( imageName, 1 );

	if(!src.data )
	{
		cout << " No image data \n " << endl;
		return -1;
	}

	// Define the transformation table
	Mat inv(1, 256, CV_8U);
	Mat sqr(1, 256, CV_8U);

	for (int i = 0; i < 256; i++){
		// Inverse function
		inv.at<uchar>(i) = 255 - i;

		// square root function
		sqr.at<uchar>(i) = pow((float)i * 255, (float)(1 / 2.0));
	}

	// Calculation of the output images

	Mat dst_inv, dst_sqr;
	LUT(src, inv, dst_inv);
	LUT(src, sqr, dst_sqr);

	namedWindow( "Original", CV_WINDOW_AUTOSIZE );
	imshow( "Original", src );
	namedWindow( "Inverse", CV_WINDOW_AUTOSIZE );
	imshow( "Inverse", dst_inv );
	namedWindow( "Square root", CV_WINDOW_AUTOSIZE );
	imshow( "Square root", dst_sqr );

	waitKey(0);
	return 0;
}
