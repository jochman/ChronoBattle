// Save.cpp : implementation file
//

#include "stdafx.h"
#include "ChronoBattle.h"
#include "Save.h"
#include "afxdialogex.h"



// Save dialog

IMPLEMENT_DYNAMIC(Save, CDialogEx)

Save::Save(hero* user, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SAVE, pParent),user(user)
	, save_name(_T(""))
{

}

Save::~Save()
{
}

void Save::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}




BEGIN_MESSAGE_MAP(Save, CDialogEx)

	ON_BN_CLICKED(IDC_Save, &Save::OnBnClickedSave)
	ON_EN_CHANGE(IDC_Enter_Save_Name, &Save::OnEnChangeEnterSaveName)
END_MESSAGE_MAP()


// Save message handlers




CString Save::get_save_name()
{
	return save_name;
}

void Save::OnBnClickedSave()
{
	
	std::ofstream file;

	save_name += ".sav";
	char name[100] = " ";
	char save[100] = " ";

	for (int i = 0; i < user->name().GetLength(); i++) {
	name[i] = user->name()[i];
	}

	for (int i = 0; i < save_name.GetLength(); i++) {
		save[i] = save_name[i];
	}
	
	
	
	file.open(save);

	if (!file) { return; }

	else
	{
		file << name << "\n";
		file << user->hp_max() << "\n";
		file << user->sp_max() << "\n";
		file << user->atk() << "\n";
		file << user->def() << "\n";
		file << user->get_point_av() << "\n";
		file << user->get_point_max() << "\n";
		file << user->get_point_used_atk() << "\n";
		file << user->get_point_used_def() << "\n";
		file << user->get_point_used_hp() << "\n";
		file << user->get_point_used_sp() << "\n";
		file << user->get_potion_count() << "\n";

		file.close();

		EndDialog(-1);
	}

}

void Save::OnEnChangeEnterSaveName()
{
	CString txt;
	CWnd* textwindow = GetDlgItem(IDC_Enter_Save_Name);
	textwindow->GetWindowText(txt);
	save_name = txt;
}
