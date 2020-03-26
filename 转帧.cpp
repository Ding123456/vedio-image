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
	char *AviFileName = "E:\\��������Ƶ����202001\\20200114_5.mp4";//��Ƶ��Ŀ¼
	char *AviSavePath = "E:\\������ʵ��ͼ\\20200114_5";//ͼƬ�����λ��
	const int jiange = 1;//�����֡����һ��ͼƬ
	capture = cvCaptureFromAVI(AviFileName);
	cvNamedWindow("AVI player", 1);
	int count_tmp = 0;//������֡��
	char tmpfile[100] = { '\0' };
	while (true)
	{
		if (cvGrabFrame(capture))
		{
			if (count_tmp % jiange == 0)
			{
				frame = cvRetrieveFrame(capture);
				cvShowImage("AVI player", frame);//��ʾ��ǰ֡
				sprintf_s(tmpfile, "%s//%d.jpg", "E:\\������ʵ��ͼ\\20200114_5", count_tmp);//ʹ��֡����ΪͼƬ��
				cvSaveImage(tmpfile, frame);
			}
			if (cvWaitKey(10) >= 0) //��ʱ
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
	std::cout << "��֡��" << count_tmp << std::endl;
	return 0;
}
