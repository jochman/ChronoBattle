#pragma once


// Save dialog

class Save : public CDialogEx
{
	DECLARE_DYNAMIC(Save)
	hero *user;
public:
	Save(hero* user,CWnd* pParent = NULL);   // standard constructor
	virtual ~Save();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
public:
	CString save_name;
	
	CString get_save_name();
	
	afx_msg void OnBnClickedSave();
	afx_msg void OnEnChangeEnterSaveName();
};
