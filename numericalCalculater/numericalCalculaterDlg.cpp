
// transMedia2YuvMfcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "numericalCalculater.h"
#include "numericalCalculaterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtransMedia2YuvMfcDlg 对话框



CtransMedia2YuvMfcDlg::CtransMedia2YuvMfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TRANSMEDIA2YUVMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtransMedia2YuvMfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtransMedia2YuvMfcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtransMedia2YuvMfcDlg::OnBnClickedButton1_trans2YUV)
	ON_BN_CLICKED(IDC_BUTTON2, &CtransMedia2YuvMfcDlg::OnBnClickedButton2_test_binary_io_align_problm)
	ON_BN_CLICKED(IDC_BUTTON3, &CtransMedia2YuvMfcDlg::OnBnClickedButton3_study_fundamentalMatrix)
	ON_BN_CLICKED(IDC_BUTTON4, &CtransMedia2YuvMfcDlg::OnBnClickedButton4_optimization)
	ON_BN_CLICKED(IDC_BUTTON5, &CtransMedia2YuvMfcDlg::OnBnClickedButton5_numerical_analysis)
	ON_BN_CLICKED(IDC_BUTTON6, &CtransMedia2YuvMfcDlg::OnBnClickedButton6_numerical_opt_gaus_nuton)
	ON_BN_CLICKED(IDC_BUTTON7, &CtransMedia2YuvMfcDlg::OnBnClickedButton7_mixmizeBinaryProduct)
	ON_BN_CLICKED(IDC_BUTTON8, &CtransMedia2YuvMfcDlg::OnBnClickedButton8_function_fit_02)
	ON_BN_CLICKED(IDC_BUTTON9, &CtransMedia2YuvMfcDlg::OnBnClickedButton9_optical_flow_method)
	ON_BN_CLICKED(IDC_BUTTON10, &CtransMedia2YuvMfcDlg::OnBnClickedButton10_video2__383x383x3)
	ON_BN_CLICKED(IDC_BUTTON11, &CtransMedia2YuvMfcDlg::OnBnClickedButton11_get2Frequence)
END_MESSAGE_MAP()


// CtransMedia2YuvMfcDlg 消息处理程序

BOOL CtransMedia2YuvMfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CtransMedia2YuvMfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtransMedia2YuvMfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtransMedia2YuvMfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtransMedia2YuvMfcDlg::OnBnClickedButton1_trans2YUV()
{
	// TODO: 在此添加控件通知处理程序代码
	// 打开图片文件
	CString m_strPicPath;
	//IplImage* TheImage;
	CFileDialog dlg(true, _T("*.mp4"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		_T("video(*.mp4,*.avi,*.rmvb,*.rm,*.jpg,*.bmp)|*.mp4;*.avi;*.jpg;*.bmp;*.rmvb;*.rmvb;*.mpg;*.mov;*.dat;*.rm;*.bin;*.mkv|avi(*.avi)|*.avi;rmvb(*.rmvb)|*.rmvb|rm(*.rm)|*.rm|All files(*.*)|*.*"), NULL);//弹出选择图片对话框
	dlg.m_ofn.lpstrTitle = _T("open video");
	if (dlg.DoModal() != IDOK)
		return;
	m_strPicPath = dlg.GetPathName();
	//append_string_on_edit_controler(IDC_EDIT9, CString("文件名称显示(检查)：m_strPicPath = ") + m_strPicPath);
	//append_string_on_edit_controler(IDC_EDIT9, CString("打开视频：") + m_strPicPath);

	if (m_strPicPath.IsEmpty())
	{
		return;
	}

	//从这里开始进行转化，这是一个宏定义
	USES_CONVERSION;
	//进行转换
	char* keyChar = T2A(m_strPicPath.GetBuffer(0));
	m_strPicPath.ReleaseBuffer();
	//转化结束，进行对数据的操作
	//CString value(…………);
	//对数据进行显示
	//((CListBox*)GetDlgItem(IDC_LIST1))->AddString(value);
	//append_string_on_edit_controler(IDC_EDIT9, CString("文件名称显示(检查)：CString(str ) = ") + CString(keyChar));

	string  nameFile = string(keyChar); // "d:/video/Vivo.mp4";
	string  nameFileOut = nameFile + string(".yuv");


	AllocConsole();
	freopen("CONOUT$", "a+", stdout);


	main_ttt(nameFile, nameFileOut);
	FreeConsole();
	AfxMessageBox(_T("生成yuv数据完成。 "));
}




//using namespace std;

//#include<iostream>
//#include<fstream>
//using namespace  std;

int main_write_binaryfile_study()
{

	int count = 0x41424344;
	//write  count(DCBAECBA)   to the file.
	fstream f("liaoZhup.txt.bin", fstream::out | fstream::binary);
	f.write((char *)&count, sizeof(int));
	count++;
	f.write((char *)&count, sizeof(int));
	f.close();

	//read byte by byte.
	f.open("liaoZhup.txt.bin", fstream::in | fstream::binary);
	char ch;
	int fileSize = f.tellg();
	std::cout << "file beg pos = " << fileSize << std::endl;
	while (f.good())
	{
		fileSize = f.tellg();
		std::cout << "pos before read = " << fileSize << std::endl;
		if (f.read(&ch, sizeof(char)))
		{
			fileSize = f.tellg();
			std::cout << "pos after read= " << fileSize << std::endl;
			std::cout << "read byte = " << ch << std::endl;
		}
	}
	fileSize = f.tellg();
	std::cout << "pos after end= " << fileSize << std::endl;
	f.clear();

	//read once a int.
	f.seekg(0, ios_base::end);
	fileSize = f.tellg();
	cout << "file size = " << fileSize << std::endl;
	f.seekg(0, ios_base::beg);
	fileSize = f.tellg();
	std::cout << "file begin = " << fileSize << std::endl;
	std::cout << "****read****" << std::endl;
	while (f.good())
	{
		//if (f.read((char *)&count,sizeof(int)*10))
		if (f.read((char *)&count, sizeof(int)))
		{
			int current = f.tellg();
			std::cout << "current pos:" << dec << current << std::endl;
			std::cout << "count = " << hex << count << std::endl;
		}
	}
	int current = f.tellg();
	std::cout << "pos end of read int:" << dec << current << std::endl;
	std::cout << "****out of read****" << std::endl;
	f.close();
	return 0;
}





void CtransMedia2YuvMfcDlg::OnBnClickedButton2_test_binary_io_align_problm()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	std::cout << "This is a test info" << std::endl;




	// TODO: 在此添加控件通知处理程序代码
	fstream   of("OnBnClickedButton2_test_binary_io_align_problm.bin", ios::binary | ios::out);

	unsigned  char x1 = 2;
	int x2 = 8;

	of.write((char*)&x2, sizeof(int));
	of.write((char*)&x2, sizeof(int));
	of.write((char*)&x2, sizeof(int));
	of.write((char*)&x2, sizeof(int));


	of.write((char*)&x1, sizeof(unsigned  char));
	of.write((char*)&x1, sizeof(unsigned  char));
	of.write((char*)&x1, sizeof(unsigned  char));
	of.write((char*)&x2, sizeof(int));


	//of.write((char*)&x1, sizeof(unsigned  char));
	//of.write((char*)&x1, sizeof(unsigned  char));
	//of.write((char*)&x1, sizeof(unsigned  char));
	//of.write((char*)&x2, sizeof(int));



	of.close();

	main_write_binaryfile_study();
	std::cout << "all  finished.  " << std::endl;

	//system("pause" );
	FreeConsole();
}


//   -------------------------------     ------------ 基础矩阵  基本矩阵 ----------------    ----------------------------  



using  namespace  cv;

//------------ 各種外部変数 ----------//
double first[12][2] =
{
	{ 488.362, 169.911 },
	{ 449.488, 174.44 },
	{ 408.565, 179.669 },
	{ 364.512, 184.56 },
	{ 491.483, 122.366 },
	{ 451.512, 126.56 },
	{ 409.502, 130.342 },
	{ 365.5, 134 },
	{ 494.335, 74.544 },
	{ 453.5, 76.5 },
	{ 411.646, 79.5901 },
	{ 366.498, 81.6577 }
};

double second[12][2] =
{
	{ 526.605, 213.332 },
	{ 470.485, 207.632 },
	{ 417.5, 201 },
	{ 367.485, 195.632 },
	{ 530.673, 156.417 },
	{ 473.749, 151.39 },
	{ 419.503, 146.656 },
	{ 368.669, 142.565 },
	{ 534.632, 97.5152 },
	{ 475.84, 94.6777 },
	{ 421.16, 90.3223 },
	{ 368.5, 87.5 }
};

int main_study_fundamentalMatrix()
{
	CvMat *firstM = cvCreateMat(12, 2, CV_64FC1);
	cvSetData(firstM, first, firstM->step);

	CvMat *secondM = cvCreateMat(12, 2, CV_64FC1);
	cvSetData(secondM, second, secondM->step);

	CvMat *FMat = cvCreateMat(3, 3, CV_64FC1);

	if (cvFindFundamentalMat(firstM, secondM, FMat, CV_FM_RANSAC, 1.00, 0.99) == 0) {
		std::cerr << "Can't Get F Mat/n";
		return -1;
	}

	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x)
		{
			std::cout << CV_MAT_ELEM(*FMat, double, y, x) << " ";
		}
		std::cout << "/n";


	}

	Mat   mt(FMat);
	std::cout << "mt = " << endl << mt << endl;


	cvReleaseMat(&firstM);
	cvReleaseMat(&secondM);
	cvReleaseMat(&FMat);

	return EXIT_SUCCESS;
}


void CtransMedia2YuvMfcDlg::OnBnClickedButton3_study_fundamentalMatrix()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	std::cout << "OnBnClickedButton3_study_fundamentalMatrix :  " << std::endl;
	main_study_fundamentalMatrix();

	FreeConsole();
}


//using namespace Gdiplus;

// "cuboid.png"
void DrawCuboid(CDC *pDC)
{
	Gdiplus::Graphics graphics(pDC->m_hDC);
	Gdiplus::Point point1(50, 50); //    2       3
	Gdiplus::Point point2(100, 20);// 1      7
	Gdiplus::Point point3(200, 20);//
	Gdiplus::Point point4(50, 250);//
	Gdiplus::Point point5(150, 250);//           6
	Gdiplus::Point point6(200, 220);//4      5
	Gdiplus::Point point7(150, 50);  //
							// front :1,7,5,4
	Gdiplus::Point frontPoints[4] = { point1 , point7 , point5, point4 };
	Gdiplus::RectF frontRect((float)point1.X, (float)point1.Y,
		(float)(point7.X - point1.X),
		(float)(point5.Y - point7.Y));
	Gdiplus::LinearGradientBrush frontB(frontRect, Gdiplus::Color::Blue, Gdiplus::Color::Aqua, Gdiplus::LinearGradientModeHorizontal);// = 90.0f);//
	graphics.FillPolygon(&frontB, frontPoints, 4);
	// right :7,3,6,5
	Gdiplus::RectF rightRect((float)point7.X, (float)point7.Y,
		(float)(point3.X - point7.X),
		(float)(point5.Y - point3.Y));
	Gdiplus::Point rightPoints[4] = { point7 , point3 , point6, point5 };
	Gdiplus::LinearGradientBrush b(rightRect, Gdiplus::Color::Aqua, Gdiplus::Color::Blue, Gdiplus::LinearGradientModeHorizontal);// = 90.0f);//
	graphics.FillPolygon(&b, rightPoints, 4);
	// top :1,2,3,7
	INT count = 4;
	Gdiplus::GraphicsPath rectPath;
	Gdiplus::Point topPoints[4] = { point1 , point2 , point3, point7 };
	rectPath.AddPolygon(topPoints, count);
	//
	Gdiplus::PathGradientBrush pathBrush(&rectPath);
	//
	Gdiplus::Color cols[] = { Gdiplus::Color::Blue,Gdiplus::Color::Blue,Gdiplus::Color::Blue,Gdiplus::Color::Blue };
	pathBrush.SetSurroundColors(cols, &count);
	pathBrush.SetCenterColor(Gdiplus::Color::Aqua);
	pathBrush.SetCenterPoint(point7);
	graphics.FillPolygon(&pathBrush, topPoints, count);
	// draw  contour
	Gdiplus::Pen bluePen(Gdiplus::Color(255, 0, 0, 255), 1);
	Gdiplus::Point points[6] = { point1 , point2 , point3, point6, point5, point4 };
	graphics.DrawPolygon(&bluePen, points, 6);
	// draw 3 lines
	graphics.DrawLine(&bluePen, point1, point7);
	graphics.DrawLine(&bluePen, point7, point3);
	graphics.DrawLine(&bluePen, point5, point7);
}



void CtransMedia2YuvMfcDlg::OnBnClickedButton4_optimization()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码

	//main_study_fundamentalMatrix();
	//  IDC_STATIC1
	CDC *pDC = GetDlgItem((UINT)IDC_STATIC1)->GetDC();
	DrawCuboid(pDC);



	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	std::cout << "OnBnClickedButton4_optimization :  " << std::endl;
	FreeConsole();
}




//using  namespace   Eigen;

int  doSomeEigen()
{
	cout << "___________________________________________________" << endl;
	cout << "doSomeEigen :" << endl;
	cout << " eigen中的基本变量：  " << endl;
	Eigen::Matrix<double, 3, 3> A;               // Fixed rows and cols. Same as Matrix3d.
	Eigen::Matrix<double, 3, Eigen::Dynamic> B;         // Fixed rows, dynamic cols.
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> C;   // Full dynamic. Same as MatrixXd.
	Eigen::Matrix<double, 3, 3, Eigen::RowMajor> E;     // Row major; default is column-major.
	Eigen::Matrix3f P, Q, R;                     // 3x3 float matrix.
	Eigen::Vector3f x, y, z;                     // 3x1 float matrix.
	Eigen::RowVector3f a, b, c;                  // 1x3 float matrix.
	Eigen::VectorXd v;                           // Dynamic column vector of doubles
	double s;
	std::cout << "A = " << A << std::endl;
	return  0;
}




#define  M_PI   3.14159265

/****************************
* 本程序演示了Eigen 几何模块的使用方法
****************************/

//int main (int argc, char** argv)
int main__eigen_study_calc_001()
{
	cout << "___________________________________________________" << endl;
	cout << "main__eigen_study_calc_001 :" << endl;
	cout << "  eigen学习初步：  " << endl;
	// Eigen/Geometry 模块提供了各种旋转和平移的表示
	// 3D 旋转矩阵直接使用Matrix3d 或Matrix3f
	Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
	// 旋转向量使用AngleAxis, 它底层不直接是Matrix ，但运算可以当作矩阵（因为重载了运算符）
	Eigen::AngleAxisd rotation_vector(M_PI / 4, Eigen::Vector3d(0, 0, 1)); // 沿Z 轴旋转45 度
	std::cout.precision(3);
	std::cout << "rotation matrix =\n" << rotation_vector.matrix() << std::endl; //用matrix() 转换成矩阵
																				 // 也可以直接赋值


	rotation_matrix = rotation_vector.toRotationMatrix();
	// 用AngleAxis 可以进行坐标变换
	Eigen::Vector3d v(1, 0, 0);
	Eigen::Vector3d v_rotated = rotation_vector * v;
	std::cout << "(1,0,0) after rotation = " << v_rotated.transpose() << std::endl;
	// 或者用旋转矩阵
	v_rotated = rotation_matrix * v;
	std::cout << "(1,0,0) after rotation = " << v_rotated.transpose() << std::endl;

	// 欧拉角：可以将旋转矩阵直接转换成欧拉角
	Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); // ZYX 顺序，即yaw pitch roll序
	std::cout << "yaw pitch roll = " << euler_angles.transpose() << std::endl;

	// 欧氏变换矩阵使用Eigen::Isometry
	Eigen::Isometry3d T = Eigen::Isometry3d::Identity(); // 虽然称为3d ，实质上是4＊4 的矩阵
	T.rotate(rotation_vector); // 按照rotation_vector 进行旋转
	T.pretranslate(Eigen::Vector3d(1, 3, 4)); // 把平移向量设成(1,3,4)
	std::cout << "Transform matrix = \n" << T.matrix() << std::endl;

	// 用变换矩阵进行坐标变换
	Eigen::Vector3d v_transformed = T*v; // 相当于R*v+t
	std::cout << "v tranformed = " << v_transformed.transpose() << std::endl;

	// 对于仿射和射影变换，使用Eigen::Affine3d 和Eigen::Projective3d 即可，略

	// 四元数
	// 可以直接把AngleAxis 赋值给四元数，反之亦然
	Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
	std::cout << "quaternion = \n" << q.coeffs() << std::endl; // 请注意coeffs 的顺序是(x,y,z,w), w 为实部，前三者为虚

															   // 也可以把旋转矩阵赋给它
	q = Eigen::Quaterniond(rotation_matrix);
	std::cout << "quaternion = \n" << q.coeffs() << std::endl;
	// 使用四元数旋转一个向量，使用重载的乘法即可
	v_rotated = q*v; // 注意数学上是qvq^{-1}
	std::cout << "(1,0,0) after rotation = " << v_rotated.transpose() << std::endl;
	/**/

	return 0;
}






void CtransMedia2YuvMfcDlg::OnBnClickedButton5_numerical_analysis()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	cout << "___________________________________________________" << endl;
	//cout << "main__eigen_study_calc_001 :" << endl;
	std::cout << "OnBnClickedButton5_numerical_analysis :  " << std::endl;

	main__eigen_study_calc_001();
	doSomeEigen();

	FreeConsole();
}




// ------------------------------------  数值优化之高斯-牛顿  --------------    ---------------------------------   




// A simple demo of Gauss-Newton algorithm on a user defined function  

//#include <cstdio>  
//#include <vector>  
//#include <opencv2/core/core.hpp>  

using namespace std;
using namespace cv;

const double DERIV_STEP = 1e-5;
const int MAX_ITER = 100;


void GaussNewton(double(*Func)(const Mat &input, const Mat params), // function pointer  
	const Mat &inputs, const Mat &outputs, Mat params);

double Deriv(double(*Func)(const Mat &input, const Mat params), // function pointer  
	const Mat &input, const Mat params, int n);

// The user defines their function here  
double Func(const Mat &input, const Mat params);//  这个就是目标函数

int main_gauss_nuton()
{
	cout << "___________________________________________________" << endl;
	cout << "main_gauss_nuton: 高斯牛顿法： " << endl;
	cout << "  F = A*exp(t*B)  " << endl;
	//例子1，根据美国1815年至1885年数据，估计人口模型中的参数A和B。如下表所示，已知年份和人口总量，及人口模型方程，求方程中的参数。
	//cout << "main_gauss_nuton:" << endl;
	// For this demo we're going to try and fit to the function  
	// F = A*exp(t*B)  人口模型
	// There are 2 parameters: A B  
	int num_params = 2;

	// Generate random data using these parameters  
	int total_data = 8;

	Mat inputs(total_data, 1, CV_64F);
	Mat outputs(total_data, 1, CV_64F);

	//load observation data  
	for (int i = 0; i < total_data; i++) {
		inputs.at<double>(i, 0) = i + 1;  //load year  
	}
	//load America population  加载美国人口
	outputs.at<double>(0, 0) = 8.3;
	outputs.at<double>(1, 0) = 11.0;
	outputs.at<double>(2, 0) = 14.7;
	outputs.at<double>(3, 0) = 19.7;

	outputs.at<double>(4, 0) = 26.7;
	outputs.at<double>(5, 0) = 35.2;
	outputs.at<double>(6, 0) = 44.4;
	outputs.at<double>(7, 0) = 55.9;

	// Guess the parameters, it should be close to the true value, else it can fail for very sensitive functions!  
	Mat params(num_params, 1, CV_64F);

	//init guess  
	params.at<double>(0, 0) = 6;
	params.at<double>(1, 0) = 0.3;

	GaussNewton(Func, inputs, outputs, params);

	printf("Parameters from GaussNewton: %f %f\n", params.at<double>(0, 0), params.at<double>(1, 0));

	return 0;
}

double Func(const Mat &input, const Mat params)
{
	// Assumes input is a single row matrix  
	// Assumes params is a column matrix  

	double A = params.at<double>(0, 0);
	double B = params.at<double>(1, 0);

	double x = input.at<double>(0, 0);

	return A*exp(x*B);
}

//calc the n-th params' partial derivation ， the params are our  final target  
double Deriv(double(*Func)(const Mat &input, const Mat params), const Mat &input, const Mat params, int n)
{
	// Assumes input is a single row matrix  

	// Returns the derivative of the nth parameter  
	Mat params1 = params.clone();
	Mat params2 = params.clone();

	// Use central difference  to get derivative  
	params1.at<double>(n, 0) -= DERIV_STEP;
	params2.at<double>(n, 0) += DERIV_STEP;

	double p1 = Func(input, params1);
	double p2 = Func(input, params2);

	double d = (p2 - p1) / (2 * DERIV_STEP);

	return d;
}


void GaussNewton(double(*Func)(const Mat &input, const Mat params),
	const Mat &inputs, const Mat &outputs, Mat params)
{
	int m = inputs.rows;
	int n = inputs.cols;
	int num_params = params.rows;

	Mat r(m, 1, CV_64F); // residual matrix  
	Mat Jf(m, num_params, CV_64F); // Jacobian of Func()  
	Mat input(1, n, CV_64F); // single row input  

	double last_mse = 0;

	printf("(i, mse) = \n");
	for (int i = 0; i < MAX_ITER; i++) {
		double mse = 0;

		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				//copy Independent variable vector, the year  
				input.at<double>(0, k) = inputs.at<double>(j, k);
			}

			r.at<double>(j, 0) = outputs.at<double>(j, 0) - Func(input, params);//diff between estimate and observation population  
			mse += r.at<double>(j, 0)*r.at<double>(j, 0);

			for (int k = 0; k < num_params; k++) {
				Jf.at<double>(j, k) = Deriv(Func, input, params, k);
			}
		}

		mse /= m;

		// The difference in mse is very small, so quit  
		if (fabs(mse - last_mse) < 1e-8) {
			printf(" \n 达成：  fabs(mse - last_mse) < 1e-8 \n ");
			break;
		}

		Mat delta = ((Jf.t()*Jf)).inv() * Jf.t()*r;
		params += delta;

		//printf("%d: mse=%f\n", i, mse);  
		printf("( %d , %f ),", i, mse);

		last_mse = mse;
	}
	printf("\n");
}











void CtransMedia2YuvMfcDlg::OnBnClickedButton6_numerical_opt_gaus_nuton()
{
	// TODO: 在此添加控件通知处理程序代码

	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	cout << "___________________________________________________" << endl;
	cout << "OnBnClickedButton6_numerical_opt_gaus_nuton:" << endl;
	main_gauss_nuton();
	FreeConsole();
}


void CtransMedia2YuvMfcDlg::OnBnClickedButton7_mixmizeBinaryProduct()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	cout << "___________________________________________________" << endl;
	//cout << "main__eigen_study_calc_001 :" << endl;
	std::cout << "OnBnClickedButton7_mixmizeBinaryProduct :  " << std::endl;

	FreeConsole();
}



// -----------------------------------   GaussNewton_02    -----------------------------------------   


// A simple demo of Gauss-Newton algorithm on a user defined function  
//由于缺乏观测量，就自导自演，假设4个参数已知A = 5, B = 1, C = 10, D = 2，构造100个随机数作为x的观测值，计算相应的函数观测值。然后，利用这些观测值，反推4个参数
#include <cstdio>  
#include <vector>  
#include <opencv2/core/core.hpp>  

using namespace std;
using namespace cv;

//const double DERIV_STEP = 1e-5;
//const int MAX_ITER = 100;


void GaussNewton_02(double(*Func)(const Mat &input, const Mat params), // function pointer  
	const Mat &inputs, const Mat &outputs, Mat params);

double Deriv_02(double(*Func)(const Mat &input, const Mat params), // function pointer  
	const Mat &input, const Mat params, int n);

// The user defines their function here  
double Func_02(const Mat &input, const Mat params);

int main_function_fit_02()
{
	// For this demo we're going to try and fit to the function  
	// F = A*sin(Bx) + C*cos(Dx)  
	// There are 4 parameters: A, B, C, D  
	cout << "____________________________________________________________" << endl;
	cout << "GaussNewton_02: 高斯牛顿02： " << endl;
	cout << " aim func:  F = A*sin(Bx) + C*cos(Dx)  " << endl;
	cout << " There are 4 parameters: A, B, C, D    " << endl;
	cout << " 4 1  10 2   " << endl;
	int num_params = 4;

	// Generate random data using these parameters  
	int total_data = 100;

	double A = 5;
	double B = 1;
	double C = 10;
	double D = 2;

	Mat inputs(total_data, 1, CV_64F);
	Mat outputs(total_data, 1, CV_64F);

	for (int i = 0; i < total_data; i++) {
		double x = -10.0 + 20.0* rand() / (1.0 + RAND_MAX); // random between [-10 and 10]  
		double y = A*sin(B*x) + C*cos(D*x);

		// Add some noise  
		// y += -1.0 + 2.0*rand() / (1.0 + RAND_MAX);  

		inputs.at<double>(i, 0) = x;
		outputs.at<double>(i, 0) = y;
	}

	// Guess the parameters, it should be close to the true value, else it can fail for very sensitive functions!  
	Mat params(num_params, 1, CV_64F);

	params.at<double>(0, 0) = 1;
	params.at<double>(1, 0) = 1;
	params.at<double>(2, 0) = 8; // changing to 1 will cause it not to find the solution, too far away  
	params.at<double>(3, 0) = 1;

	GaussNewton_02(Func_02, inputs, outputs, params);

	printf("True parameters: %f %f %f %f\n", A, B, C, D);
	printf("Parameters from GaussNewton: %f %f %f %f\n", params.at<double>(0, 0), params.at<double>(1, 0),
		params.at<double>(2, 0), params.at<double>(3, 0));

	return 0;
}

double Func_02(const Mat &input, const Mat params)
{
	// Assumes input is a single row matrix  
	// Assumes params is a column matrix  

	double A = params.at<double>(0, 0);
	double B = params.at<double>(1, 0);
	double C = params.at<double>(2, 0);
	double D = params.at<double>(3, 0);

	double x = input.at<double>(0, 0);

	return A*sin(B*x) + C*cos(D*x);
}



double Deriv_02(double(*Func)(const Mat &input, const Mat params), const Mat &input, const Mat params, int n)
{
	// Assumes input is a single row matrix  

	// Returns the derivative of the nth parameter  
	Mat params1 = params.clone();
	Mat params2 = params.clone();

	// Use central difference  to get derivative  
	params1.at<double>(n, 0) -= DERIV_STEP;
	params2.at<double>(n, 0) += DERIV_STEP;

	double p1 = Func(input, params1);
	double p2 = Func(input, params2);

	double d = (p2 - p1) / (2 * DERIV_STEP);

	return d;
}

void GaussNewton_02(double(*Func)(const Mat &input, const Mat params),
	const Mat &inputs, const Mat &outputs, Mat params)
{
	int m = inputs.rows;
	int n = inputs.cols;
	int num_params = params.rows;

	Mat r(m, 1, CV_64F); // residual matrix  
	Mat Jf(m, num_params, CV_64F); // Jacobian of Func()  
	Mat input(1, n, CV_64F); // single row input  

	double last_mse = 0;

	printf("output  mse: \n");
	const  int   max_iter = 10000;//  100  
	for (int i = 0; i < max_iter; i++) {
		double mse = 0;

		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				input.at<double>(0, k) = inputs.at<double>(j, k);
			}

			r.at<double>(j, 0) = outputs.at<double>(j, 0) - Func(input, params);

			mse += r.at<double>(j, 0)*r.at<double>(j, 0);

			for (int k = 0; k < num_params; k++) {
				Jf.at<double>(j, k) = Deriv_02(Func, input, params, k);
			}
		}

		mse /= m;

		// The difference in mse is very small, so quit  
		if (fabs(mse - last_mse) < 1e-8) {
			printf("(%d, %f), ", i, mse);
			printf("达成：  fabs(mse - last_mse) < 1e-8 \n");
			break;
		}

		Mat delta = ((Jf.t()*Jf)).inv() * Jf.t()*r;
		params += delta;

		//printf("%d: mse=%f\n", i, mse);  
		if (i % 100 == 0)
			printf("(%d, %f), ", i, mse);

		last_mse = mse;
	}
	printf("\n");
}










//  以下代码来源于此
//https://blog.csdn.net/piaoxuezhong/article/details/60135153

/*
需要参数为theta：theta0，theta1
目标函数:y=theta0*x0+theta1*x1;
*/
#include <iostream>

using namespace std;
#include <iomanip>

int study_example_gradient()
{
	float matrix[4][2] = { { 1, 1 },{ 2, 1 },{ 2, 2 },{ 3, 4 } };
	float result[4] = { 5,6.99,12.02,18 };
	float theta[2] = { 0,0 };
	double  loss = 10.0;
	cout << "_______________________________________________________" << endl;
	cout << "study_example_gradient:梯度下降法：" << endl;
	cout << " ( i, theta[0] " << " , " << "theta[1],  loss  ) = " << endl;
	const    int   width = 15;
	cout.precision(width);
	double  loss_pre = 0;
	const   int   steps_max = 1.e+6;  //  10000   
	for (int i = 0; i < steps_max && loss>0.0000001; ++i)
	{
		float ErrorSum = 0.0;
		float cost[2] = { 0.0, 0.0 };
		for (int j = 0; j < 4; ++j)
		{
			float h = 0.0;
			for (int k = 0; k < 2; ++k)
			{
				h += matrix[j][k] * theta[k];
			}

			ErrorSum = result[j] - h;

			for (int k = 0; k < 2; ++k)
			{
				cost[k] = ErrorSum*matrix[j][k];
			}
		}
		for (int k = 0; k < 2; ++k)
		{
			theta[k] = theta[k] + 0.01*cost[k] / 4;
		}
		if (i % 20000 == 0)
			cout << "( " << setw(8) << i << ", " << setw(width + 2) << theta[0] << " , " << setw(width + 2) << theta[1] << " , " << setw(width + 2) << loss << " ), ";// << endl;
		loss = 0.0;
		for (int j = 0; j < 4; ++j)
		{
			double  h2 = 0.0;
			for (int k = 0; k < 2; ++k)
			{
				h2 += matrix[j][k] * theta[k];
			}
			loss += (h2 - result[j])*(h2 - result[j]);
		}
		if (i == 0)
			loss_pre += loss + 1;
		if (loss_pre == loss)
		{
			cout << "( " << setw(8) << i << ", " << setw(width + 2) << theta[0] << " , " << setw(width + 2) << theta[1] << " , " << setw(width + 2) << loss << " ), ";// << endl;
			printf("达成： loss_pre == loss \n");
			break;
		}

		loss_pre = loss;
	}
	cout << endl;
	return 0;

}

/*
需要参数为theta：theta0，theta1
目标函数:y=theta0*x0+theta1*x1;
*/
#include <iostream>
using namespace std;

int main_rand_gradient()
{
	cout << "_______________________________________________________" << endl;
	cout << "main_rand_gradient: 随机梯度下降法： " << endl;
	cout << " ( i, theta[0] " << " , " << "theta[1],  loss  ) = " << endl;
	float matrix[4][2] = { { 1, 1 },{ 2, 1 },{ 2, 2 },{ 3, 4 } };
	float result[4] = { 5,6.99,12.02,18 };
	float theta[2] = { 0,0 };
	double loss = 10.0;
	double  loss_pre = 0;
	//const  int   steps_max = 10000;   //1000  
	const   int   steps_max = 1.e+5;  //  10000   
	for (int i = 0; i<steps_max && loss>0.00001; ++i)
	{
		float ErrorSum = 0.0;
		int j = i % 4;

		float h = 0.0;
		for (int k = 0; k < 2; ++k)
		{
			h += matrix[j][k] * theta[k];
		}

		ErrorSum = result[j] - h;

		for (int k = 0; k < 2; ++k)
		{
			theta[k] = theta[k] + 0.001*(ErrorSum)*matrix[j][k];
		}
		if (i % (1000) == 0)
			cout << "( " << i << "," << theta[0] << "," << theta[1] << "," << loss << "," << loss_pre << ", " << abs(loss_pre - loss) << " ), ";// << endl;

		loss = 0.0;
		for (int j = 0; j < 4; ++j)
		{
			double sum = 0.0;
			for (int k = 0; k < 2; ++k)
			{
				sum += matrix[j][k] * theta[k];
			}
			loss += (sum - result[j])*(sum - result[j]);
		}

		// 相邻的两个永远都不会一样，而且不收敛，真是奇观。也说明了这里可能是有问题滴，嘿嘿
		if (i == 0)
			loss_pre += loss + 1;
		//printf("<  %fl ,  %fl >,", loss_pre,  loss );
		//if (abs(loss_pre - loss) <= 1.0e-6)
		if (fabs(loss_pre - loss) <= 0.00001)
		{
			cout << "( " << i << "," << theta[0] << "," << theta[1] << "," << loss << " ), ";// << endl;
			printf("达成： loss_pre == loss \n");
			break;
		}

		loss_pre = loss;
		//cout << "loss=" << loss << endl;
	}
	return 0;
}

void CtransMedia2YuvMfcDlg::OnBnClickedButton8_function_fit_02()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	main_function_fit_02();
	study_example_gradient();
	main_rand_gradient();

	FreeConsole();
}



//#include<iostream>

void calculate(unsigned char* buf)
{
	//随便添加的几个变量的定义。还没有仔细考虑是否合理。201811231531
	const  int  width = 800;
	const  int  height = 600;
	const  int  size = width*height * sizeof(int);
	uchar * prevframe = new uchar(width* height * 3);
	uchar * opticalflow = new uchar(width* height * 3);
	uchar * output = new uchar(width* height * 3);



	int Ex, Ey, Et;
	int gray1, gray2;
	int u;
	int i, j;
	memset(opticalflow, 0, width*height * sizeof(int));
	memset(output, 255, size);
	for (i = 2; i < height - 2; i++) {
		for (j = 2; j < width - 2; j++) {
			gray1 = int(((int)(buf[(i*width + j) * 3])
				+ (int)(buf[(i*width + j) * 3 + 1])
				+ (int)(buf[(i*width + j) * 3 + 2]))*1.0 / 3);
			gray2 = int(((int)(prevframe[(i*width + j) * 3])
				+ (int)(prevframe[(i*width + j) * 3 + 1])
				+ (int)(prevframe[(i*width + j) * 3 + 2]))*1.0 / 3);
			Et = gray1 - gray2;
			gray2 = int(((int)(buf[(i*width + j + 1) * 3])
				+ (int)(buf[(i*width + j + 1) * 3 + 1])
				+ (int)(buf[(i*width + j + 1) * 3 + 2]))*1.0 / 3);
			Ex = gray2 - gray1;
			gray2 = int(((int)(buf[((i + 1)*width + j) * 3])
				+ (int)(buf[((i + 1)*width + j) * 3 + 1])
				+ (int)(buf[((i + 1)*width + j) * 3 + 2]))*1.0 / 3);
			Ey = gray2 - gray1;
			Ex = ((int)(Ex / 10)) * 10;
			Ey = ((int)(Ey / 10)) * 10;
			Et = ((int)(Et / 10)) * 10;
			u = (int)((Et*10.0) / (sqrt((Ex*Ex + Ey*Ey)*1.0)) + 0.1);
			opticalflow[i*width + j] = u;
			if (abs(u) > 10) {
				output[(i*width + j) * 3] = 0;
				output[(i*width + j) * 3 + 1] = 0;
				output[(i*width + j) * 3 + 2] = 0;
			}
		}
	}
	memcpy(prevframe, buf, size);
}

//////////////////////////////////////////////////////////////////////////

/// 另一个代码
//
///

/////////////////////////////////////////////////////////////////////////////

using  namespace  cv;

int  ImgOpticalFlow(IplImage *pre_grey, IplImage *grey)
/*************************************************
Function:
Description:  光流法计算运动速度与方向
Date:   2006－6－14
Author:
Input:
Output:
Return:
Others:
*************************************************/
{
	/*    2006年的代码太久了，暂时不好改动   故而注释
	IplImage *velx = cvCreateImage(cvSize(grey->width, grey->height), IPL_DEPTH_32F, 1);
	IplImage *vely = cvCreateImage(cvSize(grey->width, grey->height), IPL_DEPTH_32F, 1);

	velx->origin = vely->origin = grey->origin;
	CvSize winSize = cvSize(5, 5);
	//cvCalcOpticalFlowLK(prev_grey, grey, winSize, velx, vely);
	cvCalcOpticalFlowPyrLK(prev_grey, grey, winSize, velx, vely);

	cvAbsDiff(grey, prev_grey, abs_img);
	cvThreshold(abs_img, abs_img, 29, 255, CV_THRESH_BINARY);

	CvScalar xc, yc;
	for (int y = 0; yheight; y++)
		for (int x = 0; xwidth; x++)
		{
			xc = cvGetAt(velx, y, x);
			yc = cvGetAt(vely, y, x);

			float x_shift = (float)xc.val[0];
			float y_shift = (float)yc.val[0];
			const int winsize = 5;  //计算光流的窗口大小

			if ((x % (winsize * 2) == 0) && (y % (winsize * 2) == 0))
			{

				if (x_shift != 0 || y_shift != 0)
				{

					if (x > winsize && y > winsize && x < (velx->width - winsize) && y < (velx->height - winsize))
					{
						cvSetImageROI(velx, cvRect(x - winsize, y - winsize, 2 * winsize, 2 * winsize));
						CvScalar total_x = cvSum(velx);
						float xx = (float)total_x.val[0];
						cvResetImageROI(velx);

						cvSetImageROI(vely, cvRect(x - winsize, y - winsize, 2 * winsize, 2 * winsize));
						CvScalar total_y = cvSum(vely);
						float yy = (float)total_y.val[0];
						cvResetImageROI(vely);

						cvSetImageROI(abs_img, cvRect(x - winsize, y - winsize, 2 * winsize, 2 * winsize));
						CvScalar total_speed = cvSum(abs_img);
						float ss = (float)total_speed.val[0] / (4 * winsize*winsize) / 255;
						cvResetImageROI(abs_img);

						const double ZERO = 0.000001;
						const double pi = 3.1415926;
						double alpha_angle;

						if (xx - ZERO)
							alpha_angle = pi / 2;
						else
							alpha_angle = abs(atan(yy / xx));

						if (xx < 0 && yy>0) alpha_angle = pi - alpha_angle;
						if (xx < 0 && yy < 0) alpha_angle = pi + alpha_angle;
						if (xx > 0 && yy < 0) alpha_angle = 2 * pi - alpha_angle;

						CvScalar line_color;
						float scale_factor = ss * 100;
						line_color = CV_RGB(255, 0, 0);
						CvPoint pt1, pt2;
						pt1.x = x;
						pt1.y = y;
						pt2.x = static_cast(x + scale_factor*cos(alpha_angle));
						pt2.y = static_cast(y + scale_factor*sin(alpha_angle));

						cvLine(image, pt1, pt2, line_color, 1, CV_AA, 0);
						CvPoint p;
						p.x = (int)(pt2.x + 6 * cos(alpha_angle - pi / 4 * 3));
						p.y = (int)(pt2.y + 6 * sin(alpha_angle - pi / 4 * 3));
						cvLine(image, p, pt2, line_color, 1, CV_AA, 0);
						p.x = (int)(pt2.x + 6 * cos(alpha_angle + pi / 4 * 3));
						p.y = (int)(pt2.y + 6 * sin(alpha_angle + pi / 4 * 3));
						cvLine(image, p, pt2, line_color, 1, CV_AA, 0);

						///*
						//line_color = CV_RGB(255,255,0);
						//pt1.x = x-winsize;
						//pt1.y = y-winsize;
						//pt2.x = x+winsize;
						//pt2.y = y+winsize;
						//cvRectangle(image, pt1,pt2,line_color,1,CV_AA,0);
						//

					}
				}
			}
		}

	cvShowImage("Contour", abs_img);
	cvShowImage("Contour2", vely);

	cvReleaseImage(&velx);
	cvReleaseImage(&vely);
	cvWaitKey(20);
	**/
	return 0;
}






//(整个位图由文件头、信息头、调色板、颜色表这四部分组合构成
typedef long LONG;
typedef unsigned long DWORD;
typedef unsigned short WORD;
#pragma pack (push ,1)//由于4字节对齐，而信息头大小为54字节，第一部分14字节，
//第二部分40字节，所以会将第一部分补齐为16自己，直接用sizeof，打开图片时就会
//遇到premature end-of-file encountered错误
typedef struct {//位图文件头,14字节
	WORD      bfType;   //  指定文件类型，必须是0x424D，即字符串“BM”，也就是说所有.bmp文件的头两个字节都是“BM”。
	DWORD   bfSize;   //   位图文件的大小，包括这14个字节，以字节为单位  
	WORD      bfReserved1;   //   位图文件保留字，必须为0
	WORD      bfReserved2;   //   位图文件保留字，必须为0
	DWORD   bfOffBits;   //   位图数据的起始位置，以相对于位图， 文件头的偏移量表示，以字节为单位
} BMPFILEHEADER_T;
#pragma pack (pop)
typedef struct {//这个结构的长度是固定的，为40个字节,可以自己算一下，DWORD、LONG4个字节，WORD两个字节
	DWORD      biSize;//指定这个结构的长度，为40
	LONG       biWidth;//指定图象的宽度，单位是象素。
	LONG       biHeight;//指定图象的高度，单位是象素。
	WORD       biPlanes;//必须是1，不用考虑。
	WORD       biBitCount;/*指定表示颜色时要用到的位数，常用的值为1(黑白二色图), 4(16色图),
						  8(256色), 24(真彩色图)(新的.bmp格式支持32位色，这里就不做讨论了)。*/
	DWORD      biCompression;/*指定位图是否压缩，有效的值为BI_RGB，BI_RLE8，BI_RLE4，
							 BI_BITFIELDS(都是一些Windows定义好的常量)。要说明的是，
							 Windows位图可以采用RLE4，和RLE8的压缩格式，但用的不多。
							 我们今后所讨论的只有第一种不压缩的情况，即biCompression为BI_RGB的情况。*/
	DWORD      biSizeImage;/*指定实际的位图数据占用的字节数，其实也可以从以下的公式中计算出来：
						   biSizeImage=biWidth’ × biHeight
						   要注意的是：上述公式中的biWidth’必须是4的整倍数(所以不是biWidth，而是biWidth’，
						   表示大于或等于biWidth的，最接近4的整倍数。举个例子，如果biWidth=240，则biWidth’=240；
						   如果biWidth=241，biWidth’=244)。如果biCompression为BI_RGB，则该项可能为零*/
	LONG       biXPelsPerMeter;//指定目标设备的水平分辨率，单位是每米的象素个数
	LONG       biYPelsPerMeter;//指定目标设备的垂直分辨率，单位同上。
	DWORD      biClrUsed;//指定本图象实际用到的颜色数，如果该值为零，则用到的颜色数为2的biBitCount指数次幂
	DWORD      biClrImportant;//指定本图象中重要的颜色数，如果该值为零，则认为所有的颜色都是重要的。
} BMPINFOHEADER_T;



int  readWriteBMP()    //有一点bug
{
	int  width = 500;
	int  height = 369;

	//输入文件
	CFile file;                             //定义一个文件对象  
	_ASSERTE(file.Open(CString("D:\\images/3.bmp"), CFile::modeRead));//打开文件  
	DWORD  dwLen = file.GetLength();                    //获取文件长度  
	file.Seek(54, CFile::begin);     //略过位图文件头、信息头 ，为什么是54，往下看
	BYTE * buffer = new BYTE[dwLen - 54];   //为缓冲区分配空间  
	file.Read(buffer, dwLen - 54);

	//width = buffer[26];
	//height = buffer[27];

	//输出文件
	char * bmp_file = "D:\\images/3.bmp.another.bmp";//要保存的bmp文件名，后缀不要忘了
									 //int width = cx.GetWidth();图像宽高，已知
									 //int height = cx.GetHeight();
	int datalen = width*height * 3 * sizeof(char); // 每个像素点3个字节  
												   //_ASSERTE(l == size);
												   // 位图第一部分，文件信息  
	BMPFILEHEADER_T bfh;
	int dw = sizeof(DWORD);
	int ww = sizeof(WORD);
	int kk = sizeof(BMPFILEHEADER_T);//14，不对齐的话会得到16，这样创建的BMP打不开
	int nn = sizeof(BMPINFOHEADER_T);// second section size
	bfh.bfType = (WORD)0x4d42;  //bm  
	bfh.bfSize = datalen + kk + nn;
	bfh.bfReserved1 = 0; // reserved  
	bfh.bfReserved2 = 0; // reserved  
	bfh.bfOffBits = sizeof(BMPFILEHEADER_T) + sizeof(BMPINFOHEADER_T);//真正的数据的位置  

																	  // 位图第二部分，数据信息  
	BMPINFOHEADER_T bih;
	bih.biSize = sizeof(BMPINFOHEADER_T);
	bih.biWidth = width;
	bih.biHeight = height;//有时你得到的RGB数据是从位图最后一个点开始扫描，直接写入得到的图片是倒着的，这时用-height，这样图片就正了  
	bih.biPlanes = 1;//为1，不用改  
	bih.biBitCount = 24;
	bih.biCompression = 0;//不压缩  
	bih.biSizeImage = datalen;
	bih.biXPelsPerMeter = 0;//2835;//像素每米  
	bih.biYPelsPerMeter = 0;//2835;
	bih.biClrUsed = 0;//已用过的颜色，24位的为0  
	bih.biClrImportant = 0;//每个像素都重要  
	FILE * fp = fopen(bmp_file, "wb");//创建bmp文件
	if (!fp)
		return-1;

	fwrite(&bfh, 8, 1, fp);//由于linux上4字节对齐，而信息头大小为54字节，第一部分14字节，第二部分40字节，所以会将第一部分补齐为16自己，直接用sizeof，打开图片时就会遇到premature end-of-file encountered错误  
	fwrite(&bfh.bfReserved2, sizeof(bfh.bfReserved2), 1, fp);
	fwrite(&bfh.bfOffBits, sizeof(bfh.bfOffBits), 1, fp);
	fwrite(&bih, sizeof(BMPINFOHEADER_T), 1, fp);
	//写入rgb数据
	fwrite(buffer, datalen, 1, fp);
	fclose(fp);
	delete[]buffer;
	return 0;
}

//#include "BMP.h"

int main_bmp_read_write(void)
{
	IMAGE img;
	LoadBMP("D:\\images/3.bmp", &img, BIT24);
	WriteBMP("D:\\images/3.bmp.write.bmp", &img, BIT24);
	freeImage(&img);
	//system("pause");
	return 0;
}



void CtransMedia2YuvMfcDlg::OnBnClickedButton9_optical_flow_method()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);



	//LucasKanadeTracker    lkt(600,  0  );

	



	main_bmp_read_write();


	if (0)
	{

		main_bmp_read_write();

		try {
			readWriteBMP();
		}
		catch (CFileException & e)
		{
			cout << "发生异常： in   readWriteBMP();   " << endl;
		}
	}


	FreeConsole();
}


void CtransMedia2YuvMfcDlg::OnBnClickedButton10_video2__383x383x3()
{
	// TODO: 在此添加控件通知处理程序代码

	CString m_strPicPath;
	//IplImage* TheImage;
	CFileDialog dlg(true, _T("*.mp4"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		_T("video(*.mp4,*.avi,*.rmvb,*.rm)|*.mp4;*.avi;*.rmvb;*.rmvb;*.mpg;*.mov;*.dat;*.rm;*.bin;*.mkv|avi(*.avi)|*.avi;rmvb(*.rmvb)|*.rmvb|rm(*.rm)|*.rm|All files(*.*)|*.*"), NULL);//弹出选择图片对话框
	dlg.m_ofn.lpstrTitle = _T("open video");
	if (dlg.DoModal() != IDOK)
		return;
	m_strPicPath = dlg.GetPathName();
	//append_string_on_edit_controler(IDC_EDIT9, CString("文件名称显示(检查)：m_strPicPath = ") + m_strPicPath);
	//append_string_on_edit_controler(IDC_EDIT9, CString("打开视频：") + m_strPicPath);

	if (m_strPicPath.IsEmpty())
	{
		return;
	}

	//从这里开始进行转化，这是一个宏定义
	USES_CONVERSION;
	//进行转换
	char* keyChar = T2A(m_strPicPath.GetBuffer(0));
	m_strPicPath.ReleaseBuffer();
	//转化结束，进行对数据的操作
	//CString value(…………);
	//对数据进行显示
	//((CListBox*)GetDlgItem(IDC_LIST1))->AddString(value);
	//append_string_on_edit_controler(IDC_EDIT9, CString("文件名称显示(检查)：CString(str ) = ") + CString(keyChar));

	string  nameFile = string(keyChar); // "d:/video/Vivo.mp4";
	string  nameFileOut = nameFile + string(".383x383x3.avi");




	//   -----------------  
	VideoCapture capture;
	Mat frame;
	frame = capture.open(nameFile);
	if (!capture.isOpened())
	{
		printf("can not open ...\n");
		return;
		//return -1;
	}

	//return 0;

	Size size = Size(capture.get(CV_CAP_PROP_FRAME_WIDTH), capture.get(CV_CAP_PROP_FRAME_HEIGHT));
	size = Size(  383,383  );
	VideoWriter writer;
	writer.open(nameFileOut, CV_FOURCC('M', 'J', 'P', 'G'), 10, size, true);


	namedWindow("output", CV_WINDOW_AUTOSIZE);
	while (capture.read(frame))
	{
		Mat  rsz;
		resize(frame , rsz,  size  );
		writer.write(rsz);
		imshow("output", frame);
		waitKey(10);
	}
	capture.release();
	writer.release();
}


void CtransMedia2YuvMfcDlg::OnBnClickedButton11_get2Frequence()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	int  fre = 1338;    // 6692---1a24;
	printf("fre =  %d\t,  %x\t,  %X\t,   %#x\t, %#X\t    \n", fre, fre, fre, fre, fre);


	float  fre_out_00;
	float fre_out_01;

	float  fre_ori_00 = 6060;  //  1100    275    60  
	float  fre_ori_01 = 1212;

	char nameFrameConfigure[800];

	for (int fre_show = 60; fre_show >= 30; fre_show -= 10)
	{
		for (int steps = 500; steps <= 2400; steps += 100)
		{
			fre_out_00 = fre_ori_00 * 1100 * 60 / steps / fre_show;
			fre_out_01 = fre_ori_01 * 1100 * 60 / steps / fre_show;

			cout << setw(8) << fre_show << setw(8) << steps;
			cout << setw(6) << steps / 4.0 << setw(12) << fre_out_00 << setw(12) << fre_out_01;
			printf("\t%x\t", (int)(steps / 4.0));
			printf("\t%x\t", (int)fre_out_00);
			printf("\t%x\t", (int)fre_out_01);
			cout << endl;

			sprintf(nameFrameConfigure, "fr___%dHz_%dL_frameRateSetup.bin",
				(int)fre_show, (int)(steps / 4.0)  );
		}
	}



	FreeConsole();
}
