#include "GameWindow.hpp"

hast::GameWindow::GameWindow(){
	Setup("Window", sf::Vector2u(1640, 880));
}


hast::GameWindow::GameWindow(const std::string& winTittle, const sf::Vector2u& winSize){
	Setup(winTittle, winSize);
}


hast::GameWindow::~GameWindow(){
	std::cout << "GameWindow Destroyed \n";
	Destroy();
}


void hast::GameWindow::BeginDraw(){
	m_window.clear(sf::Color::Black);
}


void hast::GameWindow::EndDraw(){
	m_window.display();
}


void hast::GameWindow::Update(){
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_isDone = true;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
			ToggleFullscreen();
		
	}
}


bool hast::GameWindow::IsDone(){
	return m_isDone;
}


bool hast::GameWindow::IsFullscreen(){
	return m_isfullscreen;
}


sf::Vector2u hast::GameWindow::GetWindowSize(){
	return windowSize;
}


void hast::GameWindow::ToggleFullscreen(){
	m_isfullscreen = !m_isfullscreen;
	Destroy();
	Create();
}

void hast::GameWindow::EndWindow(){
	m_isDone = true;
}


void hast::GameWindow::Draw(sf::Drawable& toDraw){
	m_window.draw(toDraw);
}

void hast::GameWindow::SetFPS(const int fps){
	m_window.setFramerateLimit(fps);
}

sf::RenderWindow* hast::GameWindow::getWindow(){
	return &m_window;
}


void hast::GameWindow::Setup(const std::string& winTittle, const sf::Vector2u& winSize){
	windowTitle = winTittle;
	windowSize = winSize;
	m_isfullscreen = false;
	m_isDone = false;
	Create();
}


void hast::GameWindow::Destroy(){
	m_window.close();
}


void hast::GameWindow::Create() {
	auto fullScreen = (m_isfullscreen ? sf::Style::Fullscreen : sf::Style::Default);

	m_window.create({windowSize.x, windowSize.y, 32}, windowTitle, fullScreen);
	m_window.setFramerateLimit(60);
}
