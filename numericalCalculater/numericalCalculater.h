
// numericalCalculater.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#include "CommonTools.h"		// ������

// CtransMedia2YuvMfcApp: 
// �йش����ʵ�֣������ numericalCalculater.cpp
//

class CtransMedia2YuvMfcApp : public CWinApp
{
public:
	CtransMedia2YuvMfcApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CtransMedia2YuvMfcApp theApp;