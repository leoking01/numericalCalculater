
// numericalCalculaterDlg.cpp : 实现文件
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


// CnumericalCalculaterDlg 对话框



CnumericalCalculaterDlg::CnumericalCalculaterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_numericalCalculater_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CnumericalCalculaterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CnumericalCalculaterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CnumericalCalculaterDlg::OnBnClickedButton1_trans2YUV)
	ON_BN_CLICKED(IDC_BUTTON2, &CnumericalCalculaterDlg::OnBnClickedButton2_test_binary_io_align_problm)
	ON_BN_CLICKED(IDC_BUTTON3, &CnumericalCalculaterDlg::OnBnClickedButton3_study_fundamentalMatrix)
	ON_BN_CLICKED(IDC_BUTTON4, &CnumericalCalculaterDlg::OnBnClickedButton4_optimization)
	ON_BN_CLICKED(IDC_BUTTON5, &CnumericalCalculaterDlg::OnBnClickedButton5_numerical_analysis)
	ON_BN_CLICKED(IDC_BUTTON6, &CnumericalCalculaterDlg::OnBnClickedButton6_numerical_opt_gaus_nuton)
	ON_BN_CLICKED(IDC_BUTTON7, &CnumericalCalculaterDlg::OnBnClickedButton7_mixmizeBinaryProduct)
	ON_BN_CLICKED(IDC_BUTTON8, &CnumericalCalculaterDlg::OnBnClickedButton8_function_fit_02)
	ON_BN_CLICKED(IDC_BUTTON9, &CnumericalCalculaterDlg::OnBnClickedButton9_optical_flow_method)
	ON_BN_CLICKED(IDC_BUTTON10, &CnumericalCalculaterDlg::OnBnClickedButton10_video2__383x383x3)
	ON_BN_CLICKED(IDC_BUTTON11, &CnumericalCalculaterDlg::OnBnClickedButton11_get2Frequence)
	ON_BN_CLICKED(IDC_BUTTON12, &CnumericalCalculaterDlg::OnBnClickedButton12_opencv_player_toobar)
	ON_BN_CLICKED(IDC_BUTTON13, &CnumericalCalculaterDlg::OnBnClickedButton13_oneChannels2Three)
	ON_BN_CLICKED(IDC_BUTTON14, &CnumericalCalculaterDlg::OnBnClickedButton14_dlibBayes)
	ON_BN_CLICKED(IDC_BUTTON15, &CnumericalCalculaterDlg::OnBnClickedButton15_dlibSvm)
END_MESSAGE_MAP()


// CnumericalCalculaterDlg 消息处理程序

BOOL CnumericalCalculaterDlg::OnInitDialog()
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

void CnumericalCalculaterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CnumericalCalculaterDlg::OnPaint()
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
HCURSOR CnumericalCalculaterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CnumericalCalculaterDlg::OnBnClickedButton1_trans2YUV()
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





void CnumericalCalculaterDlg::OnBnClickedButton2_test_binary_io_align_problm()
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


void CnumericalCalculaterDlg::OnBnClickedButton3_study_fundamentalMatrix()
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



void CnumericalCalculaterDlg::OnBnClickedButton4_optimization()
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






void CnumericalCalculaterDlg::OnBnClickedButton5_numerical_analysis()
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











void CnumericalCalculaterDlg::OnBnClickedButton6_numerical_opt_gaus_nuton()
{
	// TODO: 在此添加控件通知处理程序代码

	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	cout << "___________________________________________________" << endl;
	cout << "OnBnClickedButton6_numerical_opt_gaus_nuton:" << endl;
	main_gauss_nuton();
	FreeConsole();
}


void CnumericalCalculaterDlg::OnBnClickedButton7_mixmizeBinaryProduct()
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
		double x = -10.0 + 20.0*  std::rand() / (1.0 + RAND_MAX); // random between [-10 and 10]  
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

void CnumericalCalculaterDlg::OnBnClickedButton8_function_fit_02()
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



void CnumericalCalculaterDlg::OnBnClickedButton9_optical_flow_method()
{
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


void CnumericalCalculaterDlg::OnBnClickedButton10_video2__383x383x3()
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
	size = Size(383, 383);
	VideoWriter writer;
	writer.open(nameFileOut, CV_FOURCC('M', 'J', 'P', 'G'), 10, size, true);


	namedWindow("output", CV_WINDOW_AUTOSIZE);
	while (capture.read(frame))
	{
		Mat  rsz;
		resize(frame, rsz, size);
		writer.write(rsz);
		imshow("output", frame);
		waitKey(10);
	}
	capture.release();
	writer.release();
}



//对应int32大小的成员 的转换 范例
int32_t swapInt32(int32_t value)
{
	return ((value & 0x000000FF) << 24) |
		((value & 0x0000FF00) << 8) |
		((value & 0x00FF0000) >> 8) |
		((value & 0xFF000000) >> 24);
}


//    计算fpga的两个显示频率    
void CnumericalCalculaterDlg::OnBnClickedButton11_get2Frequence()
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
		if (fre_show != 30 && fre_show != 60)
		{
			continue;
		}
		if (fre_show != 60)
		{
			//  continue;
		}
		for (int steps = 500; steps <= 4800; steps += 20)
		{
			if (steps != 2660 && steps != 1320 && steps != 2800 && steps != 1100 && steps != 2720)
			{
				//continue;
			}
			fre_out_00 = fre_ori_00 * 1100 * 60 / steps / fre_show;
			fre_out_01 = fre_ori_01 * 1100 * 60 / steps / fre_show;

			cout << setw(8) << fre_show << setw(8) << steps;
			cout << setw(6) << steps / 4.0 << setw(12) << fre_out_00 << setw(12) << fre_out_01;
			printf("\t%x\t", (int)(steps / 4.0));
			printf("\t%x\t", (int)fre_out_00);
			printf("\t%x\t", (int)fre_out_01);
			cout << endl;

			sprintf(nameFrameConfigure, "frameSetBin/fr___%dHz__rnd%d__%dL__steps_%d_frameRateSetup.bin",
				(int)fre_show, (int)fre_show * 900 / 60, (int)(steps / 4.0), (int)(steps));
			fstream  fout(nameFrameConfigure, ios::out | ios::binary);

			unsigned char x01 = 90;
			fout.write((char*)&x01, sizeof(x01));
			fout.write((char*)&x01, sizeof(x01));

			unsigned char x02 = 91;
			fout.write((char*)&x02, sizeof(x02));
			fout.write((char*)&x02, sizeof(x02));

			unsigned char x03 = 4;
			fout.write((char*)&x03, sizeof(x03));


			short  x04 = (steps / 4.0);
			fout.write((char*)&x04, sizeof(x04));

			short  x05 = (short)(0.5 + fre_out_00);
			fout.write((char*)&x05, sizeof(x05));

			short  x06 = (short)(0.5 + fre_out_01);
			fout.write((char*)&x06, sizeof(x06));


			unsigned char  x07 = 0;
			fout.write((char*)&x07, sizeof(x07));
			fout.write((char*)&x07, sizeof(x07));
			fout.write((char*)&x07, sizeof(x07));
			fout.write((char*)&x07, sizeof(x07));
			fout.write((char*)&x07, sizeof(x07));


			fout.close();
		}
	}



	FreeConsole();
}

//  ----------------------------------------   opencv播放器-带进度条  ------------------------------------------------ //  

Mat image;   //读入视频帧的Mat
char* windowName = "Video Control-如果要结束就输入任意键并单击关闭图标"; //播放窗口名称
char* trackBarName = "播放进度";    //trackbar控制条名称

double totalFrame = 1.0;     //视频总帧数
double currentFrame = 1.0;    //当前播放帧
int trackbarValue = 1;    //trackbar控制量
int trackbarMax = 255;   //trackbar控制条最大值
double frameRate = 1.0;  //视频帧率
VideoCapture video;    //声明视频对象
double controlRate = 0.1;


//int createTrackbar(const string& trackbarname, const string& winname,
//	int* value, int count,
//	TrackbarCallback onChange = 0,
//	void* userdata = 0);

//void TrackBarFunc(int, void(*));
void TrackBarFunc(int, void(*))
{
	controlRate = (double)trackbarValue / trackbarMax*totalFrame; //trackbar控制条对视频播放进度的控制
	video.set(CV_CAP_PROP_POS_FRAMES, controlRate);	 //设置当前播放帧
}
void CnumericalCalculaterDlg::OnBnClickedButton12_opencv_player_toobar()
{
	// TODO: 在此添加控件通知处理程序代码
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


	string nameVideo = nameFile;//  "D:\\video/2016.out.mp4";
	//打开视频文件
	video.open(nameVideo);
	if (!video.isOpened())
	{
		std::cout << "Failed to open video" << std::endl;
	}
	totalFrame = video.get(CV_CAP_PROP_FRAME_COUNT);  //获取总帧数
	frameRate = video.get(CV_CAP_PROP_FPS);   //获取帧率
	double pauseTime = 1000 / frameRate; // 由帧率计算两幅图像间隔时间
	namedWindow(windowName);
	//在图像窗口上创建控制条
	createTrackbar(trackBarName, windowName, &trackbarValue, trackbarMax, TrackBarFunc);
	TrackBarFunc(0, 0);
	while (true)
	{
		video.read(image);
		resize(image, image, Size(500, 400)); //调整图像大小，视频在我的显示器上显示不全
		imshow(windowName, image);  //显示图像
		char key = waitKey(pauseTime);   //图像间隔
		if (key > 0)
			break;
		controlRate++;
		if (controlRate > totalFrame)  //播放完成退出
		{
			break;
		}

	}
	video.release();  //释放视频，C++中不写也无碍，可以自动释放
	waitKey();




}


void CnumericalCalculaterDlg::OnBnClickedButton13_oneChannels2Three()
{
	// TODO: 在此添加控件通知处理程序代码
	string  nameOfImage = "D:\\tof_img/";
	string  nameOfImageOut = "D:\\tof_img3/";
	for (int i = 1; i < 125; i++)
	{
		Mat  src = imread( nameOfImage+to_string(i)+string(".png"),   1 );
		imwrite( (nameOfImageOut + to_string(i) + string(".png")).c_str() ,     src  );
		//Mat  out3 = imread(, 1);

	}

}



using namespace dlib;
using namespace std;

// The contents of this file are in the public domain. See LICENSE_FOR_EXAMPLE_PROGRAMS.txt
/*
This is an example illustrating the use of the Bayesian Network
inference utilities found in the dlib C++ library.


In this example all the nodes in the Bayesian network are
boolean variables.  That is, they take on either the value
0 or the value 1.

The network contains 4 nodes and looks as follows:

B     C
\\   //
\/ \/
A
||
\/
D


The probabilities of each node are summarized below.  (The probability
of each node being 0 is not listed since it is just P(X=0) = 1-p(X=1) )

p(B=1) = 0.01

p(C=1) = 0.001

p(A=1 | B=0, C=0) = 0.01
p(A=1 | B=0, C=1) = 0.5
p(A=1 | B=1, C=0) = 0.9
p(A=1 | B=1, C=1) = 0.99

p(D=1 | A=0) = 0.2
p(D=1 | A=1) = 0.5

*/




// ----------------------------------------------------------------------------------------

int main_example_dlib_bayes()
{
	try
	{
		// There are many useful convenience functions in this namespace.  They all
		// perform simple access or modify operations on the nodes of a bayesian network. 
		// You don't have to use them but they are convenient and they also will check for
		// various errors in your bayesian network when your application is built with
		// the DEBUG or ENABLE_ASSERTS preprocessor definitions defined.  So their use
		// is recommended.  In fact, most of the global functions used in this example 
		// program are from this namespace.
		using namespace bayes_node_utils;

		// This statement declares a bayesian network called bn.  Note that a bayesian network
		// in the dlib world is just a directed_graph object that contains a special kind 
		// of node called a bayes_node.
		directed_graph<bayes_node>::kernel_1a_c bn;

		// Use an enum to make some more readable names for our nodes.
		enum nodes
		{
			A = 0,
			B = 1,
			C = 2,
			D = 3
		};

		// The next few blocks of code setup our bayesian network.

		// The first thing we do is tell the bn object how many nodes it has
		// and also add the three edges.  Again, we are using the network
		// shown in ASCII art at the top of this file.
		bn.set_number_of_nodes(4);
		bn.add_edge(A, D);
		bn.add_edge(B, A);
		bn.add_edge(C, A);


		// Now we inform all the nodes in the network that they are binary
		// nodes.  That is, they only have two possible values.  
		set_node_num_values(bn, A, 2);
		set_node_num_values(bn, B, 2);
		set_node_num_values(bn, C, 2);
		set_node_num_values(bn, D, 2);

		assignment parent_state;
		// Now we will enter all the conditional probability information for each node.
		// Each node's conditional probability is dependent on the state of its parents.  
		// To specify this state we need to use the assignment object.  This assignment 
		// object allows us to specify the state of each nodes parents. 


		// Here we specify that p(B=1) = 0.01
		// parent_state is empty in this case since B is a root node. 
		set_node_probability(bn, B, 1, parent_state, 0.01);
		// Here we specify that p(B=0) = 1-0.01
		set_node_probability(bn, B, 0, parent_state, 1 - 0.01);


		// Here we specify that p(C=1) = 0.001
		// parent_state is empty in this case since B is a root node. 
		set_node_probability(bn, C, 1, parent_state, 0.001);
		// Here we specify that p(C=0) = 1-0.001
		set_node_probability(bn, C, 0, parent_state, 1 - 0.001);


		// This is our first node that has parents. So we set the parent_state
		// object to reflect that A has both B and C as parents.
		parent_state.add(B, 1);
		parent_state.add(C, 1);
		// Here we specify that p(A=1 | B=1, C=1) = 0.99 
		set_node_probability(bn, A, 1, parent_state, 0.99);
		// Here we specify that p(A=0 | B=1, C=1) = 1-0.99 
		set_node_probability(bn, A, 0, parent_state, 1 - 0.99);

		// Here we use the [] notation because B and C have already
		// been added into parent state.  
		parent_state[B] = 1;
		parent_state[C] = 0;
		// Here we specify that p(A=1 | B=1, C=0) = 0.9 
		set_node_probability(bn, A, 1, parent_state, 0.9);
		set_node_probability(bn, A, 0, parent_state, 1 - 0.9);

		parent_state[B] = 0;
		parent_state[C] = 1;
		// Here we specify that p(A=1 | B=0, C=1) = 0.5 
		set_node_probability(bn, A, 1, parent_state, 0.5);
		set_node_probability(bn, A, 0, parent_state, 1 - 0.5);

		parent_state[B] = 0;
		parent_state[C] = 0;
		// Here we specify that p(A=1 | B=0, C=0) = 0.01 
		set_node_probability(bn, A, 1, parent_state, 0.01);
		set_node_probability(bn, A, 0, parent_state, 1 - 0.01);


		// Here we set probabilities for node D.
		// First we clear out parent state so that it doesn't have any of
		// the assignments for the B and C nodes used above.
		parent_state.clear();
		parent_state.add(A, 1);
		// Here we specify that p(D=1 | A=1) = 0.5 
		set_node_probability(bn, D, 1, parent_state, 0.5);
		set_node_probability(bn, D, 0, parent_state, 1 - 0.5);

		parent_state[A] = 0;
		// Here we specify that p(D=1 | A=0) = 0.2 
		set_node_probability(bn, D, 1, parent_state, 0.2);
		set_node_probability(bn, D, 0, parent_state, 1 - 0.2);



		// We have now finished setting up our bayesian network.  So let's compute some 
		// probability values.  The first thing we will do is compute the prior probability
		// of each node in the network.  To do this we will use the join tree algorithm which
		// is an algorithm for performing exact inference in a bayesian network.   

		// First we need to create an undirected graph which contains set objects at each node and
		// edge.  This long declaration does the trick.
		typedef dlib::set<unsigned long>::compare_1b_c set_type;
		typedef graph<set_type, set_type>::kernel_1a_c join_tree_type;
		join_tree_type join_tree;

		// Now we need to populate the join_tree with data from our bayesian network.  The next  
		// function calls do this.  Explaining exactly what they do is outside the scope of this
		// example.  Just think of them as filling join_tree with information that is useful 
		// later on for dealing with our bayesian network.  
		create_moral_graph(bn, join_tree);
		create_join_tree(join_tree, join_tree);

		// Now that we have a proper join_tree we can use it to obtain a solution to our
		// bayesian network.  Doing this is as simple as declaring an instance of
		// the bayesian_network_join_tree object as follows:
		bayesian_network_join_tree solution(bn, join_tree);


		// now print out the probabilities for each node
		cout << "Using the join tree algorithm:\n";
		cout << "p(A=1) = " << solution.probability(A)(1) << endl;
		cout << "p(A=0) = " << solution.probability(A)(0) << endl;
		cout << "p(B=1) = " << solution.probability(B)(1) << endl;
		cout << "p(B=0) = " << solution.probability(B)(0) << endl;
		cout << "p(C=1) = " << solution.probability(C)(1) << endl;
		cout << "p(C=0) = " << solution.probability(C)(0) << endl;
		cout << "p(D=1) = " << solution.probability(D)(1) << endl;
		cout << "p(D=0) = " << solution.probability(D)(0) << endl;
		cout << "\n\n\n";


		// Now to make things more interesting let's say that we have discovered that the C 
		// node really has a value of 1.  That is to say, we now have evidence that 
		// C is 1.  We can represent this in the network using the following two function
		// calls.
		set_node_value(bn, C, 1);
		set_node_as_evidence(bn, C);

		// Now we want to compute the probabilities of all the nodes in the network again
		// given that we now know that C is 1.  We can do this as follows:
		bayesian_network_join_tree solution_with_evidence(bn, join_tree);

		// now print out the probabilities for each node
		cout << "Using the join tree algorithm:\n";
		cout << "p(A=1 | C=1) = " << solution_with_evidence.probability(A)(1) << endl;
		cout << "p(A=0 | C=1) = " << solution_with_evidence.probability(A)(0) << endl;
		cout << "p(B=1 | C=1) = " << solution_with_evidence.probability(B)(1) << endl;
		cout << "p(B=0 | C=1) = " << solution_with_evidence.probability(B)(0) << endl;
		cout << "p(C=1 | C=1) = " << solution_with_evidence.probability(C)(1) << endl;
		cout << "p(C=0 | C=1) = " << solution_with_evidence.probability(C)(0) << endl;
		cout << "p(D=1 | C=1) = " << solution_with_evidence.probability(D)(1) << endl;
		cout << "p(D=0 | C=1) = " << solution_with_evidence.probability(D)(0) << endl;
		cout << "\n\n\n";

		// Note that when we made our solution_with_evidence object we reused our join_tree object.
		// This saves us the time it takes to calculate the join_tree object from scratch.  But
		// it is important to note that we can only reuse the join_tree object if we haven't changed
		// the structure of our bayesian network.  That is, if we have added or removed nodes or 
		// edges from our bayesian network then we must recompute our join_tree.  But in this example
		// all we did was change the value of a bayes_node object (we made node C be evidence)
		// so we are ok.





		// Next this example will show you how to use the bayesian_network_gibbs_sampler object
		// to perform approximate inference in a bayesian network.  This is an algorithm 
		// that doesn't give you an exact solution but it may be necessary to use in some 
		// instances.  For example, the join tree algorithm used above, while fast in many
		// instances, has exponential runtime in some cases.  Moreover, inference in bayesian
		// networks is NP-Hard for general networks so sometimes the best you can do is
		// find an approximation.
		// However, it should be noted that the gibbs sampler does not compute the correct
		// probabilities if the network contains a deterministic node.  That is, if any
		// of the conditional probability tables in the bayesian network have a probability
		// of 1.0 for something the gibbs sampler should not be used.


		// This Gibbs sampler algorithm works by randomly sampling possibles values of the
		// network.  So to use it we should set the network to some initial state.  

		set_node_value(bn, A, 0);
		set_node_value(bn, B, 0);
		set_node_value(bn, D, 0);

		// We will leave the C node with a value of 1 and keep it as an evidence node.  


		// First create an instance of the gibbs sampler object
		bayesian_network_gibbs_sampler sampler;


		// To use this algorithm all we do is go into a loop for a certain number of times
		// and each time through we sample the bayesian network.  Then we count how 
		// many times a node has a certain state.  Then the probability of that node
		// having that state is just its count/total times through the loop. 

		// The following code illustrates the general procedure.
		unsigned long A_count = 0;
		unsigned long B_count = 0;
		unsigned long C_count = 0;
		unsigned long D_count = 0;

		// The more times you let the loop run the more accurate the result will be.  Here we loop
		// 2000 times.
		const long rounds = 2000;
		for (long i = 0; i < rounds; ++i)
		{
			sampler.sample_graph(bn);

			if (node_value(bn, A) == 1)
				++A_count;
			if (node_value(bn, B) == 1)
				++B_count;
			if (node_value(bn, C) == 1)
				++C_count;
			if (node_value(bn, D) == 1)
				++D_count;
		}

		cout << "Using the approximate Gibbs Sampler algorithm:\n";
		cout << "p(A=1 | C=1) = " << (double)A_count / (double)rounds << endl;
		cout << "p(B=1 | C=1) = " << (double)B_count / (double)rounds << endl;
		cout << "p(C=1 | C=1) = " << (double)C_count / (double)rounds << endl;
		cout << "p(D=1 | C=1) = " << (double)D_count / (double)rounds << endl;
	}
	catch (std::exception& e)
	{
		cout << "exception thrown: " << endl;
		cout << e.what() << endl;
		cout << "hit enter to terminate" << endl;
		cin.get();
	}

	return  0;
}






void CnumericalCalculaterDlg::OnBnClickedButton14_dlibBayes()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	main_example_dlib_bayes();
	FreeConsole();
}




// The contents of this file are in the public domain. See LICENSE_FOR_EXAMPLE_PROGRAMS.txt
/*
This is an example illustrating the use of the support vector machine
utilities from the dlib C++ Library.
This example creates a simple set of data to train on and then shows
you how to use the cross validation and svm training functions
to find a good decision function that can classify examples in our
data set.
The data used in this example will be 2 dimensional data and will
come from a distribution where points with a distance less than 10
from the origin are labeled +1 and all other points are labeled
as -1.
*/


#include <iostream>
#include <dlib/svm.h>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace dlib;
using namespace cv;

int main_dlibSvm()
{

	// The svm functions use column vectors to contain a lot of the data on which they
	// operate. So the first thing we do here is declare a convenient typedef.  

	// This typedef declares a matrix with 2 rows and 1 column.  It will be the object that
	// contains each of our 2 dimensional samples.   (Note that if you wanted more than 2
	// features in this vector you can simply change the 2 to something else.  Or if you
	// don't know how many features you want until runtime then you can put a 0 here and
	// use the matrix.set_size() member function)
	typedef matrix<double, 2, 1> sample_type;

	// This is a typedef for the type of kernel we are going to use in this example.  In
	// this case I have selected the radial basis kernel that can operate on our 2D
	// sample_type objects
	typedef radial_basis_kernel<sample_type> kernel_type;


	// Now we make objects to contain our samples and their respective labels.
	std::vector<sample_type> samples;
	std::vector<double> labels;

	int 宽 = 500, 高 = 500;
	cv::Mat 演示图片 = cv::Mat::zeros(高, 宽, CV_8UC3);

	for (int r = -20; r <= 20; ++r)
	{
		for (int c = -20; c <= 20; ++c)
		{
			// if this point is less than 10 from the origin
			if (sqrt((double)r*r + c*c) <= 10)
			{
				cv::line(演示图片, Point(c * 10 + 250 - 2, r * 10 + 250 - 2), Point(c * 10 + 250 + 2, r * 10 + 250 + 2), Scalar(0, 0, 255));
				cv::line(演示图片, Point(c * 10 + 250 - 2, r * 10 + 250 + 2), Point(c * 10 + 250 + 2, r * 10 + 250 - 2), Scalar(0, 0, 255));
			}
			else
				cv::circle(演示图片, Point(c * 10 + 250, r * 10 + 250), 1, Scalar(100));

		}
	}

	imshow("训练样本", 演示图片);
	waitKey(1);

	// Now let's put some data into our samples and labels objects.  We do this by looping
	// over a bunch of points and labeling them according to their distance from the
	// origin.
	for (int r = -20; r <= 20; ++r)
	{
		for (int c = -20; c <= 20; ++c)
		{
			sample_type samp;
			samp(0) = r;
			samp(1) = c;
			samples.push_back(samp);

			// if this point is less than 10 from the origin
			if (sqrt((double)r*r + c*c) <= 10)
				labels.push_back(+1);
			else
				labels.push_back(-1);

		}
	}


	// Here we normalize all the samples by subtracting their mean and dividing by their
	// standard deviation.  This is generally a good idea since it often heads off
	// numerical stability problems and also prevents one large feature from smothering
	// others.  Doing this doesn't matter much in this example so I'm just doing this here
	// so you can see an easy way to accomplish this with the library.  
	vector_normalizer<sample_type> normalizer;
	// let the normalizer learn the mean and standard deviation of the samples
	normalizer.train(samples);
	// now normalize each sample
	for (unsigned long i = 0; i < samples.size(); ++i)
		samples[i] = normalizer(samples[i]);


	// Now that we have some data we want to train on it.  However, there are two
	// parameters to the training.  These are the nu and gamma parameters.  Our choice for
	// these parameters will influence how good the resulting decision function is.  To
	// test how good a particular choice of these parameters is we can use the
	// cross_validate_trainer() function to perform n-fold cross validation on our training
	// data.  However, there is a problem with the way we have sampled our distribution
	// above.  The problem is that there is a definite ordering to the samples.  That is,
	// the first half of the samples look like they are from a different distribution than
	// the second half.  This would screw up the cross validation process but we can fix it
	// by randomizing the order of the samples with the following function call.
	randomize_samples(samples, labels);


	// The nu parameter has a maximum value that is dependent on the ratio of the +1 to -1
	// labels in the training data.  This function finds that value.
	const double max_nu = maximum_nu(labels);

	// here we make an instance of the svm_nu_trainer object that uses our kernel type.
	svm_nu_trainer<kernel_type> trainer;

	// Now we loop over some different nu and gamma values to see how good they are.  Note
	// that this is a very simple way to try out a few possible parameter choices.  You
	// should look at the model_selection_ex.cpp program for examples of more sophisticated
	// strategies for determining good parameter choices.
	cout << "开始测试各参数效果" << endl;
	double Gamma = 0.00001, Nu = 0.00001;
	double OK = 0;
	for (double gamma = 0.00001; gamma <= 1; gamma *= 2)
	{
		for (double nu = 0.00001; nu < max_nu; nu *= 5)
		{
			// tell the trainer the parameters we want to use
			trainer.set_kernel(kernel_type(gamma));
			trainer.set_nu(nu);

			cout << "gamma: " << gamma << "    nu: " << nu;
			// Print out the cross validation accuracy for 3-fold cross validation using
			// the current gamma and nu.  cross_validate_trainer() returns a row vector.
			// The first element of the vector is the fraction of +1 training examples
			// correctly classified and the second number is the fraction of -1 training
			// examples correctly classified.
			matrix<double>temp = cross_validate_trainer(trainer, samples, labels, 3);
			if (OK < (temp(0, 1) + temp(0, 0))) {
				OK = temp(0, 1) + temp(0, 0);
				Gamma = gamma;
				Nu = nu;
			}
			cout << "     交叉训练测试结果: " << cross_validate_trainer(trainer, samples, labels, 3);
		}
	}


	// From looking at the output of the above loop it turns out that a good value for nu
	// and gamma for this problem is 0.15625 for both.  So that is what we will use.

	// Now we train on the full set of data and obtain the resulting decision function.  We
	// use the value of 0.15625 for nu and gamma.  The decision function will return values
	// >= 0 for samples it predicts are in the +1 class and numbers < 0 for samples it
	// predicts to be in the -1 class.
	//trainer.set_kernel(kernel_type(0.15625));
	//trainer.set_nu(0.15625);

	trainer.set_kernel(kernel_type(Gamma));
	trainer.set_nu(Nu);

	cout << "设置参数Gamma:" << Gamma << " Nu:" << Nu << endl;

	typedef decision_function<kernel_type> dec_funct_type;
	typedef normalized_function<dec_funct_type> funct_type;

	// Here we are making an instance of the normalized_function object.  This object
	// provides a convenient way to store the vector normalization information along with
	// the decision function we are going to learn.  
	funct_type learned_function;
	learned_function.normalizer = normalizer;  // save normalization information
	learned_function.function = trainer.train(samples, labels); // perform the actual SVM training and save the results



																// print out the number of support vectors in the resulting decision function
	cout << "\nnumber of support vectors in our learned_function is "
		<< learned_function.function.basis_vectors.size() << endl;

	// Now let's try this decision_function on some samples we haven't seen before.
	sample_type sample;

	sample(0) = 3.123;
	sample(1) = 2;
	cout << "This is a +1 class example, the classifier output is " << learned_function(sample) << endl;

	sample(0) = 3.123;
	sample(1) = 9.3545;
	cout << "This is a +1 class example, the classifier output is " << learned_function(sample) << endl;

	sample(0) = 13.123;
	sample(1) = 9.3545;
	cout << "This is a -1 class example, the classifier output is " << learned_function(sample) << endl;

	sample(0) = 13.123;
	sample(1) = 0;
	cout << "This is a -1 class example, the classifier output is " << learned_function(sample) << endl;


	// We can also train a decision function that reports a well conditioned probability
	// instead of just a number > 0 for the +1 class and < 0 for the -1 class.  An example
	// of doing that follows:
	typedef probabilistic_decision_function<kernel_type> probabilistic_funct_type;
	typedef normalized_function<probabilistic_funct_type> pfunct_type;

	pfunct_type learned_pfunct;
	learned_pfunct.normalizer = normalizer;
	learned_pfunct.function = train_probabilistic_decision_function(trainer, samples, labels, 3);
	// Now we have a function that returns the probability that a given sample is of the +1 class.  

	// print out the number of support vectors in the resulting decision function.  
	// (it should be the same as in the one above)
	cout << "\nnumber of support vectors in our learned_pfunct is "
		<< learned_pfunct.function.decision_funct.basis_vectors.size() << endl;

	sample(0) = 3.123;
	sample(1) = 2;
	cout << "This +1 class example should have high probability.  Its probability is: "
		<< learned_pfunct(sample) << endl;

	sample(0) = 3.123;
	sample(1) = 9.3545;
	cout << "This +1 class example should have high probability.  Its probability is: "
		<< learned_pfunct(sample) << endl;

	sample(0) = 13.123;
	sample(1) = 9.3545;
	cout << "This -1 class example should have low probability.  Its probability is: "
		<< learned_pfunct(sample) << endl;

	sample(0) = 13.123;
	sample(1) = 0;
	cout << "This -1 class example should have low probability.  Its probability is: "
		<< learned_pfunct(sample) << endl;



	// Another thing that is worth knowing is that just about everything in dlib is
	// serializable.  So for example, you can save the learned_pfunct object to disk and
	// recall it later like so:
	serialize("saved_function.dat") << learned_pfunct;

	// Now let's open that file back up and load the function object it contains.
	deserialize("saved_function.dat") >> learned_pfunct;

	// Note that there is also an example program that comes with dlib called the
	// file_to_code_ex.cpp example.  It is a simple program that takes a file and outputs a
	// piece of C++ code that is able to fully reproduce the file's contents in the form of
	// a std::string object.  So you can use that along with the std::istringstream to save
	// learned decision functions inside your actual C++ code files if you want.  




	// Lastly, note that the decision functions we trained above involved well over 200
	// basis vectors.  Support vector machines in general tend to find decision functions
	// that involve a lot of basis vectors.  This is significant because the more basis
	// vectors in a decision function, the longer it takes to classify new examples.  So
	// dlib provides the ability to find an approximation to the normal output of a trainer
	// using fewer basis vectors.  

	// Here we determine the cross validation accuracy when we approximate the output using
	// only 10 basis vectors.  To do this we use the reduced2() function.  It takes a
	// trainer object and the number of basis vectors to use and returns a new trainer
	// object that applies the necessary post processing during the creation of decision
	// function objects.
	cout << "\ncross validation accuracy with only 10 support vectors: "
		<< cross_validate_trainer(reduced2(trainer, 10), samples, labels, 3);

	// Let's print out the original cross validation score too for comparison.
	cout << "cross validation accuracy with all the original support vectors: "
		<< cross_validate_trainer(trainer, samples, labels, 3);

	// When you run this program you should see that, for this problem, you can reduce the
	// number of basis vectors down to 10 without hurting the cross validation accuracy. 


	// To get the reduced decision function out we would just do this:
	learned_function.function = reduced2(trainer, 10).train(samples, labels);
	// And similarly for the probabilistic_decision_function: 
	learned_pfunct.function = train_probabilistic_decision_function(reduced2(trainer, 10), samples, labels, 3);
	cout << "\nnumber of support vectors in our learned_function is "
		<< learned_function.function.basis_vectors.size() << endl;

	Vec3b green(0, 255, 0), blue(255, 0, 0), red(0, 0, 255), black(0, 0, 0);
	for (int i = 0; i < 演示图片.rows; ++i)
		for (int j = 0; j < 演示图片.cols; ++j)
		{
			Mat sampleMat = (Mat_<float>(1, 2) << j, i);
			sample_type sample;

			sample(0) = (i - 250) / 10.0;
			sample(1) = (j - 250) / 10.0;
			float response = learned_function(sample);


			if (response <0)
				演示图片.at<Vec3b>(i, j) = green;
			else if (response >= 0)
				演示图片.at<Vec3b>(i, j) = blue;
			else if (response == 3)
				演示图片.at<Vec3b>(i, j) = red;
			else if (response == 4)
				演示图片.at<Vec3b>(i, j) = black;
		}

	for (int r = -20; r <= 20; ++r)
	{
		for (int c = -20; c <= 20; ++c)
		{
			// if this point is less than 10 from the origin
			if (sqrt((double)r*r + c*c) <= 10)
			{
				cv::line(演示图片, Point(c * 10 + 250 - 2, r * 10 + 250 - 2), Point(c * 10 + 250 + 2, r * 10 + 250 + 2), Scalar(0, 0, 255));
				cv::line(演示图片, Point(c * 10 + 250 - 2, r * 10 + 250 + 2), Point(c * 10 + 250 + 2, r * 10 + 250 - 2), Scalar(0, 0, 255));
			}
			else
				cv::circle(演示图片, Point(c * 10 + 250, r * 10 + 250), 1, Scalar(0));

		}
	}

	imshow("分类结果", 演示图片);
	waitKey(   -1 );
	system("pause");
	return 0;
}





void CnumericalCalculaterDlg::OnBnClickedButton15_dlibSvm()
{
	// TODO: 在此添加控件通知处理程序代码
	
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	main_dlibSvm();
	FreeConsole();
}
