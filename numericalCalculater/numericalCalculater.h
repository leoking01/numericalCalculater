
// numericalCalculater.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#include "CommonTools.h"		// ������

// CnumericalCalculaterApp: 
// �йش����ʵ�֣������ numericalCalculater.cpp
//

class CnumericalCalculaterApp : public CWinApp
{
public:
	CnumericalCalculaterApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CnumericalCalculaterApp theApp;
