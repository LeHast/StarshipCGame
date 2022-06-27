#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "SFML/Graphics.hpp"

using MessageContainer = std::vector<std::string>;

namespace hast{
class GameTextBox{
public:
	GameTextBox();
	~GameTextBox();

	void Setup();
	void Add(std::string);
	void Render(sf::RenderWindow& renWin);
	void Clear();
private:

	MessageContainer messageContainer;
	sf::RectangleShape background;
	sf::Font textFont;
	sf::Text text;

};
}

