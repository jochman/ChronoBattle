#pragma once
#include "unit.h"
class enemy :
	public unit
{
public:
	enemy(const int& hp_max, const int& sp_max, const int& atk, const int& def, const CString& name, int cost1 = 2, int cost2 = 4, double multiplier1 = 1.2,
		double multiplier2 = 1.5 ,int point = 0,int potion = 0,const CString& bmpPath = L"res/enemy.bmp",
		CString sp_attack_name = L"special attack", CString sp_attack_name2 = L"special attack2");
	virtual CString enemy_turn(unit* oppo);
	virtual CString sp_attack(unit* oppo, bool& act, double multiplier, CString sp_name, int cost);

	int get_point();
	int get_potion();

protected:
	virtual double multiplier() const;
	CString sp_attack_name() const;
	CString sp_attack_name2() const;

	double multiplier_;
	double multiplier2_;
	CString sp_attack_name_;
	CString sp_attack_name2_;
	int cost1_;
	int cost2_;
	int point_;
	int potion_;
};

