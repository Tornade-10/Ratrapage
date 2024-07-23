#ifndef CURSOR_MANAGER_H
#define CURSOR_MANAGER_H
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Cursor.hpp>

#include "ressource_manager.h"

// TODO : Fix the cursor selector and creat macros to switch in between, add more cursors depending on the type of context (after the buttons and UI)

class CursorManager : public sf::Drawable
{
public:

	//TODO : create method draw

	//static void BasicCursor(sf::Window& window)
	//{
	//	const sf::Image image = ResourceManager::Get().GetCursorTexture(ResourceManager::ResourceCursor::ClassicCursor);
	//	sf::Cursor cursor;
	//	cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), sf::Vector2u(0, 0));

	//	window.setMouseCursor(cursor);

	//}

	//static void BuildingCursor(sf::Window& window)
	//{
	//	const sf::Image image = ResourceManager::Get().GetCursorTexture(ResourceManager::ResourceCursor::BuildingCursor);
	//	sf::Cursor cursor;
	//	cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), sf::Vector2u(0, 0));

	//	window.setMouseCursor(cursor);
	//}

protected:
	void Draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite cursorSprite_;
	sf::Sprite buildingCursorSprite_;

	sf::Cursor cursor_;
	sf::Cursor buildingCursor_;
};

#endif // CURSOR_MANAGER_H