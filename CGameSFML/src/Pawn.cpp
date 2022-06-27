#include "Pawn.hpp"

hast::Pawn::Pawn(){
}

hast::Pawn::~Pawn(){
}

void hast::Pawn::Update(){
	
}

void hast::Pawn::Render(sf::RenderWindow& m_window){
	m_window.draw(m_sprite);
}

bool hast::Pawn::MakeSprite(std::string str){
	// Player Texture
	if (!m_texture.loadFromFile(str)) {
		std::cout << "Texture Not Found At: " << str << "\n";
		return false;
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(sf::Vector2f(1, 1));

	return true;
}

void hast::Pawn::SetSpriteSize(float x, float y){
	m_sprite.setScale(sf::Vector2f(x, y));
}

void hast::Pawn::SetSpriteLocation(float x, float y){
	m_sprite.setPosition(sf::Vector2f(x,y));
}


