#include "GameTextBox.hpp"

hast::GameTextBox::GameTextBox(){
	Setup();
}

hast::GameTextBox::~GameTextBox(){
	messageContainer.clear();
}

void hast::GameTextBox::Render(sf::RenderWindow& renWin){

	std::string content;

	for (auto& itr : messageContainer) {
		content.append(itr + "\n");
	}
	if (content != "") {
		text.setString(content);
		renWin.draw(background);
		renWin.draw(text);
	}

}

void hast::GameTextBox::Clear(){
	messageContainer.clear();
}

void hast::GameTextBox::Setup(){
	
	if (!textFont.loadFromFile("assets/fonts/arial.ttf"))
		std::cout << "Font No Found \n";

	text.setFont(textFont);
	text.setString("");
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setPosition(sf::Vector2f(1, 1));

	background.setSize(sf::Vector2f(250, 100));
	background.setFillColor(sf::Color(255,255,255,255/2));
	background.setPosition(sf::Vector2f(1, 1));
}

void hast::GameTextBox::Add(std::string str){
	messageContainer.push_back(str);
}
