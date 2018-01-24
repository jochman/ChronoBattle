
// ChronoBattle.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif
#include <afx.h>

#include "resource.h"		// main symbols
#include "hero.h"

// CChronoBattleApp:
// See ChronoBattle.cpp for the implementation of this class
//

class CChronoBattleApp : public CWinApp
{
public:
	CChronoBattleApp();

// Overrides
public:
	BOOL InitInstance() override;

// Implementation

	DECLARE_MESSAGE_MAP()

	hero *user;
	std::list<enemy>* enemylst{};
};



extern CChronoBattleApp theApp;