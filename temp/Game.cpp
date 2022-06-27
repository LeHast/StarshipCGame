#include "Game.hpp"


hast::Game::Game() : gamewindow("Snake", sf::Vector2u(1200, 800)), snake(world.GetBlockSize()), world(sf::Vector2u(1200, 800)) {
	Run();
}


hast::Game::Game(const std::string winTittle, sf::Vector2u winSize): gamewindow("WinTittle", winSize),
snake(world.GetBlockSize()), world(winSize) {
	Run();
}


hast::Game::~Game(){
	//gamewindow->~GameWindow();
	std::cout << "Game Destroyed \n";
}


void hast::Game::Run(){
	textBox.Setup(5, 14, 350, sf::Vector2f(0, 0));
	textBox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));
	textBox.Add("Score: " + std::to_string(snake.GetScore()));

	while (!gamewindow.IsDone()) {
		HandleInput();
		Update();
		Render();
	}
}

void hast::Game::HandleInput(){
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.GetDirection() != Direction::Down){
		snake.SetDirection(Direction::Up);
		std::cout << "Up\n";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.GetDirection() != Direction::Up){
		snake.SetDirection(Direction::Down);
		std::cout << "Down\n";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.GetDirection() != Direction::Right){
		snake.SetDirection(Direction::Left);
		std::cout << "Left\n";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake.GetDirection() != Direction::Left){
		snake.SetDirection(Direction::Right);
		std::cout << "Right\n";
	}

}

void hast::Game::Update() {
	gamewindow.Update();

	float timestep = 1.0f / snake.GetSpeed();
	if (elapsed.asSeconds() >= timestep) {
		snake.Tick();
		world.Update(snake);
		elapsed -= sf::seconds(timestep);
		if (snake.HasLost()) {
			snake.Reset();
		}
	}

	RestartClock();
}

void hast::Game::Render(){
	gamewindow.BeginDraw();
	// Draw Here:
	world.Render(*gamewindow.GetWindow());
	textBox.Render(*gamewindow.GetWindow());
	snake.Render(*gamewindow.GetWindow());
	//
	gamewindow.EndDraw();
	RestartClock();
}

hast::GameWindow* hast::Game::GetWindow() {
	return &gamewindow;
}


