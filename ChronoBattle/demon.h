#pragma once
#include "enemy.h"
class demon :
	public enemy
{
public:
	demon();
	CString enemy_turn(unit* );
};

