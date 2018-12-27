#pragma once
#include "CalcRelation.h"
class CalcTR1 :
	public CalcRelation
{
public:
	CalcTR1();
	~CalcTR1();

public:
	int   calcTR(Mat inutImage, Mat &  transform)
	{


		return  0;
	}

	int   calcPtf4(Mat inutImage, Point2f * ptf4)
	{
		if (!inutImage.data)
		{
			return -1;
		}





		return 0;
	}
};

