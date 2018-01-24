
// ChronoBattleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChronoBattle.h"
#include "ChronoBattleDlg.h"
#include "afxdialogex.h"
#include "fight.h"
#include "Stats.h"
#include "Save.h"
#include "Load.h"
#include "CustomEnemyDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChronoBattleDlg dialog



CChronoBattleDlg::CChronoBattleDlg(hero* user, std::list<enemy>* enemylst,CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHRONOBATTLE_DIALOG, pParent),user(user), enemylst(enemylst)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChronoBattleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChronoBattleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FIND, &CChronoBattleDlg::OnBnClickedFind)
	ON_BN_CLICKED(IDD_Exit, &CChronoBattleDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_Save, &CChronoBattleDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_Save, &CChronoBattleDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_Load, &CChronoBattleDlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_Hero_Stats2, &CChronoBattleDlg::OnBnClickedHeroStats2)
	ON_BN_CLICKED(IDC_CUSTOM_ENEMY, &CChronoBattleDlg::OnBnClickedCustomEnemy)
END_MESSAGE_MAP()


// CChronoBattleDlg message handlers

BOOL CChronoBattleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChronoBattleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CChronoBattleDlg::OnPaint()
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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CChronoBattleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChronoBattleDlg::OnBnClickedFind()
{
	Fight f(user, this);
	f.DoModal();
}

void CChronoBattleDlg::OnBnClickedExit()
{
	this->DestroyWindow();
}

void CChronoBattleDlg::OnBnClickedSave()
{
	Save s(user, this);
	s.DoModal();
}


void CChronoBattleDlg::OnBnClickedLoad()
{
	Load l(user, this);
	l.DoModal();
}


void CChronoBattleDlg::OnBnClickedHeroStats2()
{
	Stats s(user, this);
	s.DoModal();
}


void CChronoBattleDlg::OnBnClickedCustomEnemy()
{
	CustomEnemyDLG dlg(enemylst, user, this);
	dlg.DoModal();
}

void CChronoBattleDlg::custom_fight(enemy * opponent)
{
	Fight f(user, opponent);
	f.DoModal();
}
