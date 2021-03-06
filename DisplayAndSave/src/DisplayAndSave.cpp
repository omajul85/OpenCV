#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main( int argc, char** argv )
{
	char imageName[] = "/home/omajul/workspace/images/cartagena.jpg";
	Mat image;
	image = imread( imageName, 1 );

	if(!image.data )
	{
		cout << " No image data \n " << endl;
		return -1;
	}

	Mat gray_image;
	cvtColor( image, gray_image, CV_BGR2GRAY );

	imwrite( "/home/omajul/workspace/images/Gray_Image.jpg", gray_image );
	namedWindow( imageName, CV_WINDOW_AUTOSIZE );
	namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

	imshow( imageName, image );
	imshow( "Gray image", gray_image );

	waitKey(0);
	return 0;
}
