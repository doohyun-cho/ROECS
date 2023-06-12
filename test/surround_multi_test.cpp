#include "../include/surround/surround_view_system.h"
#include "../include/loader/frame_loader.h"
#include "../include/initializer/initializer.h"

using namespace std;




int main(){

	Initializer iInitializer;
	Camera * pFrontCamera, * pLeftCamera, * pBackCamera, * pRightCamera;
	iInitializer.InitializeCameras(	pFrontCamera,
									pLeftCamera,
									pBackCamera,
									pRightCamera);


	pLeftCamera->BlurPose();
	pRightCamera->BlurPose();


	FrameLoader iLoader("/mnt/d/input/ROECS_dataset/full_texture" , pFrontCamera,
						pLeftCamera, pBackCamera, 
						pRightCamera);

	cout << "Load pairs" << endl;
	vector<SVPair> gPairs = iLoader.LoadFramePairs(vector<int>{0 , 1, 2  , 3 , 4});

	SurroundView iSurround(pFrontCamera, pLeftCamera, pBackCamera, pRightCamera);

	cout << "Init K_G" << endl;
	iSurround.InitK_G(1000, 1000, 0.1, 0.1);

	cout << "Finish init K_G" << endl;

	cout << "Bind images" << endl;
	iSurround.BindImagePairs(gPairs);

	cv::Mat mSurroundView = iSurround.GenerateSurroundView(0, 1000, 1000);
	cv::imshow("const cv::String &winname", mSurroundView);
	cv::waitKey(0);


	mSurroundView = iSurround.GenerateSurroundView(1, 1000, 1000);
	cv::imshow("const cv::String &winname", mSurroundView);
	cv::waitKey(0);


	mSurroundView = iSurround.GenerateSurroundView(2, 1000, 1000);
	cv::imshow("const cv::String &winname", mSurroundView);
	cv::waitKey(0);



	mSurroundView = iSurround.GenerateSurroundView(3, 1000, 1000);
	cv::imshow("const cv::String &winname", mSurroundView);
	cv::waitKey(0);

	// iSurround.OptimizePoseWithOneFrame(2);
	vector<int> gIndices = { 0 , 1   , 3 };
	iSurround.OptimizeWithMultiFrame(gIndices);

	mSurroundView = iSurround.GenerateSurroundView(0, 1000, 1000);
	cv::imshow("const cv::String &winname", mSurroundView);
	cv::waitKey(0);


	mSurroundView = iSurround.GenerateSurroundView(1, 1000, 1000);
	cv::imshow("const cv::String &winname", mSurroundView);
	cv::waitKey(0);


	mSurroundView = iSurround.GenerateSurroundView(2, 1000, 1000);
	cv::imshow("const cv::String &winname", mSurroundView);
	cv::imwrite("ROECS_2.jpg", mSurroundView);
	cv::waitKey(0);


	mSurroundView = iSurround.GenerateSurroundView(3, 1000, 1000);
	cv::imshow("const cv::String &winname", mSurroundView);
	cv::imwrite("ROECS_3.jpg", mSurroundView);
	cv::waitKey(0);


	return 0;
}