#pragma once
#include "enemy.h"
class cthulhu :
	public enemy
{
public:
	cthulhu();
	CString enemy_turn(unit* oppo);
};

