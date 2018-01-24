#include "stdafx.h"
#include "paladin.h"


paladin::paladin() :enemy(200, 20, 17, 20, CString("Paladin"), 4, 8,1.2,0,2,1, CString(L"res/paladin.bmp"), L"Judgment", L"Lay on Hands")
{
}

CString paladin::enemy_turn(unit* oppo)
{
	CString str;

	bool act_ = false;

	while (!act_&& hp_current()>0) //while enemy didnt attack and is alive
	{
		srand(time(0));
		int factor = 1 + (rand() % 100);
		(sp_current() < cost1_) ? factor = 10 : factor = rand() % 100;		/*if no enought sp points, do attack*/
		if (factor <= 50) {
			str = attack(oppo); act_ = true;
		}
		else if (factor <= 75) str = sp_attack(oppo, act_, multiplier_, sp_attack_name(), cost1_);
		else {
			if (hp_current() <= 150) {
				str.Format(L"%s used %s, ", name(), sp_attack_name2());
				decrease_sp(cost2_);
				str += heal(50);
				act_ = true;
			}
		}
	}
	def_cycle();
	return str;
}
