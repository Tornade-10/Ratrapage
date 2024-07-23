#include "ui/View.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>

#include "tilemap/tile.h"

ViewPoint::ViewPoint()
{
    view_.setSize(700, 500);
    view_.setCenter(pos_);
}

bool ViewPoint::IsWithinBounds(sf::Vector2f newCenter)
{
    float halfViewWidth = view_.getSize().x / 2.0f;
    float halfViewHeight = view_.getSize().y / 2.0f;

    if (newCenter.x - halfViewWidth < 0 || newCenter.x + halfViewWidth > tile_map_.GetMapSize().x * tile_map_.GetTileSize().x ||
        newCenter.y - halfViewHeight < 0 || newCenter.y + halfViewHeight > tile_map_.GetMapSize().y * tile_map_.GetTileSize().y)
    {
        std::cout << "center " << newCenter.x << " : " << newCenter.y << std::endl;

        return false;
    }

	return true;
}

sf::Vector2f ViewPoint::ClampCenterToBounds(const sf::Vector2f& center)
{
    float halfViewWidth = view_.getSize().x / 2.0f;
    float halfViewHeight = view_.getSize().y / 2.0f;

    sf::Vector2f clampedCenter = center;

    // Clamp the X coordinate
    if (clampedCenter.x - halfViewWidth < 0)
    {
        clampedCenter.x = halfViewWidth;
    }
    else if (clampedCenter.x + halfViewWidth > tile_map_.GetMapSize().x * tile_map_.GetTileSize().x)
    {
        clampedCenter.x = tile_map_.GetMapSize().x * tile_map_.GetTileSize().x - halfViewWidth;
    }

    // Clamp the Y coordinate
    if (clampedCenter.y - halfViewHeight < 0)
    {
        clampedCenter.y = halfViewHeight;
    }
    else if (clampedCenter.y + halfViewHeight > tile_map_.GetMapSize().y * tile_map_.GetTileSize().y)
    {
        clampedCenter.y = tile_map_.GetMapSize().y * tile_map_.GetTileSize().y - halfViewHeight;
    }

    return clampedCenter;
}

void ViewPoint::Move(sf::Event event)
{
    sf::Vector2f center = view_.getCenter();

    if (event.type == sf::Event::KeyPressed) 
    {
        sf::Vector2f movement(0, 0);

        if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) 
        {
            movement.y = -8;  // Move view up
        }
        if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
        {
            movement.y = 8;   // Move view down
        }
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
        {
            movement.x = -8;  // Move view left
        }
        if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
        {
            movement.x = 8;   // Move view right
        }

        sf::Vector2f newCenter = view_.getCenter() + movement;

        if (IsWithinBounds(newCenter))
        {
            // Set the camera to the new pov
            view_.setCenter(newCenter);
            pos_ = newCenter;
        }
        else
        {
            // Keep the camera at the last position
            view_.setCenter(center);
            pos_ = center;
        }
    }
}

void ViewPoint::Zoom(sf::Event event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::MouseWheelScrolled)
    {
        // Get the current mouse position in window coordinates
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        // Convert it to world coordinates
        sf::Vector2f worldPos = pos_;

        camera_modification_ = false;

        if (event.mouseWheelScroll.delta > 0 && zoom_ > max_zoom_)
        {
            zoom_ *= 0.9f;  // Zoom in
            camera_modification_ = true;
        }

        if (event.mouseWheelScroll.delta < 0 && zoom_ < min_zoom_)
        {
            zoom_ *= 1.1f;  // Zoom out
            camera_modification_ = true;
        }

        // Calculate the new center of the view to zoom at the mouse position
        if (camera_modification_)
        {
            // Adjust the view size based on the new zoom level
            view_.setSize(800 * zoom_, 600 * zoom_);

            sf::Vector2f newCenter = worldPos + (view_.getCenter() - worldPos) * ((event.mouseWheelScroll.delta > 0) ? 0.9f : 1.1f);

            newCenter = ClampCenterToBounds(newCenter);

            view_.setCenter(newCenter);
            pos_ = newCenter;
        }
    }
}

void ViewPoint::MoveViewByMouse(sf::RenderWindow& window)
{
    sf::Vector2f center = view_.getCenter();

    // Get the current mouse position in window coordinates
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

    // Get the center of the window
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f windowCenter(windowSize.x / 2.0f, windowSize.y / 2.0f);

    // Calculate the distance from the mouse to the window center
    sf::Vector2f mouseDelta(pixelPos.x - windowCenter.x, pixelPos.y - windowCenter.y);

    // Check if the mouse is outside the dead zone
    if (abs(mouseDelta.x) > dead_zone_.x / 2.0f || abs(mouseDelta.y) > dead_zone_.y / 2.0f)
    {
        // Move the view center based on mouse movement outside the dead zone
        if (abs(mouseDelta.x) > dead_zone_.x / 2.0f) 
        {
            pos_.x += mouseDelta.x * camera_speed_.x;  // Speed value, Adjust the factor as needed
        }
        if (abs(mouseDelta.y) > dead_zone_.y / 2.0f) 
        {
            pos_.y += mouseDelta.y * camera_speed_.y;  // Speed value, Adjust the factor as needed
        }

        if (IsWithinBounds(pos_))
        {
            view_.setCenter(pos_);
        }
        else
        {
            view_.setCenter(center);
            pos_ = center;
        }
    }
}