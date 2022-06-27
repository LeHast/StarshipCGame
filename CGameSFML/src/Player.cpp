#include "Player.hpp"

hast::Player::Player(){
	m_lives = 3;
	m_speed = 30;
}

void hast::Player::Move(hast::Direction dir){
	switch (dir) {
	case hast::Direction::Left:
		m_sprite.move((-1 * m_speed) , 0);
		break;

	case hast::Direction::Right:
		m_sprite.move((1 * m_speed), 0);
		break;

	default:
		break;
	}

}


void hast::Player::ChangeSpeed(float toSp){
	m_speed = toSp;
}
