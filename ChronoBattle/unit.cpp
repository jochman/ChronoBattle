#include "stdafx.h"
#include "unit.h"
#include <string>
#include "resource.h"

unit::unit(const int& hp_max, const int& sp_max, const int& atk, const int& def, const CString& name,
	const CString bmp_path)
	: hp_max_(hp_max),
	hp_current_(hp_max),
	sp_max_(sp_max),
	sp_current_(sp_max),
	atk_(atk),
	def_(def),
	name_(name),
	hBmp_(HBITMAP(LoadImage(nullptr, bmp_path, IMAGE_BITMAP, 250, 200, LR_LOADFROMFILE)))/*Loading image*/
	, def_flag_(false),
	defend_turn_counter_(0){}


// getting for a unit stat
int unit::hp_max() const
{
	return hp_max_;
}

int unit::hp_current() const
{
	return hp_current_;
}

int unit::sp_max() const
{
	return sp_max_;
}

int unit::sp_current() const
{
	return sp_current_;
}
int unit::cAtk()const { return atk_; }
int unit::atk() const
{
	int atk = atk_;
	if (def_flag()) /*if defense debuff is active, cut attack*/
	{
		atk /= 2;
		return atk;
	}
	return this->atk_;
}
int unit::cDef()const{
	return def_;
}
int unit::def() const
{
	int def = def_;
	if (debuff_flag()) {

		def *= 2;
		return def;
		}
	return this->def_;
}


//inc and dec for units stats

void unit::inc_hp_max(int num)
{
	hp_max_ += num;
}

void unit::dec_hp_max(int num)
{
	hp_max_ -= num;
}

void unit::inc_sp_max(int num)
{
	sp_max_ += num;
}

void unit::dec_sp_max(int num)
{
	sp_max_ -= num;
}

void unit::inc_atk(int num)
{
	atk_ += num;
}

void unit::dec_atk(int num)
{
	atk_ -= num;
}

void unit::inc_def(int num)
{
	def_ += num;
}

void unit::dec_def(int num)
{
	def_ -= num;
}



//units fancutions
void unit::set_atk(int atk)
{
	this->atk_ = atk;
}

void unit::set_def(int def)
{
	def_ = def;
}

void unit::decrease_sp(int dec)
{
	sp_current_ -= dec;
}

void unit::set_hp(int hp)
{
	hp_current_ = hp;
}

void unit::set_hp_max(int hp)
{
	hp_max_ = hp;
}

void unit::set_sp(int sp)
{
	sp_current_ = sp;
}

void unit::set_sp_max(int sp)
{
	sp_max_ = sp;
}

void unit::reborn()
{
	hp_current_ = hp_max_;
	sp_current_ = sp_max_;
}

CString unit::name() const
{
	return name_;
}

void unit::set_name(CString name)
{
	name_ = name;
}



CString unit::heal(const int hp)
{
	CString str;
	hp_current_ += hp;
	str.Format(L"%s was healed for %d hp!", this->name(), hp);
	if (hp_current_ > hp_max_)
		hp_current_ = hp_max_;
	return str;
}

CString unit::attack(unit* enemy){
	CString str;
	int dmg = hurt(atk(),enemy);
	if (dmg==0) {
		str.Format (L"%s has dealt a mortal blow to %s!", name() ,enemy->name());
		return str;
	}
	str.Format(L"%s dealt %d damage to %s", name(), dmg ,enemy->name());
	return str;
}

CString unit::attack(unit& enemy)
{
	CString str;
	int dmg = hurt(atk(), enemy);
	if (dmg == 0) {
		str.Format(L"%s has dealt a mortal blow to %s!", name(), enemy.name());
		return str;
	}
	str.Format(L"%s dealt %d damage to %s", name(), dmg, enemy.name());
	return str;
}

HBITMAP& unit::hBmp()
{
	return hBmp_;
}

int unit::hurt(const int& dmg, unit* enemy)
{
	int hurt;
	if (dmg <= enemy->def_)
		hurt = 1;
	else hurt = dmg - enemy->def_;

	if (enemy->hp_current_ - hurt <= 0) {  //if I dead
		enemy->set_hp(0);
		return 0;
	}

	enemy->hp_current_ -= hurt; //if I survived
	return hurt;
}

int unit::hurt(const int& dmg, unit& enemy)
{
	int hurt;
	if (dmg <= enemy.def_)
		hurt = 1;
	else hurt = dmg - enemy.def_;

	if (enemy.hp_current_ - hurt <= 0) { //if I dead
		enemy.set_hp(0);
		return 0;
	}
	enemy.hp_current_ -= hurt; //if I survived
	return hurt;
}

void unit::defend_debuff(const int turns /* = 2*/)
{
	def_flag_ = true;
	defend_turn_counter_ = turns;
}

void unit::general_debuff(int turns)
{
	debuff_flag_ = true;
	debuff_turn_counter_ = turns;
}

int unit::get_defend_debuff()
{
	return defend_turn_counter_;
}

int unit::get_general_debuff()
{
	return debuff_turn_counter_;
}



bool unit::def_flag() const
{
	return def_flag_;
}

bool unit::debuff_flag() const
{
	return debuff_flag_;
}

void unit::def_cycle()
{
	if (def_flag_)
		defend_turn_counter_--;
	if (defend_turn_counter_ == 0)
		def_flag_ = false;
}

void unit::debuff_cycle()
{
	if (debuff_flag_)
		debuff_turn_counter_--;
	if (debuff_turn_counter_ == 0)
		debuff_flag_ = false;
}

CString unit::sp_attack(unit* oppo, bool& act, double multiplier, CString sp_name, int cost)
{
	CString str;
	if (sp_current() >= cost) {
		decrease_sp(cost);
		act = true;
		int dmg = hurt(atk()*double(multiplier), oppo);
		if (dmg == 0) {
			str.Format(L"%s used %s and dealt a mortal blow to %s! ", name(), sp_name, oppo->name());
			return str;
		}
		str.Format(L"%s used %s and dealt %d damage to %s ", name(), sp_name, dmg, oppo->name());
		return str;
	}
	return str;
}

