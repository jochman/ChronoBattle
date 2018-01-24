#pragma once
#include "Header.h"
#include "afxwin.h"
#include "ChronoBattleDlg.h"
#include "Fight.h"
#include <string>
#include <stack>

// CustomEnemyDLG dialog

class CustomEnemyDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CustomEnemyDLG)
	std::list<enemy>* enemylst{};

	std::stack<enemy*> past;
	std::stack<enemy*> future;

	enemy* user;
	hero* gibor;

	bool undoflag;
	bool saveflag;
	//bool deleted;
public:
	CustomEnemyDLG(std::list<enemy>* enemylst, hero* gibor, CWnd* pParent = NULL);   // standard constructor
	virtual ~CustomEnemyDLG();

	void updater();
	void shower();
	void shower(std::list<enemy>::iterator it);
	void shower(CString num);
	void OnOK(); //onok overrider
	enemy* save_this();

	std::list<enemy>::iterator find_user(CString name);

	CString edit_enemy_name;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CUSTOMENEMYDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_hIcon{};
	DECLARE_MESSAGE_MAP()
	

private:
	//enemy stats for construction;
	CString name;

public:
	afx_msg void OnBnClickedSaveEnemy();
	afx_msg void OnEnChangeEditHeroName();

	int ENEMY_HP;
	afx_msg void OnEnChangeHpEnemy();
	int SP_ENEMY;
	afx_msg void OnEnChangeSpEnemy();
	int ATK_ENEMY;
	afx_msg void OnEnChangeDefEnemy();
	int DEF_ENEMY;
	afx_msg void OnEnChangeAtkEnemy();
	virtual BOOL OnInitDialog();
	CString ENEMY_NAME;
	

	afx_msg void OnBnClickedBack();
	afx_msg void MouseDoubleClick();
	afx_msg void OnBnClickedFightCustom();
	afx_msg void OnBnClickedDeleteEnemy();
	afx_msg void OnBnClickedUndo();
	afx_msg void OnBnClickedRedo();
	

	CListBox enemy_list_box;
};
