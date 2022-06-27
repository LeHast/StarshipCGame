#pragma once

#include "Pawn.hpp"

namespace hast {

enum class Direction{
	Left,
	Right,
};

class Player: public hast::Pawn{
public:
	Player();

	void Move(hast::Direction);
	void ChangeSpeed(float);

private:
	float m_speed;
	int m_lives;


};
}

