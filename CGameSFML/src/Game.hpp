#pragma once

#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameWindow.hpp"
#include "GameTextBox.hpp"
#include "player.hpp"


namespace hast{
class Game{
public:
	Game();
	Game(const std::string winTittle, sf::Vector2u winSize);
	~Game();

	void HandleInput();
	void Update();
	void Render();
	hast::GameWindow* GetWindow();

	void Run();

private:
	hast::Player* player;

	// Window
	hast::GameWindow m_window;
	// Debug 
	hast::GameTextBox debug;

	// FPS
	void GetFPS();
	unsigned int mFrame;
	unsigned int mFps;
	sf::Clock mClock;

};
}
