#include "ui/ui_button.h"

#include "graphics/ressource_manager.h"

#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>

UiButton::UiButton(sf::Vector2f position, sf::Vector2f size, sf::Color color_base, sf::Texture& icon, std::string text, sf::Texture& texture)
{
	//font_ = ResourceManager::Get().GetTextFont(ResourceManager::RessourceFonts::kPixelated);

	// Set the position
	setPosition(position);
	position_ = position;

	// Set the textures
	sprite_.setScale(size);
	sprite_.setTexture(texture);
	sprite_.setOrigin(sprite_.getTexture()->getSize().x / 2.0f, sprite_.getTexture()->getSize().y / 2.0f);
	sprite_.setColor(color_base);

	icon_.setScale(sf::Vector2f(1.5f, 1.5f));
	icon_.setTexture(icon);

	sf::FloatRect iconBounds = icon_.getLocalBounds();
	icon_.setOrigin(iconBounds.left + iconBounds.width / 2.0f, iconBounds.top + iconBounds.height / 2.0f + +10.0f);

	// Create a text
	text_ = sf::Text(text, font_);
	text_.setFont(ResourceManager::Get().GetTextFont(ResourceManager::RessourceFonts::kPixelated));

	text_.setCharacterSize(16);
	text_.setFillColor(sf::Color::Black);
	//text_.setStyle(sf::Text::Bold);

	// Set the text at the bottom of the button
	sf::FloatRect textBounds = text_.getLocalBounds();
	text_.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f + -10.0f);
}

void UiButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprite_, states);
	target.draw(icon_, states);
	target.draw(text_, states);
}

bool UiButton::ContainsMouse(const sf::Event& event)
{
	// Get the position of the mouse click

	float mouseX = static_cast<float>(event.mouseButton.x) - getPosition().x;
	float mouseY = static_cast<float>(event.mouseButton.y) - getPosition().y;

	//sf::Mouse::getPosition()
	// // Check if the mouse click is inside the drawable shape
	if (sprite_.getGlobalBounds().contains(mouseX, mouseY))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UiButton::HandleEvent(const sf::Event& event)
{
	//std::cout << mouseX << " : " << mouseY << " ; " << sprite_.getGlobalBounds().getSize().x << " : " << sprite_.getGlobalBounds().getSize().y << std::endl;

	// Check for mouse button pressed event
	if (event.type == sf::Event::MouseButtonReleased) 
	{
		if (ContainsMouse(event))
		{
			// Check if the left mouse button is pressed
			if (event.mouseButton.button == sf::Mouse::Left) 
			{
				// Code � faire pour le bouton ---------------------------------------------------
				if (callback_) {
					std::cout << "CALL BACK TIME !" << std::endl;
					callback_();
				}
				else
				{
					std::cout << "No callback defined...";
				}
			}
		}
	}
}

void UiButton::SetButtonPosition(sf::Vector2f position)
{
	setPosition(position);
}

sf::Vector2f UiButton::GetButtonStartingPosition()
{
	return position_;
}