#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Calculates the Histogram
int main( int argc, char** argv )
{
	char imageName[] = "/home/omajul/workspace/images/cartagena.jpg";
	Mat src;
	src = imread( imageName, 1 );

	if(!src.data )
	{
		cout << " No image data \n " << endl;
		return -1;
	}

	// Separate the color image in their 3 components R, G and B
	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	// Histrogram Calculation

	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	bool uniform = true;
	bool accumulate = false;

	Mat b_hist, r_hist, g_hist;

	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	// Plot the histograms
	int hist_width = 512; int hist_height = 400;
	int bin_w = cvRound((double)hist_width / histSize);

	Mat histImage(hist_height, hist_width, CV_8UC3, Scalar(0, 0, 0));

	// Normalize the result to { 0, histImage.rows }
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	// Plot the histogram for each channel
	for(int i = 1; i < histSize; i++){
		line(histImage, Point(bin_w*(i-1), hist_height - cvRound(b_hist.at<float>(i-1))),
				Point(bin_w*(i), hist_height - cvRound(b_hist.at<float>(i))),
				Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i-1), hist_height - cvRound(g_hist.at<float>(i-1))),
						Point(bin_w*(i), hist_height - cvRound(g_hist.at<float>(i))),
						Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i-1), hist_height - cvRound(r_hist.at<float>(i-1))),
						Point(bin_w*(i), hist_height - cvRound(r_hist.at<float>(i))),
						Scalar(0, 0, 255), 2, 8, 0);
	}

	namedWindow( "Original", CV_WINDOW_AUTOSIZE );
	imshow( "Original", src );
	namedWindow( "Histogram", CV_WINDOW_AUTOSIZE );
	imshow( "Histogram", histImage );

	waitKey(0);
	return 0;
}
