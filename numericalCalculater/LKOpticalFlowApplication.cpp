#include "stdafx.h"
#include "LKOpticalFlowApplication.h"


LKOpticalFlowApplication::LKOpticalFlowApplication()
{
}


LKOpticalFlowApplication::~LKOpticalFlowApplication()
{
}



//////////////////////    opt  ////////////////


using namespace std;
LucasKanadeTracker::LucasKanadeTracker(const int windowRadius, bool usePyr)
	:window_radius(windowRadius), isusepyramid(usePyr)
{

}


LucasKanadeTracker::~LucasKanadeTracker()
{
	for (int i = 0; i < max_pyramid_layer; i++)
	{
		if (pre_pyr[i])
			delete[]pre_pyr[i];
		if (next_pyr[i])
			delete[]next_pyr[i];
	}
	delete[]pre_pyr;
	delete[]next_pyr;
	if (height)
		delete[]height;
	if (width)
		delete[]width;
}


void LucasKanadeTracker::lowpass_filter(BYTE*&src, const int H, const int W, BYTE*&smoothed)
{
	//tackle with border
	for (int i = 0; i < H; i++)
	{
		smoothed[i*W] = src[i*W];
		smoothed[i*W + W - 1] = src[i*W + W - 1];
	}
	for (int i = 0; i < W; i++)
	{
		smoothed[i] = src[i];
		smoothed[(H - 1)*W + i] = src[(H - 1)*W + i];
	}

	for (int i = 1; i < H - 1; i++)
		for (int j = 1; j < W - 1; j++)
		{
			double re = 0;
			re += src[i*W + j] * 0.25;
			re += src[(i - 1)*W + j] * 0.125;
			re += src[i*W + j + 1] * 0.125;
			re += src[i*W + j - 1] * 0.125;
			re += src[(i + 1)*W + j] * 0.125;
			re += src[(i - 1)*W + j - 1] * 0.0625;
			re += src[(i + 1)*W + j - 1] * 0.0625;
			re += src[(i - 1)*W + j + 1] * 0.0625;
			re += src[(i + 1)*W + j + 1] * 0.0625;
			smoothed[i*W + j] = BYTE(re);
		}
	delete[]src;
	src = smoothed;
}


void LucasKanadeTracker::get_info(const int nh, const int nw)
{
	original_imgH = nh;
	original_imgW = nw;
	if (isusepyramid)
		get_max_pyramid_layer();
	else
		max_pyramid_layer = 1;
	pre_pyr = new BYTE*[max_pyramid_layer];
	next_pyr = new BYTE*[max_pyramid_layer];
	height = new int[max_pyramid_layer];
	width = new int[max_pyramid_layer];
	height[0] = nh;
	width[0] = nw;
}
void LucasKanadeTracker::get_target(POINT*target, int n)
{
	this->target = new DBPoint[n];
	endin = new DBPoint[n];
	for (int i = 0; i < n; i++)
	{
		this->target[i].x = target[i].x;
		this->target[i].y = target[i].y;
	}
	numofpoint = n;
}

BYTE*&LucasKanadeTracker::get_pyramid(int th)
{
	return pre_pyr[th];
}
POINT LucasKanadeTracker::get_result()
{
	POINT pp;
	pp.x = target[0].x;
	pp.y = target[0].y;
	return pp;
}
void LucasKanadeTracker::get_pre_frame(BYTE*&gray)//use only at the beginning
{
	pre_pyr[0] = gray;
	build_pyramid(pre_pyr);
	//save_gray("1.bmp", pre_pyr[1], height[1], width[1]);
}

void  LucasKanadeTracker::discard_pre_frame()
{
	//we don't new memory for original data,so we don't delete it here
	for (int i = 0; i < max_pyramid_layer; i++)
		delete[]pre_pyr[i];
}
//set the next frame as pre_frame,must dicard pre_pyr in advance
void  LucasKanadeTracker::get_pre_frame()
{
	for (int i = 0; i < max_pyramid_layer; i++)
		pre_pyr[i] = next_pyr[i];
}
//use every time,must after using get_pre_frame(BYTE**pyr)
void  LucasKanadeTracker::get_next_frame(BYTE*&gray)
{
	next_pyr[0] = gray;
	build_pyramid(next_pyr);
	//save_gray("1.bmp", next_pyr[1], height[1], width[1]);
}

void LucasKanadeTracker::pyramid_down(BYTE*&src_gray_data,
	const int src_h, const int src_w, BYTE*& dst, int&dst_h, int&dst_w)
{
	dst_h = src_h / 2;
	dst_w = src_w / 2;
	int ii = height[1];
	int hh = width[1];
	assert(dst_w > 3 && dst_h > 3);
	//BYTE*smoothed = new BYTE[src_h*src_w];
	dst = new BYTE[dst_h*dst_w];
	//lowpass_filter(src_gray_data, src_h, src_w,smoothed);
	for (int i = 0; i < dst_h - 1; i++)
		for (int j = 0; j < dst_w - 1; j++)
		{
			int srcY = 2 * i + 1;
			int srcX = 2 * j + 1;
			double re = src_gray_data[srcY*src_w + srcX] * 0.25;
			re += src_gray_data[(srcY - 1)*src_w + srcX] * 0.125;
			re += src_gray_data[(srcY + 1)*src_w + srcX] * 0.125;
			re += src_gray_data[srcY*src_w + srcX - 1] * 0.125;
			re += src_gray_data[srcY*src_w + srcX + 1] * 0.125;
			re += src_gray_data[(srcY - 1)*src_w + srcX + 1] * 0.0625;
			re += src_gray_data[(srcY - 1)*src_w + srcX - 1] * 0.0625;
			re += src_gray_data[(srcY + 1)*src_w + srcX - 1] * 0.0625;
			re += src_gray_data[(srcY + 1)*src_w + srcX + 1] * 0.0625;
			dst[i*dst_w + j] = re;
		}
	for (int i = 0; i < dst_h; i++)
		dst[i*dst_w + dst_w - 1] = dst[i*dst_w + dst_w - 2];
	for (int i = 0; i < dst_w; i++)
		dst[(dst_h - 1)*dst_w + i] = dst[(dst_h - 2)*dst_w + i];
}

//bilinear interplotation
double LucasKanadeTracker::get_subpixel(BYTE*&src, int h, int w, const DBPoint& point)
{
	int floorX = floor(point.x);
	int floorY = floor(point.y);

	double fractX = point.x - floorX;
	double fractY = point.y - floorY;

	return ((1.0 - fractX) * (1.0 - fractY) * src[floorX + w* floorY])
		+ (fractX * (1.0 - fractY) * src[floorX + 1 + floorY*w])
		+ ((1.0 - fractX) * fractY * src[floorX + (floorY + 1)*w])
		+ (fractX * fractY * src[floorX + 1 + (floorY + 1)*w]);
}


void LucasKanadeTracker::get_max_pyramid_layer()
{
	int layer = 0;
	int windowsize = 2 * window_radius + 1;
	int temp = original_imgH > original_imgW ?
		original_imgW : original_imgH;
	if (temp > ((1 << 4) * 2 * windowsize))
	{
		max_pyramid_layer = 5;
		return;
	}
	temp = double(temp) / 2;
	while (temp > 2 * windowsize)
	{
		layer++;
		temp = double(temp) / 2;
	}
	max_pyramid_layer = layer;
}

void LucasKanadeTracker::build_pyramid(BYTE**&pyramid)
{
	for (int i = 1; i < max_pyramid_layer; i++)
	{
		pyramid_down(pyramid[i - 1], height[i - 1],
			width[i - 1], pyramid[i], height[i], width[i]);
	}
}

void LucasKanadeTracker::run_single_frame()
{
	char*state = NULL;
	lucaskanade(pre_pyr, next_pyr, target, endin, numofpoint, state);
	for (int i = 0; i < numofpoint; i++)
	{
		target[i].x = endin[i].x;
		target[i].y = endin[i].y;
	}

}

void LucasKanadeTracker::lucaskanade(BYTE**&frame_pre, BYTE**&frame_cur,
	DBPoint*& start, DBPoint*& finish, unsigned int point_nums, char*state)
{

	double*derivativeXs = new double
		[(2 * window_radius + 1)*(2 * window_radius + 1)];
	double*derivativeYs = new double
		[(2 * window_radius + 1)*(2 * window_radius + 1)];
	for (int i = 0; i < point_nums; i++)
	{
		double g[2] = { 0 };
		double finalopticalflow[2] = { 0 };

		memset(derivativeXs, 0, sizeof(double)*
			(2 * window_radius + 1)*(2 * window_radius + 1));

		memset(derivativeYs, 0, sizeof(double)*
			(2 * window_radius + 1)*(2 * window_radius + 1));

		for (int j = max_pyramid_layer - 1; j >= 0; j--)
		{
			DBPoint curpoint;
			curpoint.x = start[i].x / pow(2.0, j);
			curpoint.y = start[i].y / pow(2.0, j);
			double Xleft = curpoint.x - window_radius;
			double Xright = curpoint.x + window_radius;
			double Yleft = curpoint.y - window_radius;
			double Yright = curpoint.y + window_radius;

			double gradient[4] = { 0 };
			int cnt = 0;
			for (double xx = Xleft; xx < Xright + 0.01; xx += 1.0)
				for (double yy = Yleft; yy < Yright + 0.01; yy += 1.0)
				{
					assert(xx < 1000 && yy < 1000 && xx >= 0 && yy >= 0);
					double derivativeX = get_subpixel(frame_pre[j],
						height[j], width[j], DBPoint(xx + 1.0, yy)) -
						get_subpixel(frame_pre[j], height[j],
							width[j], DBPoint(xx - 1.0, yy));
					derivativeX /= 2.0;

					double t1 = get_subpixel
					(frame_pre[j], height[j], width[j], DBPoint(xx, yy + 1.0));
					double t2 = get_subpixel(frame_pre[j], height[j],
						width[j], DBPoint(xx, yy - 1.0));
					double derivativeY = (t1 - t2) / 2.0;

					derivativeXs[cnt] = derivativeX;
					derivativeYs[cnt++] = derivativeY;
					gradient[0] += derivativeX * derivativeX;
					gradient[1] += derivativeX * derivativeY;
					gradient[2] += derivativeX * derivativeY;
					gradient[3] += derivativeY * derivativeY;
				}
			double gradient_inv[4] = { 0 };
			ContraryMatrix(gradient, gradient_inv, 2);

			double opticalflow[2] = { 0 };
			int max_iter = 50;
			double opticalflow_residual = 1;
			int iteration = 0;
			while (iteration<max_iter&&opticalflow_residual>0.00001)
			{
				iteration++;
				double mismatch[2] = { 0 };
				cnt = 0;
				for (double xx = Xleft; xx < Xright + 0.001; xx += 1.0)
					for (double yy = Yleft; yy < Yright + 0.001; yy += 1.0)
					{
						assert(xx < 1000 && yy < 1000 && xx >= 0 && yy >= 0);
						double nextX = xx + g[0] + opticalflow[0];
						double nextY = yy + g[1] + opticalflow[1];
						assert(nextX < 1000 && nextY < 1000 && nextX >= 0 && nextY >= 0);
						double pixelDifference = (get_subpixel(frame_pre[j],
							height[j], width[j], DBPoint(xx, yy))
							- get_subpixel(frame_cur[j], height[j],
								width[j], DBPoint(nextX, nextY)));
						mismatch[0] += pixelDifference*derivativeXs[cnt];
						mismatch[1] += pixelDifference*derivativeYs[cnt++];
					}
				double temp_of[2];
				matrixMul(gradient_inv, 2, 2, mismatch, 2, 1, temp_of);
				opticalflow[0] += temp_of[0];
				opticalflow[1] += temp_of[1];
				opticalflow_residual = abs(temp_of[0]) + abs(temp_of[1]);
			}
			if (j == 0)
			{
				finalopticalflow[0] = opticalflow[0];
				finalopticalflow[1] = opticalflow[1];
			}
			else
			{
				g[0] = 2 * (g[0] + opticalflow[0]);
				g[1] = 2 * (g[1] + opticalflow[1]);
			}
		}
		finalopticalflow[0] += g[0];
		finalopticalflow[1] += g[1];
		finish[i].x = start[i].x + finalopticalflow[0];
		finish[i].y = start[i].y + finalopticalflow[1];
	}
	delete[]derivativeXs, derivativeYs;
}



//matrix inverse
void LucasKanadeTracker::ContraryMatrix(double *pMatrix, double * _pMatrix, int dim)
{
	double *tMatrix = new double[2 * dim*dim];
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++)
			tMatrix[i*dim * 2 + j] = pMatrix[i*dim + j];
	}
	for (int i = 0; i < dim; i++) {
		for (int j = dim; j < dim * 2; j++)
			tMatrix[i*dim * 2 + j] = 0.0;
		tMatrix[i*dim * 2 + dim + i] = 1.0;
	}
	//Initialization over!   
	for (int i = 0; i < dim; i++)//Process Cols   
	{
		double base = tMatrix[i*dim * 2 + i];
		if (fabs(base) < 1E-300) {
			// AfxMessageBox("求逆矩阵过程中被零除，无法求解!" );
			_ASSERTE(-1);//throw exception
			exit(0);
		}
		for (int j = 0; j < dim; j++)//row   
		{
			if (j == i) continue;
			double times = tMatrix[j*dim * 2 + i] / base;
			for (int k = 0; k < dim * 2; k++)//col   
			{
				tMatrix[j*dim * 2 + k] = tMatrix[j*dim * 2 + k] - times*tMatrix[i*dim * 2 + k];
			}
		}
		for (int k = 0; k < dim * 2; k++) {
			tMatrix[i*dim * 2 + k] /= base;
		}
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
			_pMatrix[i*dim + j] = tMatrix[i*dim * 2 + j + dim];
	}
	delete[] tMatrix;
}

bool LucasKanadeTracker::matrixMul(double *src1, int height1, int width1, double *src2, int height2, int width2, double *dst)
{
	int i, j, k;
	double sum = 0;
	double *first = src1;
	double *second = src2;
	double *dest = dst;
	int Step1 = width1;
	int Step2 = width2;

	if (src1 == NULL || src2 == NULL || dest == NULL || height2 != width1)
		return false;

	for (j = 0; j < height1; j++)
	{
		for (i = 0; i < width2; i++)
		{
			sum = 0;
			second = src2 + i;
			for (k = 0; k < width1; k++)
			{
				sum += first[k] * (*second);
				second += Step2;
			}
			dest[i] = sum;
		}
		first += Step1;
		dest += Step2;
	}
	return true;
}





//#endif







///////////////////////////    bmp.c  //////////////


#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#include "BMP.h"

#define BMP_SIZE_FILEHEADER 14
#define BMP_SIZE_INFOHEADER 40

#define BMP_COLOR_BITS_24 24
#define BMP_COLOR_BITS_32 32


static unsigned int uInt16Number(unsigned char buf[2]) {
	return (buf[1] << 8) | buf[0];
}

static unsigned int uInt32Number(unsigned char buf[4]) {
	unsigned numb = buf[3];
	numb = (numb << 8) | buf[2];
	numb = (numb << 8) | buf[1];
	numb = (numb << 8) | buf[0];
	return numb;
}

static void IntTo2Bytes(int val, unsigned char buf[2]) {
	buf[0] = (unsigned char)val;
	buf[1] = (unsigned char)(val >> 8);
}

static void IntTo4Bytes(int val, unsigned char buf[4]) {
	buf[0] = (unsigned char)val;
	buf[1] = (unsigned char)(val >> 8);
	buf[2] = (unsigned char)(val >> 16);
	buf[3] = (unsigned char)(val >> 24);
}


static int ReadFileHeader(FILE* f, int* bitmap_pos) {

	unsigned char header[BMP_SIZE_FILEHEADER];
	BMPHEAD bmp_head;

	int numb = 0;
	int offset = 0;

	if (fseek(f, 0, SEEK_SET))
		return -1;
	//读取bmp head信息
	numb = fread(header, BMP_SIZE_FILEHEADER, 1, f);
	if (numb != 1)
		return -2;
	// 0 - 1
	if (header[0] != 'B' || header[1] != 'M')
		return -3;
	bmp_head.type[0] = header[0];
	bmp_head.type[1] = header[1];

	// 2 - 5
	bmp_head.size = uInt32Number(header + 2);
	// 6 - 7
	// 8 - 9

	// 10 - 13
	offset = uInt32Number(header + 10);
	if (offset != 54)
		return -4;

	*bitmap_pos = offset;
	return 0;
}

static int ReadFileInfoHead(FILE* f, IMAGE * img) {

	unsigned char header[BMP_SIZE_INFOHEADER];
	BMPINFOHEAD bmp_info_head;

	int numb = 0;

	if (fseek(f, BMP_SIZE_FILEHEADER, SEEK_SET))
		return -1;
	//读取bmp info head信息
	numb = fread(header, BMP_SIZE_INFOHEADER, 1, f);
	if (numb != 1)
		return -2;

	// 14 - 17
	bmp_info_head.selfSize = uInt32Number(header);
	if (bmp_info_head.selfSize != 40)
		return -3;

	// 18 - 21
	bmp_info_head.bitWidth = (long)uInt32Number(header + 4);
	// 22 - 25
	bmp_info_head.bitHeight = (long)uInt32Number(header + 8);
	// 26 - 27
	bmp_info_head.bitPlanes = (unsigned short)uInt16Number(header + 12);
	// 28 - 29
	bmp_info_head.pixelBitCount = (unsigned short)uInt16Number(header + 14);
	// 30 - 33
	bmp_info_head.compression = uInt32Number(header + 16);
	// 34 - 37
	bmp_info_head.sizeImage = uInt32Number(header + 20);
	// 38 - 41
	bmp_info_head.pixelXPerMeter = (long)uInt32Number(header + 24);
	// 42 - 45
	bmp_info_head.pixelYPerMeter = (long)uInt32Number(header + 28);
	// 46 - 49
	bmp_info_head.colorUsed = uInt32Number(header + 32);
	// 50 - 53
	bmp_info_head.colorImportant = uInt32Number(header + 36);

	img->width = bmp_info_head.bitWidth;
	img->height = bmp_info_head.bitHeight;

	return (int)(bmp_info_head.pixelBitCount);
}

int LoadBMP(const char* file, IMAGE* out_img, BITDATATYPE bit_data_type) {

	FILE* f;
	int bitmap_pos;
	int n_bits;

	int flErr = 0;

	fopen_s(&f, file, "rb");

	if (!f)
		return -11;

	if (out_img == NULL)
		return -12;

	if (0 > (flErr = ReadFileHeader(f, &bitmap_pos))) {
		fclose(f);
		return flErr;
	}

	n_bits = ReadFileInfoHead(f, out_img);

	if (n_bits == BMP_COLOR_BITS_24) {
		int rgb_size;
		int rgba_size;
		unsigned char* rgb;
		int y;
		unsigned char* line;
		int rest_4;

		if (fseek(f, bitmap_pos, SEEK_SET)) {
			fclose(f);
			return -16;
		}

		rgb_size = 3 * out_img->width;
		rgba_size = 4 * out_img->width;

		rest_4 = rgb_size % 4;
		if (rest_4 > 0)
			rgb_size += 4 - rest_4;

		if (bit_data_type == 1)
		{
			out_img->channels = 4;
			out_img->data = (unsigned char*)malloc(out_img->width * out_img->height * 4);

			if (out_img->data == NULL)
				return -17;

			rgb = (unsigned char*)malloc(rgb_size);

			if (NULL == rgb)
				return -18;

			for (y = out_img->height - 1; y >= 0; y--) {
				int numb = 0;
				int x = 0;

				numb = fread(rgb, rgb_size, 1, f);
				if (numb != 1) {
					fclose(f);
					free(rgb);
					return -19;
				}

				numb = 0;
				line = out_img->data + out_img->width * 4 * y;
				for (x = 0; x < out_img->width; x++) {
					line[3] = 255;
					line[2] = rgb[numb++];
					line[1] = rgb[numb++];
					line[0] = rgb[numb++];
					line += 4;
				}
			}
		}
		else if (bit_data_type == 2)
		{
			out_img->channels = 3;
			out_img->data = (unsigned char*)malloc(out_img->width * out_img->height * 3);

			if (out_img->data == NULL)
				return -17;

			rgb = (unsigned char*)malloc(rgb_size);

			if (NULL == rgb)
				return -18;

			for (y = out_img->height - 1; y >= 0; y--) {
				int numb = 0;
				int x = 0;

				numb = fread(rgb, rgb_size, 1, f);
				if (numb != 1) {
					fclose(f);
					free(rgb);
					return -19;
				}

				numb = 0;
				line = out_img->data + out_img->width * 3 * y;
				for (x = 0; x < out_img->width; x++) {
					line[2] = rgb[numb++];
					line[1] = rgb[numb++];
					line[0] = rgb[numb++];
					line += 3;
				}
			}
		}
		fclose(f);
		free(rgb);
	}
	else if (n_bits == BMP_COLOR_BITS_32)
	{
		int rgba_size;
		unsigned char* rgba;
		int y;
		unsigned char* line;

		if (fseek(f, bitmap_pos, SEEK_SET)) {
			fclose(f);
			return -16;
		}

		rgba_size = 4 * out_img->width;
		if (bit_data_type == 1)
		{
			out_img->channels = 4;
			out_img->data = (unsigned char*)malloc(out_img->width * out_img->height * 4);

			if (out_img->data == NULL)
				return -17;

			rgba = (unsigned char*)malloc(rgba_size);

			if (NULL == rgba)
				return -18;

			for (y = out_img->height - 1; y >= 0; y--) {
				int numb = 0;
				int x = 0;

				numb = fread(rgba, rgba_size, 1, f);
				if (numb != 1) {
					fclose(f);
					free(rgba);
					return -19;
				}

				numb = 0;
				line = out_img->data + out_img->width * 4 * y;
				for (x = 0; x < out_img->width; x++) {
					line[2] = rgba[numb++];//B
					line[1] = rgba[numb++];//G
					line[0] = rgba[numb++];//R
					line[3] = rgba[numb++];//A
					line += 4;
				}
			}
		}
		else if (bit_data_type == 2)
		{
			out_img->channels = 3;
			out_img->data = (unsigned char*)malloc(out_img->width * out_img->height * 3);

			if (out_img->data == NULL)
				return -17;

			rgba = (unsigned char*)malloc(rgba_size);

			if (NULL == rgba)
				return -18;

			for (y = out_img->height - 1; y >= 0; y--) {
				int numb = 0;
				int x = 0;

				numb = fread(rgba, rgba_size, 1, f);
				if (numb != 1) {
					fclose(f);
					free(rgba);
					return -19;
				}

				numb = 0;
				line = out_img->data + out_img->width * 3 * y;
				for (x = 0; x < out_img->width; x++) {
					line[2] = rgba[numb++];//B
					line[1] = rgba[numb++];//G
					line[0] = rgba[numb++];//R
					line += 3;
					numb++;
				}
			}
		}
		fclose(f);
		free(rgba);
	}
	else {
		return -20;
	}
	return 0;
}

static int WriteFileHeader(FILE* f, IMAGE * in_img, BITDATATYPE bit_data_type)
{
	unsigned char header[BMP_SIZE_FILEHEADER];
	int imgWidth, imgHeight;
	int imageSize;

	int numb = 0;
	int offset = 0;

	if (fseek(f, 0, SEEK_SET))
		return -1;

	header[0] = 'B';
	header[1] = 'M';

	imgWidth = in_img->width;
	imgHeight = in_img->height;

	if (bit_data_type == 1)
	{
		imageSize = imgWidth * 4 * imgHeight + BMP_SIZE_FILEHEADER + BMP_SIZE_INFOHEADER;
	}
	else if (bit_data_type == 2)
	{
		int rgbSize;
		int rest_4;
		rgbSize = imgWidth * 3;
		rest_4 = rgbSize % 4;
		if (rest_4 > 0)
			rgbSize += 4 - rest_4;
		imageSize = rgbSize * imgHeight + BMP_SIZE_FILEHEADER + BMP_SIZE_INFOHEADER;
	}
	IntTo4Bytes(imageSize, header + 2);
	IntTo4Bytes(0, header + 6);
	IntTo4Bytes((BMP_SIZE_FILEHEADER + BMP_SIZE_INFOHEADER), header + 10);

	//读取bmp head信息
	numb = fwrite(header, BMP_SIZE_FILEHEADER, 1, f);
	if (numb != 1)
		return -2;

	return 0;
}

static int WriteFileInfoHead(FILE* f, IMAGE * in_img, BITDATATYPE bit_data_type) {

	unsigned char header[BMP_SIZE_INFOHEADER];
	int imageSize = 0;
	int numb = 0;

	if (fseek(f, BMP_SIZE_FILEHEADER, SEEK_SET))
		return -1;
	// 14- 17
	IntTo4Bytes(BMP_SIZE_INFOHEADER, header);
	// 18 - 21 
	IntTo4Bytes(in_img->width, header + 4);
	// 22 - 25
	IntTo4Bytes(in_img->height, header + 8);
	// 26 - 27
	IntTo2Bytes(1, header + 12);
	// 28 - 29
	if (bit_data_type == 1)
	{
		IntTo2Bytes(32, header + 14);
	}
	else if (bit_data_type == 2)
	{
		IntTo2Bytes(24, header + 14);
	}
	// 30 - 33
	IntTo4Bytes(0, header + 16);
	// 34 - 37
	if (bit_data_type == 1)
	{
		imageSize = in_img->width * 4 * in_img->height;
	}
	else if (bit_data_type == 2)
	{
		int rgbSize;
		int rest_4;
		rgbSize = in_img->width * 3;
		rest_4 = rgbSize % 4;
		if (rest_4 > 0)
			rgbSize += 4 - rest_4;
		imageSize = rgbSize * in_img->height;
	}
	IntTo4Bytes(imageSize, header + 20);
	// 38 - 41
	IntTo4Bytes(0, header + 24);
	// 42 - 45
	IntTo4Bytes(0, header + 28);
	// 46 - 49
	IntTo4Bytes(0, header + 32);
	// 50 - 53
	IntTo4Bytes(0, header + 36);



	numb = fwrite(header, BMP_SIZE_INFOHEADER, 1, f);
	if (numb != 1)
		return -2;

	return 0;
}
int WriteBMP(const char * file, IMAGE * in_img, BITDATATYPE bit_data_type) {
	FILE* f;

	int flErr = 0;

	fopen_s(&f, file, "wb");

	if (!f)
		return -1;

	if (in_img == NULL)
		return -2;

	if (0 != WriteFileHeader(f, in_img, bit_data_type)) {
		fclose(f);
		return -3;
	}

	if (0 != WriteFileInfoHead(f, in_img, bit_data_type)) {
		fclose(f);
		return -4;
	}


	if (bit_data_type == 2) {
		int rgb_size;
		unsigned char * rgb;
		int y;
		unsigned char* line;
		int rest_4;

		rgb_size = 3 * in_img->width;

		rest_4 = rgb_size % 4;
		if (rest_4 > 0)
			rgb_size += 4 - rest_4;


		rgb = (unsigned char *)malloc(rgb_size * in_img->height);

		if (rgb == NULL)
			return -6;

		if (in_img->channels == 4)
		{
			for (y = 0; y < in_img->height; y++) {
				int numb = 0;
				int x = 0;

				numb = in_img->width * 4 * y;
				line = rgb + rgb_size * (in_img->height - y - 1);
				for (x = 0; x < in_img->width; x++) {
					line[2] = in_img->data[numb++];
					line[1] = in_img->data[numb++];
					line[0] = in_img->data[numb++];
					line += 3;
					numb++;
				}
			}
		}
		else if (in_img->channels == 3)
		{
			for (y = 0; y < in_img->height; y++) {
				int numb = 0;
				int x = 0;

				numb = in_img->width * 3 * y;
				line = rgb + rgb_size * (in_img->height - y - 1);
				for (x = 0; x < in_img->width; x++) {
					line[2] = in_img->data[numb++];
					line[1] = in_img->data[numb++];
					line[0] = in_img->data[numb++];
					line += 3;
				}
			}
		}
		if (fseek(f, (BMP_SIZE_FILEHEADER + BMP_SIZE_INFOHEADER), SEEK_SET)) {
			fclose(f);
			return -5;
		}
		fwrite(rgb, rgb_size * in_img->height, 1, f);
		fclose(f);
		free(rgb);
	}
	else if (bit_data_type == 1)
	{
		int rgba_size;
		unsigned char * rgba;
		int y;
		unsigned char* line;
		rgba_size = 4 * in_img->width;


		rgba = (unsigned char *)malloc(rgba_size * in_img->height);

		if (rgba == NULL)
			return -6;

		if (in_img->channels == 4)
		{
			for (y = 0; y < in_img->height; y++) {
				int numb = 0;
				int x = 0;

				numb = in_img->width * 4 * y;
				line = rgba + rgba_size * (in_img->height - y - 1);
				for (x = 0; x < in_img->width; x++) {
					line[2] = in_img->data[numb++];//R
					line[1] = in_img->data[numb++];//G
					line[0] = in_img->data[numb++];//B
					line[3] = in_img->data[numb++];//A
					line += 4;
				}
			}
		}
		else if (in_img->channels == 3)
		{
			for (y = 0; y < in_img->height; y++) {
				int numb = 0;
				int x = 0;

				numb = in_img->width * 3 * y;
				line = rgba + rgba_size * (in_img->height - y - 1);
				for (x = 0; x < in_img->width; x++) {
					line[2] = in_img->data[numb++];
					line[1] = in_img->data[numb++];
					line[0] = in_img->data[numb++];
					line[3] = 255;
					line += 4;
				}
			}
		}
		if (fseek(f, (BMP_SIZE_FILEHEADER + BMP_SIZE_INFOHEADER), SEEK_SET)) {
			fclose(f);
			return -5;
		}
		fwrite(rgba, rgba_size * in_img->height, 1, f);
		fclose(f);
		free(rgba);
	}
	else {
		return -20;
	}
	return 0;
}
int freeImage(IMAGE * img) {
	if (img == NULL)
	{
		return -1;
	}
	if (img->data != NULL)
	{
		free(img->data);
		img->data = NULL;
		img->width = 0;
		img->height = 0;
	}
	return 0;
}



//////////////////////////////////////////////////////////////////////////   opt //////////////////

