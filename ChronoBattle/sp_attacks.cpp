// sp_attacks.cpp : implementation file
//

#include "stdafx.h"
#include "ChronoBattle.h"
#include "sp_attacks.h"
#include "afxdialogex.h"


// sp_attacks dialog

IMPLEMENT_DYNAMIC(sp_attacks, CDialogEx)

sp_attacks::sp_attacks(hero* user, enemy& opponent ,Fight* pParent /*=NULL*/)
	: CDialogEx(IDD_SP_ATTACKS, pParent), parent(pParent), user(user), opponent(&opponent)
{

}

sp_attacks::~sp_attacks()
{
}

void sp_attacks::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(sp_attacks, CDialogEx)
	ON_BN_CLICKED(IDC_Cyclone_strike, &sp_attacks::OnBnClickedCyclonestrike)
	ON_BN_CLICKED(IDC_Time_heal, &sp_attacks::OnBnClickedTimeheal)
	ON_BN_CLICKED(IDC_Time_warp, &sp_attacks::OnBnClickedTimewarp)
END_MESSAGE_MAP()


// sp_attacks message handlers


void sp_attacks::OnBnClickedCyclonestrike()
{
	ASSERT(parent);
	parent->enter_list();
	if (user->sp_current() < 4)
	{
		parent->set_battlelog(L"You don't have enough sp!");
		EndDialog(-1);
		return;
	}
	parent->set_battlelog(user->cyclone_strike(*opponent));
	parent->set_battlelog(L"You're protected for 2 turns!");
	parent->set_battlelog(opponent->enemy_turn(user));
	EndDialog(-1);
}

void sp_attacks::OnBnClickedTimeheal()
{
	ASSERT(parent);
	CString str;
	parent->enter_list();
	if (user->sp_current() < 12)
	{
		parent->set_battlelog(L"You don't have enough sp!");
		EndDialog(-1);
		return;
	}
	user->set_hp(user->hp_max());
	str.Format(L"%s used Time Heal and was heal to full hp!", user->name());
	user->decrease_sp(12);
	parent->set_battlelog(str);
	parent->set_battlelog(opponent->enemy_turn(user));
	EndDialog(-1);
}


void sp_attacks::OnBnClickedTimewarp()
{
	ASSERT(parent);
	if (user->sp_current() < 6) {
		parent->set_battlelog(L"You don't have enough sp!");
		EndDialog(-1);
		return;
	}
	parent->cycle_list();
	EndDialog(-1);
}
