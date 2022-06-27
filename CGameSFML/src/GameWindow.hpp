#pragma once

#include <iostream> 
#include "SFML/Graphics.hpp"

namespace hast {
class GameWindow {
public:
	GameWindow();
	GameWindow(const std::string& l_title, const sf::Vector2u& l_size);
	~GameWindow();
	void BeginDraw(); // Clear the window.
	void EndDraw(); // Display the changes.
	void Update();
	bool IsDone();
	bool IsFullscreen();
	sf::Vector2u GetWindowSize();
	void ToggleFullscreen();
	void EndWindow();

	void Draw(sf::Drawable& l_drawable);
	void SetFPS(const int fps);

	sf::RenderWindow* getWindow();

private:
	void Setup(const std::string& l_title,const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u windowSize;
	std::string windowTitle;
	bool m_isDone;
	bool m_isfullscreen;
};

}