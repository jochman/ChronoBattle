#pragma once
#include "enemy.h"
class metal_golem : 
		public enemy
{
public:
	metal_golem();
	CString enemy_turn(unit*);
};

