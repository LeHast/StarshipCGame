#pragma once

#include "Pawn.hpp"

namespace hast {
// Enum Class for the direction of the player.
enum class Direction{
	Left,
	Right,
};

// Player Class
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

