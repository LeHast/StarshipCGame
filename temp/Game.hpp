#pragma once

#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameWindow.hpp"
#include "TextBox.hpp"

// Snake Game
#include "World.hpp"
#include "Snake.h"

namespace hast{
class Game{
public:
	Game();
	Game(const std::string winTittle, sf::Vector2u winSize);
	~Game();

	void HandleInput();
	void Update();
	void Render();
	void Run();

	hast::GameWindow* GetWindow();

	// Clock
	sf::Time GetElapsed() { return elapsed; };
	void RestartClock() { elapsed += clock.restart(); };


private:
	// GameEngine
	hast::GameWindow gamewindow;
	sf::Clock clock;
	sf::Time elapsed;
	hast::Textbox textBox;

	// Game
	World world;
	Snake snake;

};
}
