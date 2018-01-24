// Conclusions.cpp : implementation file
//

#include "stdafx.h"
#include "ChronoBattle.h"
#include "Conclusions.h"
#include "afxdialogex.h"


// Conclusions dialog

IMPLEMENT_DYNAMIC(Conclusions, CDialogEx)

Conclusions::Conclusions(bool ifwon,enemy* opponent, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CONCLUSIONS, pParent)
	, IDC_CON(_T("")), ifwon(ifwon),opponent(opponent),user(user)
	, Reward(_T(""))
{

}

Conclusions::~Conclusions()
{
}

void Conclusions::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialogEx::OnFinalRelease();
}

void Conclusions::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONC, IDC_CON);
	DDV_MaxChars(pDX, IDC_CON, 100);
	DDX_Text(pDX, IDC_Rewards, Reward);
}


BEGIN_MESSAGE_MAP(Conclusions, CDialogEx)
	ON_BN_CLICKED(IDOK, &Conclusions::OnBnClickedOk)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Conclusions, CDialogEx)
END_DISPATCH_MAP()

// Note: we add support for IID_Ionclusions to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {D35A8581-AF24-4E66-835C-8A22F29FD408}
static const IID IID_Ionclusions =
{ 0xD35A8581, 0xAF24, 0x4E66, { 0x83, 0x5C, 0x8A, 0x22, 0xF2, 0x9F, 0xD4, 0x8 } };

BEGIN_INTERFACE_MAP(Conclusions, CDialogEx)
	INTERFACE_PART(Conclusions, IID_Ionclusions, Dispatch)
END_INTERFACE_MAP()


// Conclusions message handlers


void Conclusions::OnBnClickedOk()
{
	
	CDialogEx::OnOK();
}


BOOL Conclusions::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	show_text(ifwon);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
//function to show the conclusion text and getting the rewards
void Conclusions::show_text(bool check)
{
	CString str;
	CString str2;
	
	CWnd* label = GetDlgItem(IDC_CONC);
	CWnd* label2 = GetDlgItem(IDC_Rewards);
	if (!check)
	{
		str.Format(L"You have killed the enemy and won the battle!");
		str2.Format(L"You won %d Talent Points and %d new Potions!", opponent->get_point(), opponent->get_potion());
		
	}
	else
	{
		str.Format(L"You died and lost the battle!");
		str2.Format(L"You lost so no rewards for you!");
		
	}

	label->SetWindowText(str);
	label2->SetWindowText(str2);
}

