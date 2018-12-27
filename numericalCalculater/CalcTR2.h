#pragma once
#include "CalcRelation.h"
class CalcTR2 :
	public CalcRelation
{
public:
	CalcTR2();
	~CalcTR2();

public:
	int   calcTR(Mat inutImage, Mat &  transform)
	{


		return  0;
	}

	int   calcPtf4(Mat inutImage, Point2f * ptf4)
	{

		return 0;
	}
};

