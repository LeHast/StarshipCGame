#include "Pawn.hpp"

hast::Pawn::Pawn(){
	m_texture = new sf::Texture;
}

hast::Pawn::~Pawn(){
	delete m_texture;
}

void hast::Pawn::Update(){
	m_time = m_clock.restart();
	m_dealtaTime = m_time.asSeconds();
}

void hast::Pawn::Render(sf::RenderWindow& m_window){
	m_window.draw(m_sprite);
}

bool hast::Pawn::MakeSprite(std::string str){
	// Player Texture
	if (!m_texture->loadFromFile(str)) {
		std::cout << "Texture Not Found At: " << str << "\n";
		return false;
	}
	m_sprite.setTexture(*m_texture);
	m_sprite.setPosition(sf::Vector2f(1, 1));

	return true;
}

void hast::Pawn::SetSpriteSize(float x, float y){
	m_sprite.setScale(sf::Vector2f(x, y));
}

void hast::Pawn::SetSpriteLocation(float x, float y){
	m_sprite.setPosition(sf::Vector2f(x,y));
}

void hast::Pawn::CropSprite(int left, int top, int weight, int height){
	m_sprite.setTextureRect(sf::IntRect(left, top, weight, height));
}


