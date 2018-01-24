// Load.cpp : implementation file
//

#include "stdafx.h"
#include "ChronoBattle.h"
#include "Load.h"
#include "afxdialogex.h"


// Load dialog

IMPLEMENT_DYNAMIC(Load, CDialogEx)

Load::Load(hero* user,CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOAD, pParent),user(user)
	, enter_load_name(_T(""))
{

}

Load::~Load()
{
}

void Load::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Enter_Load_Name, enter_load_name);
}


BEGIN_MESSAGE_MAP(Load, CDialogEx)
	ON_EN_CHANGE(IDC_Enter_Load_Name, &Load::OnEnChangeEnterLoadName)
	ON_BN_CLICKED(IDC_Load, &Load::OnBnClickedLoad)
END_MESSAGE_MAP()


// Load message handlers


void Load::OnEnChangeEnterLoadName()
{
	CString txt;
	CWnd* textwindow = GetDlgItem(IDC_Enter_Load_Name);
	textwindow->GetWindowText(txt);
	load_name = txt;
}


void Load::OnBnClickedLoad()
{
	
	std::ifstream file;

	load_name += ".sav";
	char load[100] = " ";
	char name[100];
	
	CString Name;

	for (int i = 0; i < load_name.GetLength(); i++) {
		load[i] = load_name[i];
	}



	file.open(load);

	if (!file) { return; }

	else
	{
		
		file >> name;
		file >> hp_max;
		file >> sp_max;
		file >> atk;
		file >> def;
		file >> point_av;
		file >> point_max;
		file >> point_used_atk;
		file >> point_used_def;
		file >> point_used_hp;
		file >> point_used_sp;
		file >> potion_count;

		file.close();

		Name = CString(name);

		user->set_name(Name);
		user->set_hp_max(hp_max);
		user-> set_hp(hp_max);
		user->set_sp_max(sp_max);
		user->set_sp(sp_max);
		user->set_atk(atk);
		user->set_def(def);
		user->set_point_av(point_av);
		user->set_point_max(point_max);
		user->set_point_used_atk(point_used_atk);
		user->set_point_used_def(point_used_def);
		user->set_point_used_hp(point_used_hp);
		user->set_point_used_sp(point_used_sp);
		user->set_potion_count(potion_count);

		EndDialog(-1);
	}

}

