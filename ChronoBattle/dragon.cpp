#include "stdafx.h"
#include "dragon.h"


dragon::dragon() : enemy(500, 25, 40, 30, CString("Dragon"), 3, 8, 1.8, 3, 5, 3, CString(L"res/dragon.bmp"), L"Tail Swipe", L"Dragon Breath")
{

}

CString dragon::enemy_turn(unit* oppo)
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
		else if (factor <= 85) { str = sp_attack(oppo, act_, multiplier_, sp_attack_name(), cost1_); }
		else {
			str = sp_attack(oppo, act_, multiplier2_, sp_attack_name2(), cost2_);
			oppo->decrease_sp(4);
			if (oppo->sp_current() < 4) {
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


