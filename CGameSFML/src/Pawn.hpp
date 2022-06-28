#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>


namespace hast{
class Pawn{
public:
	Pawn();
	~Pawn();
	
	virtual void Update();
	virtual void Render(sf::RenderWindow&);

	bool MakeSprite(std::string);

	void SetSpriteSize(float, float);
	void SetSpriteLocation(float, float);
	void CropSprite(int left, int top, int weight, int height);
private:
	sf::Clock m_clock;
	sf::Time m_time;

protected:
	float m_dealtaTime;

	sf::Texture* m_texture;
	sf::Sprite m_sprite;
};

}