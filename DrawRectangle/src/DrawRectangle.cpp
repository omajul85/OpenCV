#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Draw a rectangle
int main( int argc, char** argv )
{
	char imageName[] = "/home/omajul/workspace/images/lena.jpg";
	Mat image;
	int i,j;
	image = imread( imageName, 1 );

	if(!image.data )
	{
		cout << " No image data \n " << endl;
		return -1;
	}

	for(i = image.rows / 4; i < 3 * image.rows / 4; ++i){
		for(j = image.cols / 4; j < 3 * image.cols / 4; ++j){
			image.at<Vec3b>(Point(i,j)) = Vec3b(0, 0, 0);
		}
	}

	namedWindow( "Lena with rectangle", CV_WINDOW_AUTOSIZE );
	imshow( "Lena with rectangle", image );

	waitKey(0);
	return 0;
}
