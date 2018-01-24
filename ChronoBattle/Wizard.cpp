#include "stdafx.h"
#include "Wizard.h"


Wizard::Wizard():enemy(70, 20, 12, 1, CString("Wizard"), 3, 8,2,3.5,1,2,CString(L"res/wizard.bmp"), L"Magic Missile", L"Arcane Orb")
{
}


CString Wizard::enemy_turn(unit* oppo)
{
	CString str;


	bool act_ = false;

	while (!act_&&hp_current()>0) //while enemy didnt attack and is alive
	{
		srand(time(0));
		int factor = 1 + (rand() % 100);
		(sp_current() < cost1_) ? factor = 10 : factor = rand() % 100;		/*if no enought sp points, do attack*/
		if (factor <= 20) {
			str = attack(oppo); act_ = true;
		}
		else if (factor <= 70) str = sp_attack(oppo, act_, multiplier_, sp_attack_name(), cost1_);
		else { str = sp_attack(oppo, act_, multiplier2_, sp_attack_name2(), cost2_); }
	}
	def_cycle();
	return str;
}