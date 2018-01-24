// Fight.cpp : implementation file
//

#include "stdafx.h"
#include "ChronoBattle.h"
#include "Fight.h"
#include "sp_attacks.h"
#include "afxdialogex.h"
#include "Conclusions.h"



// Fight dialog

IMPLEMENT_DYNAMIC(Fight, CDialogEx)

Fight::Fight(hero* user, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FIGHT, pParent)
	, IDC_BATTLELOG(_T(""))
	, IDC_BATTLELOG2(_T(""))
	, IDC_BATTLELOG3(_T(""))
	, av_potions(_T(""))
	, user(user)
	, opponent(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

Fight::Fight(hero * user, enemy * opponent, CWnd * pParent) 
	: CDialogEx(IDD_FIGHT, pParent)
	, IDC_BATTLELOG(_T(""))
	, IDC_BATTLELOG2(_T(""))
	, IDC_BATTLELOG3(_T(""))
	, av_potions(_T(""))
	, user(user)
	, opponent(opponent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

Fight::~Fight()
{
}

void Fight::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


void Fight::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Battle_Log, IDC_BATTLELOG);
	DDV_MaxChars(pDX, IDC_BATTLELOG, 150);

	DDX_Text(pDX, IDC_Battle_Log2, IDC_BATTLELOG2);
	DDV_MaxChars(pDX, IDC_BATTLELOG2, 150);

	DDX_Text(pDX, IDC_Battle_Log3, IDC_BATTLELOG3);
	DDV_MaxChars(pDX, IDC_BATTLELOG3, 150);
	DDX_Text(pDX, IDC_Potions, av_potions);
}


BEGIN_MESSAGE_MAP(Fight, CDialogEx)
	ON_BN_CLICKED(IDC_ATK, &Fight::OnBnClickedAtk)
	ON_BN_CLICKED(IDC_potion, &Fight::OnBnClickedPotion)

	ON_BN_CLICKED(IDC_Satk, &Fight::OnBnClickedSatk)
	ON_BN_CLICKED(IDC_Def, &Fight::OnBnClickedDef)
END_MESSAGE_MAP()


// Fight message handlers



BOOL Fight::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetOwner()->ShowWindow(FALSE);
	if (opponent == NULL)
		generate_enemy();
	shower();
	holder();
	i = -1;
	// TODO:  Add extra initialization here
	SetIcon(m_hIcon, TRUE);	// Set big icon
	SetIcon(m_hIcon, FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE

}


BOOL Fight::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
{
	// TODO: Add your specialized code here and/or call the base class

	return CDialogEx::Create(lpszTemplateName, pParentWnd);
}


void Fight::OnBnClickedAtk()
{
	enter_list();
	//triggering attack
	set_battlelog(user->attack(opponent));
	set_battlelog(opponent->enemy_turn(user));
	shower();
}

void Fight::set_battlelog(CString str)
{
	//updating battlelog. 3 - oldest, 1 - newest
	CWnd *label3 = GetDlgItem(IDC_Battle_Log3);
	CWnd *label2 = GetDlgItem(IDC_Battle_Log2);
	CWnd *label = GetDlgItem(IDC_Battle_Log);

	label->SetWindowText(str);
	label2->SetWindowText(IDC_BATTLELOG);
	label3->SetWindowText(IDC_BATTLELOG2);

	IDC_BATTLELOG3 = IDC_BATTLELOG2;
	IDC_BATTLELOG2 = IDC_BATTLELOG;
	IDC_BATTLELOG = str;
}

void Fight::shower()
{
	//updating text flow

	CString hero_hp_txt;
	CString opponent_hp_txt;
	CString hero_sp_txt;
	CString hero_potions_txt;

	/*	HERO BLOCK	*/
	//show the hero's hp
	hero_hp_txt.Format(L"%d / %d", user->hp_current(), user->hp_max());
	CWnd *hero1 = GetDlgItem(IDC_Hero_HP);
	hero1->SetWindowText(hero_hp_txt);

	//show the hero's sp
	hero_sp_txt.Format(L"%d / %d", user->sp_current(), user->sp_max());
	CWnd *hero2 = GetDlgItem(IDC_Hero_SP);
	hero2->SetWindowText(hero_sp_txt);

	/*	ENEMY BLOCK	*/
	//show the enemy's hp
	opponent_hp_txt.Format(L"%d / %d", opponent->hp_current(), opponent->hp_max());
	CWnd *opponentl = GetDlgItem(IDC_Enemy_hp);
	opponentl->SetWindowText(opponent_hp_txt);

	/*Potions */
	hero_potions_txt.Format(L"You have %d Potions", user->get_potion_count());
	CWnd *hero3 = GetDlgItem(IDC_Potions);
	hero3->SetWindowText(hero_potions_txt);

	//check if someone died
	check_condtion();


}

void Fight::holder()
{
	CString opponent_name_txt;
	CString Hero_name_txt;

	opponent_name_txt.Format(L"%s", opponent->name());
	CWnd *opponent1 = GetDlgItem(IDC_Enemy_Name);
	opponent1->SetWindowText(opponent_name_txt);

	Hero_name_txt.Format(L"%s", user->name());
	CWnd *hero1 = GetDlgItem(IDC_Hero_Name);
	hero1->SetWindowText(Hero_name_txt);

	DisplayBitmap();


}

void Fight::OnBnClickedPotion()
{
	enter_list();
	CString str = user->add_hp();
	set_battlelog(str);
	if (str.GetAt(0) == 'N') //no potion
		return shower();
	CString str2 = user->heal(user->hp_max() * 30 / 100);
	set_battlelog(str2);
	//opponent turn
	set_battlelog(opponent->enemy_turn(user));
	shower();
}



void Fight::OnBnClickedSatk()
{
	sp_attacks modal(user, *opponent, this);
	modal.DoModal();
	shower();
}


void Fight::OnBnClickedDef()
{
	enter_list();
	opponent->defend_debuff(2);
	set_battlelog(L"You're protected for 2 turns!");
	// reducing the enemy attack by 50%
	set_battlelog(opponent->enemy_turn(user));
	shower();
}

void Fight::DisplayBitmap()
{
	CStatic* enemy_image = (CStatic*)GetDlgItem(IDC_BITMAP_ENEMY);
	enemy_image->SetBitmap(opponent->hBmp());

	CStatic* hero_image = (CStatic*)GetDlgItem(IDC_BITMAP_HERO);
	hero_image->SetBitmap(user->hBmp());
}

void Fight::check_condtion()
{
	if (!user->hp_current()) {
		Conclusions c(true, opponent, this);
		c.DoModal();
		user->reborn();
		EndDialog(-1);
		GetOwner()->ShowWindow(TRUE);
	} // check who died and then open a conclusion window
	else if (!opponent->hp_current()) {
		Conclusions c(false, opponent, this);
		c.DoModal();
		user->reborn();
		get_rewards();
		EndDialog(-1);
		GetOwner()->ShowWindow(TRUE);
	}

}



void Fight::generate_enemy()
{
	srand(time(0));
	int factor = 1 + (rand() % 13);
	switch (factor) {

	case 1: opponent = new orc();
		break;
	case 2: opponent = new archer();
		break;
	case 3: opponent = new paladin();
		break;
	case 4: opponent = new Wizard();
		break;
	case 5: opponent = new goblin();
		break;
	case 6: opponent = new vampire();
		break;
	case 7: opponent = new wolf();
		break;
	case 8: opponent = new cthulhu();
		break;
	case 9: opponent = new zombie_warrior();
		break;
	case 10: opponent = new dragon();
		break;
	case 11: opponent = new demon();
		break;
	case 12: opponent = new metal_golem();
		break;
	case 13: opponent = new berserker();
		break;
	}

}


//function to create rewards
void Fight::get_rewards()
{

	user->inc_point_max(opponent->get_point());
	user->inc_point_av(opponent->get_point());
	user->inc_potion(opponent->get_potion());

}

void Fight::enter_list()
{
	if (hero_turns.size() == 3)
	{
		hero_turns.pop_back();
		enemy_turns.pop_back();
		i--;
	}
	hero_turns.push_back(*user);
	enemy_turns.push_back(*opponent);
	i++;

}

void Fight::cycle_list()
{
	CString str;
	if (hero_turns.size() == 0) {
		set_battlelog(CString("Can't use Time Warp!"));
		return;
	}
	user->decrease_sp(6);
	user->set_hp_max(hero_turns[i].hp_max());
	user->set_hp(hero_turns[i].hp_current());
	//user->set_sp(hero_turns[i].sp_current());
	user->set_sp_max(hero_turns[i].sp_max());
	user->set_atk(hero_turns[i].atk());
	user->set_def(hero_turns[i].def());
	user->set_potion_count(hero_turns[i].get_potion_count());


	opponent->set_hp_max(enemy_turns[i].hp_max());
	opponent->set_hp(enemy_turns[i].hp_current());
	opponent->set_sp(enemy_turns[i].sp_current());
	opponent->set_sp_max(enemy_turns[i].sp_max());
	opponent->set_atk(enemy_turns[i].atk());
	opponent->set_def(enemy_turns[i].def());

	hero_turns.pop_back();
	enemy_turns.pop_back();
	i--;
	str.Format(L"%s used Time Warp and went back in time!", user->name());
	set_battlelog(str);
}
