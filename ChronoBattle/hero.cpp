#include "stdafx.h"
#include "hero.h"

hero::hero(const CString& name) : unit(100, 2, 10, 2, name, L"res/Crono_.bmp"), potion_count_(3), stat_points_av(10), stat_points_max(0)
			,stat_points_used_hp(0), stat_points_used_sp(0), stat_points_used_atk(0), stat_points_used_def(0)
{
}


//geters and setters for stat points
int hero::get_point_max() {
	return stat_points_max;
}

int hero::get_point_av() {
	return stat_points_av;
}

int hero::get_point_used_hp()
{
	return stat_points_used_hp;
}

int hero::get_point_used_sp()
{
	return stat_points_used_sp;
}

int hero::get_point_used_atk()
{
	return stat_points_used_atk;
}

int hero::get_point_used_def()
{
	return stat_points_used_def;
}

void hero::set_point_max(int pm)
{
	stat_points_max = pm;
}

void hero::set_point_av(int pa)
{
	stat_points_av = pa;
}

void hero::set_point_used_hp(int uh)
{
	stat_points_used_hp = uh;
}

void hero::set_point_used_sp(int us)
{
	stat_points_used_sp = us;
}

void hero::set_point_used_atk(int ua)
{
	stat_points_used_atk = ua;
}

void hero::set_point_used_def(int ud)
{
	stat_points_used_def = ud;
}

void hero::set_potion_count(int potion)
{
	potion_count_ = potion;
}



void hero::inc_point_max(int num) {

	stat_points_max += num;
}

void hero::dec_point_max(int num) {

	stat_points_max -= num;
}

void hero::inc_point_av(int num) {

	stat_points_av += num;
}

void hero::dec_point_av(int num) {

	stat_points_av -= num;
}

void hero::inc_point_used_hp(int num)
{
	stat_points_used_hp += num;
}

void hero::dec_point_used_hp(int num)
{
	stat_points_used_hp -= num;
}

void hero::inc_point_used_sp(int num)
{
	stat_points_used_sp += num;
}

void hero::dec_point_used_sp(int num)
{
	stat_points_used_sp -= num;
}

void hero::inc_point_used_atk(int num)
{
	stat_points_used_atk += num;
}


void hero::dec_point_used_atk(int num)
{
	stat_points_used_atk -= num;
}

void hero::inc_point_used_def(int num)
{
	stat_points_used_def += num;
}

void hero::dec_point_used_def(int num)
{
	stat_points_used_def -= num;
}

void hero::inc_potion(int num)
{
	potion_count_ += num;
}

int hero::get_potion_count()
{
	return potion_count_;
}



CString hero::add_hp(){
	CString str;
	if (potion_count_ > 0)
	{
		--potion_count_;
		str.Format(L"%d potions left", potion_count_);
		return str;
	}
	str.Format(L"No potions left!");
	return str;
}

CString hero::cyclone_strike(enemy& oppo)
{
	CString str;

	if (sp_current() > 3) {
		decrease_sp(4);
		oppo.defend_debuff(2);
		int dmg = hurt(atk()*double(2.0), oppo);
		if (dmg == 0) {
			str.Format(L"%s used Cyclone Strike and dealt a mortal blow to %s!", name(), oppo.name());
			return str;
		}
		str.Format(L"%s used Cyclone Strike and dealt %d damage to %s", name(), dmg, oppo.name());
		return str;
	}
	return str;
}




