#pragma once
#include "Header.h"

class hero :
	public unit
{
public:
	hero(const CString& name);
	CString add_hp();

	CString cyclone_strike(enemy& opponent);

	

	//geters and setters for stat points
	int get_point_max();
	int get_point_av();

	int get_point_used_hp();
	int get_point_used_sp();
	int get_point_used_atk();
	int get_point_used_def();
	int get_potion_count();

	void set_point_max(int);
	void set_point_av(int);

	void set_point_used_hp(int);
	void set_point_used_sp(int);
	void set_point_used_atk(int);
	void set_point_used_def(int);
	void set_potion_count(int);


	void inc_point_max(int num);
	void dec_point_max(int num);

	void inc_point_av(int num);
	void dec_point_av(int num);

	void inc_point_used_hp(int num);
	void dec_point_used_hp(int num);

	void inc_point_used_sp(int num);
	void dec_point_used_sp(int num);

	void inc_point_used_atk(int num);
	void dec_point_used_atk(int num);

	void inc_point_used_def(int num);
	void dec_point_used_def(int num);

	void inc_potion(int num);
	

private:
	int potion_count_;
	int stat_points_max;
	int stat_points_av;
	int stat_points_used_hp;
	int stat_points_used_sp;
	int stat_points_used_atk;
	int stat_points_used_def;
};

