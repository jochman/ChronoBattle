// Stats.cpp : implementation file
//

#include "stdafx.h"
#include "ChronoBattle.h"
#include "Stats.h"
#include "afxdialogex.h"
#include "hero.h"

// Stats dialog

IMPLEMENT_DYNAMIC(Stats, CDialogEx)

Stats::Stats(hero* user, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STATS, pParent), user(user)
	, av_hp(_T(""))
	, av_sp(_T(""))
	, av_atk(_T(""))
	, av_def(_T(""))
	, show_potion(_T(""))
	, edit_hero_name(_T(""))
	, stat_pnt(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

Stats::~Stats()
{
}

void Stats::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Stat_Points, stat_pnt);
	DDV_MaxChars(pDX, stat_pnt, 100);
	DDX_Text(pDX, IDC_av_hp, av_hp);
	DDX_Text(pDX, IDC_av_sp, av_sp);
	DDX_Text(pDX, IDC_av_atk, av_atk);
	DDX_Text(pDX, IDC_av_def, av_def);
	DDX_Text(pDX, IDC_Potions, show_potion);
	DDX_Text(pDX, IDC_Edit_Hero_Name, edit_hero_name);
}

void Stats::DisplayBitmap() const
// set the hero img
{

    CStatic* hero_image = (CStatic*)GetDlgItem(IDC_BITMAP_HERO);
	hero_image->SetBitmap(user->hBmp());
}

void Stats::updater() // updating all the info on the screen
{
	CString hero_hp_txt;
	CString hero_sp_txt;
	CString hero_atk_txt;
	CString hero_def_txt;
	CString stat_points_txt;
	CString av_hp_txt;
	CString av_sp_txt;
	CString av_atk_txt;
	CString av_def_txt;
	CString hero_potions_txt;
	CString hero_name_txt;

	hero_hp_txt.Format(L"%d", user->hp_max());
	CWnd *hero1 = GetDlgItem(IDC_HP_Stat);
	hero1->SetWindowText(hero_hp_txt);

	hero_sp_txt.Format(L"%d", user->sp_max());
	CWnd *hero2 = GetDlgItem(IDC_SP_Stat);
	hero2->SetWindowText(hero_sp_txt);

	hero_atk_txt.Format(L"%d", user->atk());
	CWnd *hero3 = GetDlgItem(IDC_Atk_Stat);
	hero3->SetWindowText(hero_atk_txt);

	hero_def_txt.Format(L"%d", user->def());
	CWnd *hero4 = GetDlgItem(IDC_Def_Stat);
	hero4->SetWindowText(hero_def_txt);

	stat_points_txt.Format(L"%d / %d", user->get_point_av(), user->get_point_max());
	CWnd *stats = GetDlgItem(IDC_Stat_Points);
	stats->SetWindowText(stat_points_txt);

	av_hp_txt.Format(L"%d", user->get_point_used_hp());
	CWnd *av1 = GetDlgItem(IDC_av_hp);
	av1->SetWindowText(av_hp_txt);

	av_sp_txt.Format(L"%d", user->get_point_used_sp());
	CWnd *av2 = GetDlgItem(IDC_av_sp);
	av2->SetWindowText(av_sp_txt);

	av_atk_txt.Format(L"%d", user->get_point_used_atk());
	CWnd *av3 = GetDlgItem(IDC_av_atk);
	av3->SetWindowText(av_atk_txt);

	av_def_txt.Format(L"%d", user->get_point_used_def());
	CWnd *av4 = GetDlgItem(IDC_av_def);
	av4->SetWindowText(av_def_txt);

	hero_potions_txt.Format(L"You have %d Potions", user->get_potion_count());
	CWnd *hero5 = GetDlgItem(IDC_Potions);
	hero5->SetWindowText(hero_potions_txt);

	hero_name_txt.Format(L"%s", user->name());
	CWnd *hero6 = GetDlgItem(IDC_Edit_Hero_Name);
	hero6->SetWindowText(hero_name_txt);
}

void Stats::OnOk() 
{
	return;
}


BOOL Stats::OnInitDialog() 
{
	CDialogEx::OnInitDialog();
	GetOwner()->ShowWindow(FALSE);
	DisplayBitmap();
	updater();

	SetIcon(m_hIcon, TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


BEGIN_MESSAGE_MAP(Stats, CDialogEx)
	ON_BN_CLICKED(IDC_inc_hp, &Stats::OnBnClickedinchp)
	ON_BN_CLICKED(IDC_inc_atk, &Stats::OnBnClickedincatk)
	ON_BN_CLICKED(IDC_Inc_sp, &Stats::OnBnClickedIncsp)
	ON_BN_CLICKED(IDC_inc_def, &Stats::OnBnClickedincdef)
	ON_BN_CLICKED(IDC_Back, &Stats::OnBnClickedBack)
	ON_BN_CLICKED(IDC_dec_hp, &Stats::OnBnClickeddechp)
	ON_BN_CLICKED(IDC_dec_sp, &Stats::OnBnClickeddecsp)
	ON_BN_CLICKED(IDC_dec_atk, &Stats::OnBnClickeddecatk)
	ON_BN_CLICKED(IDC_dec_def, &Stats::OnBnClickeddecdef)
	ON_EN_CHANGE(IDC_Edit_Hero_Name, &Stats::OnEnChangeEditHeroName)
END_MESSAGE_MAP()

//increase the stats
void Stats::OnBnClickedinchp() //inc the hp and dec the stat points avilable
{
	if (user->get_point_av())
	{
		user->dec_point_av(1);
		user->inc_point_used_hp(1);
		user->inc_hp_max(5);
		user->set_hp(user->hp_max());
	}
	
	updater();
}
void Stats::OnBnClickedincatk()// same as hp and all the rest of the stats;
{

	if (user->get_point_av())
	{
		user->dec_point_av(1);
		user->inc_point_used_atk(1);
		user->inc_atk(1);
	}

	updater();
	
}
void Stats::OnBnClickedIncsp()
{
	if (user->get_point_av())
	{
		user->dec_point_av(1);
		user->inc_point_used_sp(1);
		user->inc_sp_max(1);
		user->set_sp(user->sp_max());

	}

	updater();
}
void Stats::OnBnClickedincdef()
{
	if (user->get_point_av())
	{
		user->dec_point_av(1);
		user->inc_point_used_def(1);
		user->inc_def(1);
	}

	updater();
}

void Stats::OnBnClickedBack() // go back to main manu
{
	GetOwner()->ShowWindow(TRUE);
	EndDialog(-1);
}

//decrease the stats
void Stats::OnBnClickeddechp() 
{
	if (user->get_point_used_hp())
	{
		user->inc_point_av(1);
		user->dec_point_used_hp(1);
		user->dec_hp_max(5);
		user->set_hp(user->hp_max());

	}
	updater();
}
void Stats::OnBnClickeddecsp()
{
	if (user->get_point_used_sp())
	{
		user->inc_point_av(1);
		user->dec_point_used_sp(1);
		user->dec_sp_max(1);
		user->set_sp(user->sp_max());

	}
	updater();
}
void Stats::OnBnClickeddecatk()
{
	if (user->get_point_used_atk())
	{
		user->inc_point_av(1);
		user->dec_point_used_atk(1);
		user->dec_atk(1);
		
	}
	updater();
	
}
void Stats::OnBnClickeddecdef()
{
	if (user->get_point_used_def())
	{
		user->inc_point_av(1);
		user->dec_point_used_def(1);
		user->dec_def(1);

	}
	updater();
}


void Stats::OnEnChangeEditHeroName()
{
	CString txt;
	CWnd* textwindow = GetDlgItem(IDC_Edit_Hero_Name);
	textwindow->GetWindowText(txt);
	user->set_name(txt);

}
