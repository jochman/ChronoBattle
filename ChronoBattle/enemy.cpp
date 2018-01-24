#include "stdafx.h"
#include "enemy.h"
#include <ctime>


enemy::enemy(const int& hp_max, const int& sp_max, const int& atk, const int& def, const CString& name, int cost1, int cost2, double multiplier1,
	double multiplier2,int point,int potion, const CString& bmpPath, CString sp_attack_name, CString sp_attack_name2)
	: unit(hp_max, sp_max, atk, def, name, bmpPath), multiplier_(multiplier1), multiplier2_(multiplier2),
	sp_attack_name_(sp_attack_name), sp_attack_name2_(sp_attack_name2), cost1_(cost1), cost2_(cost2),point_(point),potion_(potion)
{
}

CString enemy::enemy_turn(unit* oppo) 
{
	CString str;
	bool act_ = false;
	int factor;
	srand(time(0)); //creating random seed
	while (!act_ && hp_current()) //while enemy didnt attack
	{
		(sp_current() < cost1_) ? factor = 10 : factor = rand() % 100;		/*if no enought sp points, do attack*/
		if (factor <= 50) { str = attack(oppo); act_ = true; }				/*regular attack*/
		else if (factor <= 85) str = str = sp_attack(oppo, act_, multiplier_, sp_attack_name(), cost1_);		/*special attack*/
		else  str = sp_attack(oppo, act_, multiplier2_, sp_attack_name2(), cost2_);	/*special attack2*/
	}
	def_cycle(); /*triggering def cycle*/
	return str;
}

CString enemy::sp_attack(unit* oppo, bool& act, double multiplier, CString sp_name, int cost)
{
	CString str;
	if (sp_current() >= cost) {
		decrease_sp(cost);
		act = true;
		int dmg = hurt(atk()*double(multiplier), oppo);
		if (dmg == 0) {
			str.Format(L"%s used %s and dealt a mortal blow to %s!", name(), sp_name, oppo->name());
			return str;
		}
		str.Format(L"%s used %s and dealt %d damage to %s", name(), sp_name, dmg, oppo->name());
		return str;
	}
	return str;
}

int enemy::get_point()
{
	return point_;
}

int enemy::get_potion()
{
	return potion_;
}

double enemy::multiplier() const
{
	return multiplier_;
}

CString enemy::sp_attack_name() const
{
	return sp_attack_name_;
}

CString enemy::sp_attack_name2() const
{
	return sp_attack_name2_;
}