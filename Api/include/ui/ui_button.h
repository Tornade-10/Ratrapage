
#ifndef API_UI_UIBUTTON_H_
#define API_UI_UIBUTTON_H_

#include <functional>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Event.hpp>

#include "graphics/ressource_manager.h"

//TODO : Fix the buttons and do the UI

class UiButton : public sf::Drawable, public sf::Transformable
{
private:
	sf::Font font_;
	sf::Text text_;

	sf::Sprite sprite_;
	sf::Sprite icon_;

	sf::Vector2f position_;



	bool ContainsMouse(const sf::Event& event);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:

	UiButton(sf::Vector2f position, sf::Vector2f size, sf::Color color_base, sf::Texture& icon, std::string text, sf::Texture& texture);

	void SetButtonPosition(sf::Vector2f position);
	sf::Vector2f GetButtonStartingPosition();

	void HandleEvent(const sf::Event& event);


	std::function<void()> callback_;
};

#endif // API_UI_UIBUTTON_H_
