#include "stdafx.h"
#include "metal_golem.h"


metal_golem::metal_golem() :enemy(300, 15, 40, 80, CString("Metal Golem"), 3, 7, 3, 0, 3, 0, CString(L"res/metal_golem.bmp"), L"Metal Slam", L"Iron Defanse")
{
}

CString metal_golem::enemy_turn(unit* oppo)
{
	CString str;

	bool act_ = false;

	while (!act_&& hp_current() > 0) //while enemy didnt attack and is alive
	{
		srand(time(0));
		int factor = 1 + (rand() % 100);
		(sp_current() < cost1_) ? factor = 10 : factor = rand() % 100;		/*if no enought sp points, do attack*/
		if (factor <= 50) {
			str = attack(oppo); act_ = true;
		}
		else if (factor <= 85) str = sp_attack(oppo, act_, multiplier_, sp_attack_name(), cost1_);
		else {
			this->general_debuff(2);
			str.Format(L"%s used %s, and is protected for 2 turns!", name(), sp_attack_name2());
			decrease_sp(cost2_);
			act_ = true;
		}
	}


	def_cycle();
	debuff_cycle();
	return str;
}

