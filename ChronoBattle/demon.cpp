#include "stdafx.h"
#include "demon.h"


demon::demon() :enemy(350, 35, 60, 28, CString("Demon"), 3, 7, 2, 3.5, 5, 2, CString(L"res/demon.bmp"), L"Shadow Bolt", L"Chaos Warp")
{
}

CString demon::enemy_turn(unit* oppo)
{
	CString str;


	bool act_ = false;

	while (!act_&&hp_current() > 0) //while enemy didnt attack and is alive
	{
		srand(time(0));
		int factor = 1 + (rand() % 100);
		(sp_current() < cost1_) ? factor = 10 : factor = rand() % 100;		/*if no enought sp points, do attack*/
		if (factor <= 35) {
			str = attack(oppo); act_ = true;
		}
		else if (factor <= 75) {
			str = sp_attack(oppo, act_, multiplier_, sp_attack_name(), cost1_);
		}
		else {
			str = sp_attack(oppo, act_, multiplier2_, sp_attack_name2(), cost2_);
			oppo->decrease_sp(8);
			if (oppo->sp_current() < 8) {
				oppo->set_sp(0);
				str += ", you lost your sp!";
			}
			else
				str += ", you lost 8 sp!";
		}
	}
	def_cycle();
	return str;
}



