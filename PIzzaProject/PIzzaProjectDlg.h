
// PIzzaProjectDlg.h : header file
//

#pragma once


// CPIzzaProjectDlg dialog
class CPIzzaProjectDlg : public CDialogEx
{
// Construction
public:
	CPIzzaProjectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PIZZAPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit1();
	int Choosen;
	int Tom_Grade;
	double Calories_show;
	int Amt_Slices;
	int Amt_Family;
	int Amt_Cheffs;
	int Amt_Personal;
	afx_msg void OnEnChangeEdit2();
	double Show_price;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit8();
	
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
	CButton Delete;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit6();

	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedButton5();
};
