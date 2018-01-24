#include "stdafx.h"
#include "cthulhu.h"


cthulhu::cthulhu() :enemy(1200, 45, 100, 85, CString("Cthulhu"), 4, 9, 1.5, 4, 15, 10, CString(L"res/cthulhu.bmp"), L"Mind Blast", L"Break of Reality")
{
}

CString cthulhu::enemy_turn(unit* oppo)
{
	CString str;


	bool act_ = false;

	while (!act_&&hp_current() > 0) //while enemy didnt attack and is alive
	{
		srand(time(0));
		int factor = 1 + (rand() % 100);
		(sp_current() < cost1_) ? factor = 10 : factor = rand() % 100;		/*if no enought sp points, do attack*/
		if (factor <= 50) {
			str = attack(oppo); act_ = true;
		}
		else if (factor <= 85) {
			str = sp_attack(oppo, act_, multiplier_, sp_attack_name(), cost1_);
			oppo->decrease_sp(10);
			if (oppo->sp_current()<10) {
				oppo->set_sp(0);
				str += ", you lost your sp!";
			}
			else
			str += ", you lost 10 sp!";
		}
		else { str = sp_attack(oppo, act_, multiplier2_, sp_attack_name2(), cost2_); }
	}
	def_cycle();
	return str;
}

