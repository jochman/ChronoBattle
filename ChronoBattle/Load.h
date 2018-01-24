#pragma once
#include <string.h>


// Load dialog

class Load : public CDialogEx
{
	DECLARE_DYNAMIC(Load)
	hero* user;

	int hp_max;
	int sp_max;
	int atk;
	int def;
	int point_av;
	int point_max;
	int point_used_atk;
	int point_used_def;
	int point_used_hp;
	int point_used_sp;
	int potion_count;

public:
	Load(hero* user,CWnd* pParent = NULL);   // standard constructor
	virtual ~Load();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString load_name;
	CString enter_load_name;
	afx_msg void OnEnChangeEnterLoadName();
	afx_msg void OnBnClickedLoad();


};
