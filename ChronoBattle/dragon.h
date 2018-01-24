#pragma once
#include "enemy.h"
class dragon :
	public enemy
{
public:
	dragon();
	CString enemy_turn(unit*);
};

