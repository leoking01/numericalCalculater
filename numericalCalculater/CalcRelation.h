#pragma once

#include<opencv2/opencv.hpp>
using  namespace  cv;

class CalcRelation
{
public:
	CalcRelation();
	~CalcRelation();

public:
	virtual int   calcTR(Mat inutImage, Mat &  transform) = 0;

	virtual int   calcPtf4(Mat inutImage,  Point2f * ptf4 ) = 0;
};

