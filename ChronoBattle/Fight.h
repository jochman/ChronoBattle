#pragma once
#include "afxwin.h"
#include "Header.h"
#include <vector>
// Fight dialog

class Fight : public CDialogEx
{
	DECLARE_DYNAMIC(Fight)
	//vars
	enemy *opponent;
	hero *user;
	int i;

	std::vector<hero> hero_turns;
	std::vector<enemy> enemy_turns;

public:
	void set_battlelog(CString str);
	Fight(hero* user, CWnd* pParent = NULL);   // standard constructor
	Fight(hero* user, enemy* oppo, CWnd* pParent = NULL);
	virtual ~Fight();

	void OnPaint();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIGHT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_hIcon{};

	DECLARE_MESSAGE_MAP()
public:
	void shower();
	void holder();
	void get_rewards();
	void enter_list();
	void cycle_list();

	void generate_enemy();		//enemy generator

	//fight strings
	CString IDC_BATTLELOG;
	CString IDC_HEROHP;

	virtual BOOL OnInitDialog();
	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	afx_msg void OnBnClickedAtk();


	CString IDC_BATTLELOG2;
	CString IDC_BATTLELOG3;
	afx_msg void OnBnClickedPotion();
	
	afx_msg void OnBnClickedSatk();
	afx_msg void OnBnClickedDef();
	void DisplayBitmap();

	void check_condtion();


	CString av_potions;
};
