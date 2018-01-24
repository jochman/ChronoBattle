#pragma once
#include "Header.h"

// Conclusions dialog

class Conclusions : public CDialogEx
{
	DECLARE_DYNAMIC(Conclusions)
	enemy* opponent;
	hero* user;
public:
	Conclusions(bool ifwon,enemy* opponent ,CWnd* pParent = NULL);   // standard constructor
	virtual ~Conclusions();

	virtual void OnFinalRelease();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONCLUSIONS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	CString IDC_CON;
	CString Reward;
	bool ifwon;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	void show_text(bool check);
	
	
};
