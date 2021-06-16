
// PIzzaProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "PIzzaProject.h"
#include "PIzzaProjectDlg.h"
#include "afxdialogex.h"
#include "wingdi.h"
#include "Pizza.h"
#include <vector>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
static int timeused = 0;
IMPLEMENT_SERIAL(SaveOrder, CObject, 1)
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CPIzzaProjectDlg dialog



CPIzzaProjectDlg::CPIzzaProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PIZZAPROJECT_DIALOG, pParent) // defualt constractor  :) to my variables 
	, Choosen(0)
	, Tom_Grade(0)
	, Calories_show(0)
	, Show_price(0)
	, Amt_Slices(0)
	, Amt_Family(0)
	, Amt_Cheffs(0)
	, Amt_Personal(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPIzzaProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	Tom_Grade = 100;
	DDX_Text(pDX, IDC_EDIT1, Choosen);// בחירה שלנו
	DDX_Text(pDX, IDC_EDIT4, Tom_Grade); // ציון שלי 
	DDX_Text(pDX, IDC_EDIT3, Calories_show);// הקלוריות המוצגות
	DDX_Text(pDX, IDC_EDIT2, Show_price); // המחיר שמוצג 

	DDX_Text(pDX, IDC_EDIT5, Amt_Slices);// כמות של  משולשים
	DDX_Text(pDX, IDC_EDIT6, Amt_Family);// כמות של משפחתיות
	DDX_Text(pDX, IDC_EDIT7, Amt_Cheffs); // פצות שף
	DDX_Text(pDX, IDC_EDIT8, Amt_Personal);// אישיות 
}

BEGIN_MESSAGE_MAP(CPIzzaProjectDlg, CDialogEx) // EVENTS 
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT4, &CPIzzaProjectDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT1, &CPIzzaProjectDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CPIzzaProjectDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT8, &CPIzzaProjectDlg::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT7, &CPIzzaProjectDlg::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_BUTTON1, &CPIzzaProjectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CPIzzaProjectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, &CPIzzaProjectDlg::OnBnClickedOk)
	
	ON_EN_CHANGE(IDC_EDIT6, &CPIzzaProjectDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDCANCEL, &CPIzzaProjectDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_Clear, &CPIzzaProjectDlg::OnBnClickedClear)

	ON_BN_CLICKED(IDC_SAVE, &CPIzzaProjectDlg::OnBnClickedSave)
	ON_BN_CLICKED(Load, &CPIzzaProjectDlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_BUTTON5, &CPIzzaProjectDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CPIzzaProjectDlg message handlers

BOOL CPIzzaProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPIzzaProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPIzzaProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPIzzaProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPIzzaProjectDlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CPIzzaProjectDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CPIzzaProjectDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
int count_Family = 0, count_Personal = 0, count_Slice = 0,x;
int calories = 0, price = 0;
vector <Cheff_Pizza> order_cheff1;
vector<Cheff_Pizza> order_cheff;
//Cheff_Pizza LOL1;
vector<Family_Pizza> order_family;
//Family_Pizza LOL2;
vector<Personal_Pizza> order_personal;
//Personal_Pizza LOL3;
vector<Slice_Pizza> order_slice;
//Slice_Pizza LOL4;


void CPIzzaProjectDlg::OnBnClickedButton1()
{

	int Choosen_number = GetDlgItemInt(IDC_EDIT1, 0, 0);
	
	CPoint point1, point2 , point3;
	point1.x = 950 +x;
	point1.y = 200 +x;

	point2.x = 1070+x;
	point2.y = 320+x;
	point3.x = 1050+x;
	point3.y = 300+x;

	CClientDC dc(this); //<- uses GetDC
	dc.SelectStockObject(GRAY_BRUSH);
	
	if (Choosen_number == 3) {
		x = order_cheff.size();
		x*=-10;
		dc.Rectangle(CRect(920+x, 160+x, 1040+x, 330+x));// Pizza Cheff 3
		x = x % 1000;
		Cheff_Pizza LOL1;
		calories =calories + LOL1.GetCalories();
		price = price + LOL1.Getprice();
		order_cheff.push_back(LOL1);
		int len =order_cheff.size();
		
		SetDlgItemInt(IDC_EDIT7, len, 0);
		SetDlgItemInt(IDC_EDIT3, calories, 0);
		SetDlgItemInt(IDC_EDIT2, price, 0);
		
	}
	
	if (Choosen_number == 4) {
		Family_Pizza LOL2;
		order_family.push_back(LOL2);
		x = order_family.size();
		x *= -10;
		dc.Ellipse(CRect(point1, point2)); // Family Pizza 4
		count_Family++;
		calories = calories + LOL2.GetCalories();
		price = price + LOL2.Getprice();
		int len = order_family.size();
		SetDlgItemInt(IDC_EDIT6, len, 0);
		x = x % 1000;
		SetDlgItemInt(IDC_EDIT3, calories, 0);
		SetDlgItemInt(IDC_EDIT2, price, 0);
		
	}
	
	if (Choosen_number == 1) {
		Personal_Pizza LOL3;
		order_personal.push_back(LOL3);
		x = order_personal.size();
		x *= -10;
		dc.Ellipse(CRect(point1, point3)); // Personal Pizza 1
		count_Personal++;
		calories = calories + LOL3.GetCalories();
		price = price + LOL3.Getprice();
		int len = order_personal.size();
	SetDlgItemInt(IDC_EDIT8, len, 0);
	x = x % 1000;
	SetDlgItemInt(IDC_EDIT3, calories, 0);
	SetDlgItemInt(IDC_EDIT2, price, 0);
	}
	
	if (Choosen_number == 2) // Slice of Pizza
	{
		
		Slice_Pizza LOL4;
		order_slice.push_back(LOL4);
		x = order_slice.size();
		x *= -10;
		dc.MoveTo(830+x, 250+x);//a                   a:(x,y) b:(x+20,y+30) c:(x+70,y+30)
		dc.LineTo(850+x, 280+x);//b
		dc.MoveTo(830+x, 250+x);//a
		dc.LineTo(900+x, 280+x);//c
		dc.LineTo(850+x, 280+x);//b
		count_Slice++;
		calories = calories + LOL4.GetCalories();
		price = price + LOL4.Getprice();
		int len = order_slice.size();
		SetDlgItemInt(IDC_EDIT5, len, 0);
		x = x % 1000;
		SetDlgItemInt(IDC_EDIT3, calories, 0);
		SetDlgItemInt(IDC_EDIT2, price, 0);
	}
	
	
	
	// TODO: Add your control notification handler code here
}


void CPIzzaProjectDlg::OnEnChangeEdit8()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CPIzzaProjectDlg::OnEnChangeEdit7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CPIzzaProjectDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CPIzzaProjectDlg::OnBnClickedButton2()
{

	
	// TODO: Add your control notification handler code here
}

void CPIzzaProjectDlg::OnBnClickedButton3()
{
	int Choosen_number = GetDlgItemInt(IDC_EDIT1, 0, 0);

	CPoint point1, point2, point3;
	point1.x = 950 + x;
	point1.y = 200 + x;

	point2.x = 1070 + x;
	point2.y = 320 + x;
	point3.x = 1050 + x;
	point3.y = 300 + x;

	CClientDC dc(this); //<- uses GetDC
	dc.SelectStockObject(LTGRAY_BRUSH);
	if (Choosen_number == 3 && order_cheff.size() != 0) {

		x = order_cheff.size()-1;
		x *= -10;
		dc.Rectangle(CRect(920 + x, 160 + x, 1040 + x, 330 + x));
		
	
		if (calories > 0 && price > 0)
		{
			Cheff_Pizza LOL1;
			calories = calories - LOL1.GetCalories();
			price = price - LOL1.Getprice();
		}
		order_cheff.pop_back();
		int len = order_cheff.size();

		SetDlgItemInt(IDC_EDIT7, len, 0);
		SetDlgItemInt(IDC_EDIT3, calories, 0);
		SetDlgItemInt(IDC_EDIT2, price, 0);

	}
	if (Choosen_number == 4 && order_family.size() != 0) {
		x = order_family.size() - 1;
		x *= -10;
		dc.Ellipse(CRect(point1, point2));
		if (calories > 0 && price > 0)
		{
			Family_Pizza LOL2;
			calories = calories - LOL2.GetCalories();
			price = price - LOL2.Getprice();
		}
		order_family.pop_back();
		//dc.Ellipse(CRect(point1, point2)); // Family Pizza 4
		int len = order_family.size();
		SetDlgItemInt(IDC_EDIT6, len, 0);
		SetDlgItemInt(IDC_EDIT3, calories, 0);
		SetDlgItemInt(IDC_EDIT2, price, 0);


	}
	if (Choosen_number == 1 && order_personal.size() != 0) {
		x =order_personal.size() - 1;
		x *= -10;
		dc.Ellipse(CRect(point1, point3));
		if (calories > 0 && price > 0)
		{
			Personal_Pizza LOL3;
			calories = calories - LOL3.GetCalories();
			price = price - LOL3.Getprice();
		}
		order_personal.pop_back();
		//dc.Ellipse(CRect(point1, point3)); // Personal Pizza 1
		int len = order_personal.size();
		SetDlgItemInt(IDC_EDIT8, len, 0);
		SetDlgItemInt(IDC_EDIT3, calories, 0);
		SetDlgItemInt(IDC_EDIT2, price, 0);

	}
	if (Choosen_number == 2 && order_slice.size() != 0) // Slice of Pizza
	{
		// doesn't work :(  dc.SetDCPenColor(RGB(0, 0, 128));
		x = order_slice.size() - 1;
		x *= -10;
		order_slice.pop_back();
		
		dc.MoveTo(830 + x, 250 + x);//a                   a:(x,y) b:(x+20,y+30) c:(x+70,y+30)
		dc.LineTo(850 + x, 280 + x);//b
		dc.MoveTo(830 + x, 250 + x);//a
		dc.LineTo(900 + x, 280 + x);//c
		dc.LineTo(850 + x, 280 + x);//b
		

		if (calories > 0 && price > 0)
		{
			Slice_Pizza LOL4;
			calories = calories - LOL4.GetCalories();
			price = price - LOL4.Getprice();
		}
		int len = order_slice.size();
		SetDlgItemInt(IDC_EDIT5, len, 0);
		SetDlgItemInt(IDC_EDIT3, calories, 0);
		SetDlgItemInt(IDC_EDIT2, price, 0);
	}

	// TODO: Add your control notification handler code here
}


void CPIzzaProjectDlg::OnEnChangeEdit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}



void CPIzzaProjectDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CPIzzaProjectDlg::OnBnClickedClear()
{
	InvalidateRect(NULL);
	count_Family = 0;
	count_Personal = 0;
	count_Slice = 0;
	calories = 0;
	price = 0;
	while (order_cheff.size() != 0)
	{
		order_cheff.pop_back();
	}
	while (order_slice.size() != 0)
	{
		order_slice.pop_back();
	}
	while (order_family.size() != 0)
	{
		order_family.pop_back();
	}
	while (order_personal.size() != 0)
	{
		order_personal.pop_back();
	}
	SetDlgItemInt(IDC_EDIT1, 0, 0);
	SetDlgItemInt(IDC_EDIT2, 0, 0);
	SetDlgItemInt(IDC_EDIT3, 0, 0);
	SetDlgItemInt(IDC_EDIT5, 0, 0);
	SetDlgItemInt(IDC_EDIT6, 0, 0);
	SetDlgItemInt(IDC_EDIT7, 0, 0);
	SetDlgItemInt(IDC_EDIT8, 0, 0);
	timeused = 0;
	// TODO: Add your control notification handler code here
}


void CPIzzaProjectDlg::OnBnClickedSave()//save with Serialize
{
	//OpenFile();
	SaveOrder t;
	t.count_F = order_family.size();
	t.count_P = order_personal.size();
	t.count_c = order_cheff.size();
	t.count_S = order_slice.size();
	CFile thefile;
	thefile.Open(_T("CArchieve__test.ser"), CFile::modeCreate | CFile::modeWrite);
	CArchive archieve(&thefile, CArchive::store);
	
		t.Serialize(archieve);
	
}


void CPIzzaProjectDlg::OnBnClickedLoad()//Load read for the file 
{
	// deleting the existing information 
	
	

	//loading the saved information
	if (timeused == 0) {
		SaveOrder t;
		CFile thefile;
		thefile.Open(_T("CArchieve__test.ser"), CFile::modeRead);

		CArchive archieve(&thefile, CArchive::load);
		t.Serialize(archieve);

		// cheff= t.count_c;
	//	personal = t.count_P;
		//slice = t.count_S;
		//family = t.count_F;
		CClientDC dc(this);
		dc.SelectStockObject(LTGRAY_BRUSH);
		x = 0;

		CPoint point1, point2, point3;
		point1.x = 950 + x;
		point1.y = 200 + x;

		point2.x = 1070 + x;
		point2.y = 320 + x;
		point3.x = 1050 + x;
		point3.y = 300 + x;
		for (int i = 0; i < t.count_c; i++)
		{
			x = order_cheff.size();
			x *= -10;
			dc.Rectangle(CRect(920 + x, 160 + x, 1040 + x, 330 + x));// Pizza Cheff 3
			x = x % 1000;
			Cheff_Pizza LOL1;
			calories = calories + LOL1.GetCalories();
			price = price + LOL1.Getprice();
			order_cheff.push_back(LOL1);
			int len = order_cheff.size();

			SetDlgItemInt(IDC_EDIT7, len, 0);
			SetDlgItemInt(IDC_EDIT3, calories, 0);
			SetDlgItemInt(IDC_EDIT2, price, 0);
		}
		for (int i = 0; i < t.count_S; i++)
		{
			Slice_Pizza LOL4;
			order_slice.push_back(LOL4);
			x = order_slice.size();
			x *= -10;
			dc.MoveTo(830 + x, 250 + x);//a                   a:(x,y) b:(x+20,y+30) c:(x+70,y+30)
			dc.LineTo(850 + x, 280 + x);//b
			dc.MoveTo(830 + x, 250 + x);//a
			dc.LineTo(900 + x, 280 + x);//c
			dc.LineTo(850 + x, 280 + x);//b
			count_Slice++;
			calories = calories + LOL4.GetCalories();
			price = price + LOL4.Getprice();
			int len = order_slice.size();
			SetDlgItemInt(IDC_EDIT5, len, 0);
			x = x % 1000;
			SetDlgItemInt(IDC_EDIT3, calories, 0);
			SetDlgItemInt(IDC_EDIT2, price, 0);
		}
		for (int i = 0; i < t.count_F; i++)
		{
			Family_Pizza LOL2;
			order_family.push_back(LOL2);
			x = order_family.size();
			x *= -10;
			dc.Ellipse(CRect(point1, point2)); // Family Pizza 4
			count_Family++;
			calories = calories + LOL2.GetCalories();
			price = price + LOL2.Getprice();
			int len = order_family.size();
			SetDlgItemInt(IDC_EDIT6, len, 0);
			x = x % 1000;
			SetDlgItemInt(IDC_EDIT3, calories, 0);
			SetDlgItemInt(IDC_EDIT2, price, 0);
		}
		for (int i = 0; i < t.count_P; i++)
		{
			Personal_Pizza LOL3;
			order_personal.push_back(LOL3);
			x = order_personal.size();
			x *= -10;
			dc.Ellipse(CRect(point1, point3)); // Personal Pizza 1
			count_Personal++;
			calories = calories + LOL3.GetCalories();
			price = price + LOL3.Getprice();
			int len = order_personal.size();
			SetDlgItemInt(IDC_EDIT8, len, 0);
			x = x % 1000;
			SetDlgItemInt(IDC_EDIT3, calories, 0);
			SetDlgItemInt(IDC_EDIT2, price, 0);
		}
	}
	timeused++;
	// TODO: Add your control notification handler code here
}


void CPIzzaProjectDlg::OnBnClickedButton5()
{
	
		SaveOrder t;
		CFile thefile;
		thefile.Open(_T("CArchieve__test.ser"), CFile::modeRead);

		CArchive archieve(&thefile, CArchive::load);
		t.Serialize(archieve);

		// cheff= t.count_c;
	//	personal = t.count_P;
		//slice = t.count_S;
		//family = t.count_F;
		CClientDC dc(this);
		dc.SelectStockObject(LTGRAY_BRUSH);
		x = 0;

		CPoint point1, point2, point3;
		point1.x = 950 + x;
		point1.y = 200 + x;

		point2.x = 1070 + x;
		point2.y = 320 + x;
		point3.x = 1050 + x;
		point3.y = 300 + x;
		for (int i = 0; i < t.count_c; i++)
		{
			x = order_cheff.size();
			x *= -10;
			dc.Rectangle(CRect(920 + x, 160 + x, 1040 + x, 330 + x));// Pizza Cheff 3
			x = x % 1000;
			Cheff_Pizza LOL1;
			calories = calories + LOL1.GetCalories();
			price = price + LOL1.Getprice();
			order_cheff.push_back(LOL1);
			int len = order_cheff.size();

			SetDlgItemInt(IDC_EDIT7, len, 0);
			SetDlgItemInt(IDC_EDIT3, calories, 0);
			SetDlgItemInt(IDC_EDIT2, price, 0);
		}
		for (int i = 0; i < t.count_S; i++)
		{
			Slice_Pizza LOL4;
			order_slice.push_back(LOL4);
			x = order_slice.size();
			x *= -10;
			dc.MoveTo(830 + x, 250 + x);//a                   a:(x,y) b:(x+20,y+30) c:(x+70,y+30)
			dc.LineTo(850 + x, 280 + x);//b
			dc.MoveTo(830 + x, 250 + x);//a
			dc.LineTo(900 + x, 280 + x);//c
			dc.LineTo(850 + x, 280 + x);//b
			count_Slice++;
			calories = calories + LOL4.GetCalories();
			price = price + LOL4.Getprice();
			int len = order_slice.size();
			SetDlgItemInt(IDC_EDIT5, len, 0);
			x = x % 1000;
			SetDlgItemInt(IDC_EDIT3, calories, 0);
			SetDlgItemInt(IDC_EDIT2, price, 0);
		}
		for (int i = 0; i < t.count_F; i++)
		{
			Family_Pizza LOL2;
			order_family.push_back(LOL2);
			x = order_family.size();
			x *= -10;
			dc.Ellipse(CRect(point1, point2)); // Family Pizza 4
			count_Family++;
			calories = calories + LOL2.GetCalories();
			price = price + LOL2.Getprice();
			int len = order_family.size();
			SetDlgItemInt(IDC_EDIT6, len, 0);
			x = x % 1000;
			SetDlgItemInt(IDC_EDIT3, calories, 0);
			SetDlgItemInt(IDC_EDIT2, price, 0);
		}
		for (int i = 0; i < t.count_P; i++)
		{
			Personal_Pizza LOL3;
			order_personal.push_back(LOL3);
			x = order_personal.size();
			x *= -10;
			dc.Ellipse(CRect(point1, point3)); // Personal Pizza 1
			count_Personal++;
			calories = calories + LOL3.GetCalories();
			price = price + LOL3.Getprice();
			int len = order_personal.size();
			SetDlgItemInt(IDC_EDIT8, len, 0);
			x = x % 1000;
			SetDlgItemInt(IDC_EDIT3, calories, 0);
			SetDlgItemInt(IDC_EDIT2, price, 0);
		}
	
	// TODO: Add your control notification handler code here
}
