
// ChronoBattleDlg.h : header file

#pragma once
#include "Header.h"
#include "CustomEnemyDLG.h"

// CChronoBattleDlg dialog
class CChronoBattleDlg : public CDialogEx
{
// Construction
public:
	CChronoBattleDlg(hero* user, std::list<enemy>*,CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHRONOBATTLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon{};

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFind();
	afx_msg void OnBnClickedHeroStats();
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedHeroStats2();
	afx_msg void OnBnClickedCustomEnemy();

	void custom_fight(enemy* opponent);
	//user var
	hero *user;
	std::list<enemy>* enemylst;


};
