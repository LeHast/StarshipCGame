#include "Player.hpp"

#define dt m_dealtaTime

hast::Player::Player(){
	m_lives = 3;
	m_speed = 300;
}

void hast::Player::Move(hast::Direction dir){

	switch (dir) {
	case hast::Direction::Left:
		m_sprite.move((-1 * m_speed * dt), 0);
		break;

	case hast::Direction::Right:
		m_sprite.move((1 * m_speed * dt), 0);
		break;

	default:
		break;
	}

}


void hast::Player::ChangeSpeed(float toSp){
	m_speed = toSp;
}
