#include "stdafx.h"
#include "vampire.h"


vampire::vampire():enemy(150, 10, 19, 8, CString("Vampire"), 3, 7, 1.5, 2.2,2,0, CString(L"res/vampire.bmp"), L"Leech", L"Shadow Strike")
{
}


CString vampire::enemy_turn(unit* oppo)
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
		else if (factor <= 85) {
			str = sp_attack(oppo, act_, multiplier_, sp_attack_name(), cost1_);
			str += (L", ");
			str += heal(atk()*1.2);
		}
		else { str = sp_attack(oppo, act_, multiplier2_, sp_attack_name2(), cost2_); }
	}
	def_cycle();
	return str;
}