#include "HUD.h"

void HUD::HUDInit(sf::RenderWindow& window)
{

	if(font_.loadFromFile("Data/pixelated.ttf"))
	{
		game_over_.setFont(font_);
		//game_over_.setOrigin(game_over_.getScale().x / 2, game_over_.getScale().y / 2);
		game_over_.setString("You ded");
		game_over_.setFillColor(sf::Color::White);
		game_over_.setOutlineThickness(10);
		game_over_.setOutlineColor(sf::Color::Black);
		game_over_.setCharacterSize(60);

		won_.setFont(font_);
		//game_over_.setOrigin(game_over_.getScale().x / 2, game_over_.getScale().y / 2);
		won_.setString("You won");
		won_.setFillColor(sf::Color::White);
		won_.setOutlineThickness(10);
		won_.setOutlineColor(sf::Color::Black);
		won_.setCharacterSize(60);

	}
}

void HUD::TextDrawGameOver(sf::RenderWindow& window)
{
	game_over_.setPosition((window.getSize().x / 2) - 100, (window.getSize().y / 2) - 100);
	game_over_.setString("You ded");
	window.draw(game_over_);
}

void HUD::TextDrawWon(sf::RenderWindow& window)
{
	won_.setPosition((window.getSize().x / 2) - 100, (window.getSize().y / 2) - 100);
	won_.setString("You ded");
	window.draw(won_);
}
