#pragma once
#include "enemy.h"
class Wizard :
	public enemy
{
public:
	Wizard();
	CString enemy_turn(unit* oppo);
};

