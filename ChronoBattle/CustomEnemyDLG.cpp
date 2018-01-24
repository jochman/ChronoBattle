// CustomEnemyDLG.cpp : implementation file
//

#include "stdafx.h"
#include "ChronoBattle.h"
#include "CustomEnemyDLG.h"
#include "afxdialogex.h"


// CustomEnemyDLG dialog

IMPLEMENT_DYNAMIC(CustomEnemyDLG, CDialogEx)

CustomEnemyDLG::CustomEnemyDLG(std::list<enemy>* enemylst, hero* gibor, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CUSTOMENEMYDLG, pParent), enemylst(enemylst), user(nullptr), gibor(gibor), undoflag(false)//,deleted(false)
	, ENEMY_HP(0)
	, SP_ENEMY(0)
	, ATK_ENEMY(0)
	, DEF_ENEMY(0)
	, ENEMY_NAME(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CustomEnemyDLG::~CustomEnemyDLG()
{
}

//take the name of enemys in the list and put them in the combobox

void CustomEnemyDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HP_ENEMY, ENEMY_HP);
	DDX_Text(pDX, IDC_SP_ENEMY, SP_ENEMY);
	DDX_Text(pDX, IDC_ATK_ENEMY, ATK_ENEMY);
	DDX_Text(pDX, IDC_DEF_ENEMY, DEF_ENEMY);
	DDX_Text(pDX, IDC_Enemy_Name, ENEMY_NAME);
	DDX_Control(pDX, IDC_LIST1, enemy_list_box);
}

void CustomEnemyDLG::updater() {
	std::list<enemy>::iterator it;
	//std::list<enemy> lst = *enemylst;
	//lst.reverse();
	enemy_list_box.ResetContent();
	for (it = enemylst->begin(); it != enemylst->end(); it++) {
		enemy_list_box.AddString((it->name()));
	}
}

int ToInt(const CString& str) {

	return _ttoi(str);
}

BEGIN_MESSAGE_MAP(CustomEnemyDLG, CDialogEx)
	ON_BN_CLICKED(IDC_Save_Enemy, &CustomEnemyDLG::OnBnClickedSaveEnemy)
	ON_EN_CHANGE(IDC_Edit_Hero_Name, &CustomEnemyDLG::OnEnChangeEditHeroName)
	ON_EN_CHANGE(IDC_HP_ENEMY, &CustomEnemyDLG::OnEnChangeHpEnemy)
	ON_EN_CHANGE(IDC_SP_ENEMY, &CustomEnemyDLG::OnEnChangeSpEnemy)
	ON_EN_CHANGE(IDC_DEF_ENEMY, &CustomEnemyDLG::OnEnChangeDefEnemy)
	ON_EN_CHANGE(IDC_ATK_ENEMY, &CustomEnemyDLG::OnEnChangeAtkEnemy)
	ON_BN_CLICKED(IDC_Back, &CustomEnemyDLG::OnBnClickedBack)
	ON_LBN_DBLCLK(IDC_LIST1, &CustomEnemyDLG::MouseDoubleClick)
	ON_BN_CLICKED(IDC_FIGHT_CUSTOM, &CustomEnemyDLG::OnBnClickedFightCustom)
	ON_WM_RBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_Delete_Enemy, &CustomEnemyDLG::OnBnClickedDeleteEnemy)
	ON_BN_CLICKED(IDC_UNDO, &CustomEnemyDLG::OnBnClickedUndo)
	ON_BN_CLICKED(IDC_REDO, &CustomEnemyDLG::OnBnClickedRedo)
END_MESSAGE_MAP()

void CustomEnemyDLG::shower() {
	UpdateData(true);
	CString str;
	std::list<enemy>::iterator it = find_user(user->name());
	if (it == enemylst->end())
		enemylst->push_front(*user);

	
	ENEMY_NAME = user->name();
	ENEMY_HP = user->hp_max();
	SP_ENEMY = user->sp_max();
	ATK_ENEMY = user->cAtk();
	DEF_ENEMY = user->cDef();

	str.Format(L"%s", user->name());
	CWnd* textwindow = GetDlgItem(IDC_Enemy_Name);
	textwindow->SetWindowText(str);

	str.Format(L"%d", user->hp_max());
	CWnd* textwindow2 = GetDlgItem(IDC_HP_ENEMY);
	textwindow2->SetWindowText(str);

	str.Format(L"%d", user->sp_max());
	CWnd* textwindow3 = GetDlgItem(IDC_SP_ENEMY);
	textwindow3->SetWindowText(str);

	str.Format(L"%d", user->cAtk());
	CWnd* textwindow4 = GetDlgItem(IDC_ATK_ENEMY);
	textwindow4->SetWindowText(str);

	str.Format(L"%d", user->cDef());
	CWnd* textwindow5 = GetDlgItem(IDC_DEF_ENEMY);
	textwindow5->SetWindowText(str);
}

void CustomEnemyDLG::shower(std::list<enemy>::iterator it)
{
	CString str;
	ENEMY_NAME = it->name();
	ENEMY_HP = it->hp_max();
	SP_ENEMY = it->sp_max();
	ATK_ENEMY = it->cAtk();
	DEF_ENEMY = it->cDef();

	CWnd* textwindow = GetDlgItem(IDC_Enemy_Name);
	textwindow->SetWindowText(ENEMY_NAME);

	str.Format(L"%d", ENEMY_HP);
	CWnd* textwindow2 = GetDlgItem(IDC_HP_ENEMY);
	textwindow2->SetWindowText(str);

	str.Format(L"%d", it->sp_max());
	CWnd* textwindow3 = GetDlgItem(IDC_SP_ENEMY);
	textwindow3->SetWindowText(str);

	str.Format(L"%d", it->cAtk());
	CWnd* textwindow4 = GetDlgItem(IDC_ATK_ENEMY);
	textwindow4->SetWindowText(str);

	str.Format(L"%d", it->cDef());
	CWnd* textwindow5 = GetDlgItem(IDC_DEF_ENEMY);
	textwindow5->SetWindowText(str);
}

void CustomEnemyDLG::shower(CString num)
{
	CWnd* textwindow = GetDlgItem(IDC_Enemy_Name);
	textwindow->SetWindowText(num);

	CWnd* textwindow2 = GetDlgItem(IDC_HP_ENEMY);
	textwindow2->SetWindowText(num);

	CWnd* textwindow3 = GetDlgItem(IDC_SP_ENEMY);
	textwindow3->SetWindowText(num);

	CWnd* textwindow4 = GetDlgItem(IDC_ATK_ENEMY);
	textwindow4->SetWindowText(num);

	CWnd* textwindow5 = GetDlgItem(IDC_DEF_ENEMY);
	textwindow5->SetWindowText(num);

	ENEMY_NAME = " ";
	ENEMY_HP = 0;
	SP_ENEMY = 0;
	ATK_ENEMY = 0;
	DEF_ENEMY = 0;
}

std::list<enemy>::iterator CustomEnemyDLG::find_user(CString name) {
	std::list<enemy>::iterator it;
	for (it = enemylst->begin(); it != enemylst->end(); it++) { //if name exists
		if (it->name() == name)
			return it;
	}
	it = enemylst->end();
	return it;
}

enemy* CustomEnemyDLG::save_this() {
	bool ifExist = false;
	std::list<enemy>::iterator it;
	it = find_user(ENEMY_NAME);
	enemy* temp;
	//if name exists, it auto-creates
	if (it != enemylst->end())/*if the name within the list*/ {
		temp = new enemy(it->hp_max(), it->sp_max(), it->cAtk(), it->cDef(), it->name());
		it->set_atk(ATK_ENEMY);
		it->set_def(DEF_ENEMY);
		it->set_hp_max(ENEMY_HP);
		it->set_sp_max(SP_ENEMY);
		ifExist = true;
	}
	else {
		temp = new enemy(ENEMY_HP, SP_ENEMY, ATK_ENEMY, DEF_ENEMY, ENEMY_NAME);
		enemylst->push_front(*temp);
	}

	return temp;
}

void CustomEnemyDLG::OnOK()
{
}

BOOL CustomEnemyDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetOwner()->ShowWindow(FALSE);
	updater();

	SetIcon(m_hIcon, TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

// CustomEnemyDLG message handlers

void CustomEnemyDLG::OnBnClickedBack()
{
	GetOwner()->ShowWindow(TRUE);
	EndDialog(-1);
}

void CustomEnemyDLG::MouseDoubleClick()
{
	std::list<enemy>::iterator it;
	int num = enemy_list_box.GetCurSel();
	if (num != LB_ERR)
	{
		CString ItemSelected;
		enemy_list_box.GetText(num, ItemSelected);
		it = find_user(ItemSelected);
	}
	shower(it);
	user = new enemy(ENEMY_HP, SP_ENEMY, ATK_ENEMY, DEF_ENEMY, ENEMY_NAME);

}

void CustomEnemyDLG::OnBnClickedSaveEnemy()
{
	UpdateData(true);
	user = save_this();
	past.push(user);
	//if (undoflag)
	//	saveflag = true;
	updater();
}

void CustomEnemyDLG::OnBnClickedDeleteEnemy()
{
	if (enemylst->empty())return;
	CString str(" ");
	std::list<enemy>::iterator it = enemylst->begin();
	int num = enemy_list_box.GetCurSel();
	enemy_list_box.DeleteString(num); // delete list item
	if (num != LB_ERR)
	{
		CString ItemSelected;
		enemy_list_box.GetText(num, ItemSelected);
		it = find_user(ItemSelected);
	}
	shower(it);
	past.push(new enemy(ENEMY_HP, SP_ENEMY, ATK_ENEMY, DEF_ENEMY, ENEMY_NAME));
	enemylst->erase(it); //delete item
	shower(CString(L"0"));
	//deleted = true;
	updater();
}

void CustomEnemyDLG::OnBnClickedUndo()
{
	if (past.empty()) return; //if stack is empty
	UpdateData(true);

	future.push(save_this());

	user = past.top();

	shower();
	save_this();


	past.pop();

	updater();
}

void CustomEnemyDLG::OnBnClickedRedo()
{
	if (future.empty()) return;
	/*if (undoflag && saveflag) {
		future = std::stack<enemy*>();
		undoflag = false;
		saveflag = false;
		return;
	}*/
	/*if (deleted)
	{
		CString ItemSelected;
		enemy_list_box.DeleteString(enemy_list_box.GetCurSel());
		enemylst->erase(find_user(ItemSelected));
	}*/


	UpdateData(true);

	past.push(user);

	user = future.top();
	
	shower();
	future.pop();

	save_this();

	
	
	updater();
}

void CustomEnemyDLG::OnEnChangeEditHeroName()
{
	UpdateData(true);
}
void CustomEnemyDLG::OnEnChangeHpEnemy()
{
	UpdateData(true);
}
void CustomEnemyDLG::OnEnChangeSpEnemy()
{
	UpdateData(true);
}

void CustomEnemyDLG::OnEnChangeDefEnemy()
{
	UpdateData(true);
}

void CustomEnemyDLG::OnEnChangeAtkEnemy()
{
	UpdateData(true);
}

void CustomEnemyDLG::OnBnClickedFightCustom()
{
	if (user == NULL) {
		MessageBox(_T("No enemy to fight, use save button or choose one from the list"), _T("ERROR!"), MB_ICONWARNING | MB_OK);
		return;
	}
	if (user->hp_max() == 0) {
		MessageBox(_T("Enemy have zero hp! fix it."), _T("ERROR!"), MB_ICONWARNING | MB_OK);
		return;
	}
	if (user->name() == " ") {
		MessageBox(_T("Enemy have no name! fix it."), _T("ERROR!"), MB_ICONWARNING | MB_OK);
		return;
	}


	Fight f(gibor, user, this);
	f.DoModal();
}