#pragma once
#include "Header.h"
#include "Fight.h"


// sp_attacks dialog
class sp_attacks : public CDialogEx
{
	DECLARE_DYNAMIC(sp_attacks)
	std::vector<hero> hero_turns;
	std::vector<enemy> enemy_turns;
public:
	sp_attacks(hero* user, enemy& opponent , Fight* pParent = NULL);   // standard constructor
	virtual ~sp_attacks();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SP_ATTACKS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCyclonestrike();

private:
	Fight *parent;
	hero *user;
	enemy* opponent;
public:
	afx_msg void OnBnClickedTimeheal();
	afx_msg void OnBnClickedTimewarp();
};
