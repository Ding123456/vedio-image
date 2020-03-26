#include <iostream>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#/*pragma comment(lib, "ml.lib")
#pragma comment(lib, "cv.lib")
#pragma comment(lib, "cvaux.lib")
#pragma comment(lib, "cvcam.lib")
#pragma comment(lib, "cxcore.lib")
#pragma comment(lib, "cxts.lib")
#pragma comment(lib, "highgui.lib")
#pragma comment(lib, "cvhaartraining.lib")*/

int main()
{
	CvCapture *capture = NULL;
	IplImage *frame = NULL;
	char *AviFileName = "E:\\大论文视频序列202001\\20200114_5.mp4";//视频的目录
	char *AviSavePath = "E:\\大论文实验图\\20200114_5";//图片保存的位置
	const int jiange = 1;//间隔两帧保存一次图片
	capture = cvCaptureFromAVI(AviFileName);
	cvNamedWindow("AVI player", 1);
	int count_tmp = 0;//计数总帧数
	char tmpfile[100] = { '\0' };
	while (true)
	{
		if (cvGrabFrame(capture))
		{
			if (count_tmp % jiange == 0)
			{
				frame = cvRetrieveFrame(capture);
				cvShowImage("AVI player", frame);//显示当前帧
				sprintf_s(tmpfile, "%s//%d.jpg", "E:\\大论文实验图\\20200114_5", count_tmp);//使用帧号作为图片名
				cvSaveImage(tmpfile, frame);
			}
			if (cvWaitKey(10) >= 0) //延时
				break;
			++count_tmp;
		}
		else
		{
			break;
		}
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("AVI player");
	std::cout << "总帧数" << count_tmp << std::endl;
	return 0;
}
