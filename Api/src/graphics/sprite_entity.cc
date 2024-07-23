
#include <SFML/Graphics/RenderTarget.hpp>

#include "graphics/sprite_entity.h"
#include "graphics/ressource_manager.h"

SpriteEntity::SpriteEntity(float x, float y)
{
	shape_.setPosition(x, y);

	rect_.setOutlineColor(sf::Color::Magenta);
	rect_.setOutlineThickness(1);
	rect_.setFillColor(sf::Color(0, 0, 0, 0));

}

void SpriteEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape_, states);
	target.draw(rect_, states);
}
