#ifndef DRAW_SPRITE_H
#define DRAW_SPRITE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "ressource_manager.h"

class DrawSprite : public sf::Drawable
{
public:
	DrawSprite(float x, float y);

protected:
	sf::Sprite shape_;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//virtual DefineTexture(ResourceManager::Texture texture) override;
	
};
#endif // DRAW_SPRITE_H
