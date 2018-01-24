#pragma once


// Stats dialog

class Stats : public CDialogEx
{
	DECLARE_DYNAMIC(Stats)
	hero *user;
public:
	Stats(hero* user,CWnd* pParent = NULL);   // standard constructor
	virtual ~Stats();

	void DisplayBitmap() const;

	void updater();

	void OnOk();

	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STATS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_hIcon{};
public:
	virtual BOOL OnInitDialog();
	CString av_hp;
	CString av_sp;
	CString av_atk;
	CString av_def;
	CString show_potion;
	CString edit_hero_name;
	CString stat_pnt;

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedinchp();
	afx_msg void OnBnClickedincatk();
	afx_msg void OnBnClickedIncsp();
	afx_msg void OnBnClickedincdef();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickeddechp();
	afx_msg void OnBnClickeddecsp();
	afx_msg void OnBnClickeddecatk();
	afx_msg void OnBnClickeddecdef();
	afx_msg void OnEnChangeEditHeroName();
};
