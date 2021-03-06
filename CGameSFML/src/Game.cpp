#include "Game.hpp"


hast::Game::Game(){
	Run();
}


hast::Game::Game(const std::string winTittle, sf::Vector2u winSize):m_window(winTittle, winSize) {
	Run();
}


hast::Game::~Game(){
	std::cout << "Game Destroyed \n";

	delete player;
}


void hast::Game::Run() {
	// Initial.
	player = new hast::Player();
	player->MakeSprite("assets/textures/SpaceShips.png");
	player->CropSprite(8, 16 , 8, 8);
	player->SetSpriteSize(10.f, 10.f);
	player->SetSpriteLocation((m_window.GetWindowSize().x / 2.f), (m_window.GetWindowSize().y - 200.f));
	sf::Vector2u vec(m_window.GetWindowSize());
	//player->SetSpriteLocation(vec.x / 2, vec.y - 200);

	// Game Loop.
	while (!m_window.IsDone()) {
		GetFPS();

		HandleInput();
		Update();
		Render();
	}

}

/***************************************************************/
//Local Functions Here.
void hast::Game::GetFPS(){
	if (mClock.getElapsedTime().asSeconds() >= 1.f) {
		debug.Clear();
		mFps = mFrame;
		mFrame = 0;
		std::string s = std::to_string(mFps);
		std::cout << s + "\n";
		debug.Add(s);
		mClock.restart();
	}
	++mFrame;
}


hast::GameWindow* hast::Game::GetWindow() {
	return &m_window;
}
/***************************************************************/
/***************************************************************/
//Game Starts here.



// Input from player
void hast::Game::HandleInput(){
	sf::Event event;
	if (m_window.getWindow()->pollEvent(event)) {\
		// CloseWindow
		if (event.type == sf::Event::Closed) {
			m_window.EndWindow();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player->Move(hast::Direction::Left);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player->Move(hast::Direction::Right);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
		m_window.SetFPS(144);
	}


}

// Update function
void hast::Game::Update(){
	//window.Update();
	player->Update();
}

void hast::Game::Render(){
	m_window.BeginDraw();

	// Draw Here:
	player->Render(*m_window.getWindow());
	debug.Render(*m_window.getWindow());

	//

	m_window.EndDraw();
}



/***************************************************************/
