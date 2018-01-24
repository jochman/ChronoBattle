#pragma once
#include "enemy.h"

class vampire :
	public enemy
{
public:
	vampire();

	CString enemy_turn(unit* oppo);
	
};

