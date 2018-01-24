#pragma once
#include "enemy.h"
class paladin :
	public enemy
{
public:
	paladin();
	CString enemy_turn(unit* oppo);
};

