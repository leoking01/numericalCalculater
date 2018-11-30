#pragma once
class LKOpticalFlowApplication
{
public:
	LKOpticalFlowApplication();
	~LKOpticalFlowApplication();
};

//#ifndef _LKOF_
//#define _LKOF_

/***********Lucas-Kanade optical flow track**********/
/*****************author Marshall********************/
/**********************2015.10.14********************/
/******************version 1.0***********************/

class LucasKanadeTracker
{
	struct DBPoint
	{
		double x;
		double y;
		DBPoint(const double X, const double Y) :x(X), y(Y) {
		}
		DBPoint() {}
	};
	int*height;
	int*width;

private:
	unsigned int max_pyramid_layer;
	unsigned int original_imgH;
	unsigned int original_imgW;
	unsigned int window_radius;
	BYTE**pre_pyr;//the pyramid of previous frame image,img1_pyr[0] is of max size
	BYTE**next_pyr;//the frame after img1_pyr
	bool isusepyramid;
	DBPoint*target, *endin;
	int numofpoint;


private:
	void build_pyramid(BYTE**&original_gray);
	void lucaskanade(BYTE**&frame_pre, BYTE**&frame_cur, DBPoint*& start,
		DBPoint*& finish, unsigned int point_nums, char*state);
	void get_max_pyramid_layer();
	void pyramid_down(BYTE*&src_gray_data, const int src_h,
		const int src_w, BYTE*& dst, int&dst_h, int&dst_w);
	void lowpass_filter(BYTE*&src, const int H, const int W, BYTE*&smoothed);
	double get_subpixel(BYTE*&src, int h, int w, const DBPoint& point);
	// caculate the inverse mareix of pMatrix，the result is put into _pMatrix   
	void ContraryMatrix(double *pMatrix, double * _pMatrix, int dim);
	bool matrixMul(double *src1, int height1, int width1, double *src2, int height2, int width2, double *dst);
public:
	LucasKanadeTracker(const int windowRadius, bool usePyr);
	~LucasKanadeTracker();
	void get_pre_frame(BYTE*&gray);//use only at the beginning
	void discard_pre_frame();
	//set the next frame as pre_frame,must dicard pre_pyr in advance
	void get_pre_frame();
	//use every time,must after using get_pre_frame(BYTE**pyr)
	void get_next_frame(BYTE*&gray);
	void get_info(const int nh, const int nw);
	void get_target(POINT*target, int n);
	void run_single_frame();
	POINT get_result();
	BYTE*&get_pyramid(int th);
	int get_pyrH(int th) { return height[th]; }
	int get_pyrW(int th) { return width[th]; }
};


//#include "stdafx.h"
//#include "LucasKanadeTracker.h"


//#ifndef _BMP_H_
//#define _BMP_H_

#include <stdio.h>
#include <stdlib.h>


#include <opencv2/opencv.hpp>
using namespace  cv;


#ifdef __cplusplus
extern "C" {
#endif

	typedef enum _BIT_DATA_TYPE_ {
		BIT32 = 1,                      //读取或存储成32位
		BIT24 = 2,                      //读取或存储成24位
	}BITDATATYPE;

	typedef struct _BMPFILEHEAD_ {
		unsigned char   type[2];        //存储 'B' 'M'                    2字节
		unsigned int    size;           //位图文件大小                    4字节
		unsigned short  reserved1;      //保留字                          2字节
		unsigned short  reserved2;      //保留字                          2字节
		unsigned int    offBits;        //位图数据起始位置                4字节
	}BMPHEAD;
	typedef struct _BMPFILEINFOHEAD_ {
		unsigned int    selfSize;       //位图信息头的大小                 4字节
		long            bitWidth;       //位图的宽度,以像素为单位          4字节
		long            bitHeight;      //位图的高度,以像素为单位          4字节
		unsigned short  bitPlanes;      //目标设备的级别,必须为1           2字节
		unsigned short  pixelBitCount;  //每个像素所需的位数               2字节
		unsigned int    compression;    //位图压缩类型,0(不压缩)           4字节
		unsigned int    sizeImage;      //位图的大小,以字节为单位          4字节
		long            pixelXPerMeter; //位图的水平分辨率,每米像素数      4字节
		long            pixelYPerMeter; //位图的垂直分辨率,每米像素数      4字节
		unsigned int    colorUsed;      //位图实际使用的颜色表中的颜色数   4字节
		unsigned int    colorImportant; //位图显示过程中重要的颜色数       4字节
	}BMPINFOHEAD;
	typedef struct _IMAGE_ {
		int width;
		int height;
		int channels;
		unsigned char * data;
	}IMAGE;

	int LoadBMP(const char * file, IMAGE* out_img, BITDATATYPE bit_data_type);
	int WriteBMP(const char * file, IMAGE * in_img, BITDATATYPE bit_data_type);
	int freeImage(IMAGE * img);
#ifdef __cplusplus
}
#endif

//#endif
