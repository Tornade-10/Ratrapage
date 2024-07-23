#include "game.h"

#include "gameplay/building_manager.h"

#ifdef TRACY_ENABLE
#include <tracy/Tracy.hpp>
#endif

// TODO : add a starting screen

void Game::InitUI()
{
    UiButton house_button(sf::Vector2f(window_.getSize().x - 180.0f, window_.getSize().y - 970.0f),
        sf::Vector2f(0.4f, 1.2f),
        sf::Color(128, 128, 128, 200),
        ResourceManager::Get().GetUiTexture(ResourceManager::ResourceUI::kHouseIcon),
        "House",
        ResourceManager::Get().GetUiTexture(ResourceManager::ResourceUI::kGreenFrame));
    house_button.setScale(sf::Vector2f(3.0f, 3.0f));
    house_button.callback_ = [this]
    {
    	std::cout << "Building Houses" << std::endl;

        if (building_manager_.GetActive())
        {
            building_manager_.SetActive(false);
        }
        else
        {
            building_manager_.SetActive(true);
            map_.ClickedTile = std::bind(&BuildingManager::AddHouse, &building_manager_, std::placeholders::_1);
        }
    };
    buttons_.push_back(house_button);

    UiButton sawmill_button(sf::Vector2f(window_.getSize().x - 180.0f, window_.getSize().y - 790.0f),
        sf::Vector2f(0.4f, 1.2f),
        sf::Color(128, 128, 128, 200),
        ResourceManager::Get().GetUiTexture(ResourceManager::ResourceUI::kSawmillIcon),
        "Sawmill",
        ResourceManager::Get().GetUiTexture(ResourceManager::ResourceUI::kGreenFrame));
    sawmill_button.setScale(sf::Vector2f(3.0f, 3.0f));
    sawmill_button.callback_ = [this]
    {
        std::cout << "Building sawmill" << std::endl;

        if (building_manager_.GetActive())
        {
            building_manager_.SetActive(false);
        }
        else
        {
            building_manager_.SetActive(true);
            map_.ClickedTile = std::bind(&BuildingManager::AddSawmill, &building_manager_, std::placeholders::_1);
        }
    };
    buttons_.push_back(sawmill_button);

    UiButton mine_button(sf::Vector2f(window_.getSize().x - 180.0f, window_.getSize().y - 610.0f),
        sf::Vector2f(0.4f, 1.2f),
        sf::Color(128, 128, 128, 200),
        ResourceManager::Get().GetUiTexture(ResourceManager::ResourceUI::kMineIcon),
        "Mine",
        ResourceManager::Get().GetUiTexture(ResourceManager::ResourceUI::kGreenFrame));
    mine_button.setScale(sf::Vector2f(3.0f, 3.0f));
    mine_button.callback_ = [this]
    {
        std::cout << "Building mines" << std::endl;

        if (building_manager_.GetActive())
        {
            building_manager_.SetActive(false);
        }
        else
        {
            building_manager_.SetActive(true);
            map_.ClickedTile = std::bind(&BuildingManager::AddMine , &building_manager_, std::placeholders::_1);
        }
    };
    buttons_.push_back(mine_button);

    UiButton storage_button(sf::Vector2f(window_.getSize().x - 180.0f, window_.getSize().y - 430.0f),
        sf::Vector2f(0.4f, 1.2f),
        sf::Color(128, 128, 128, 200),
        ResourceManager::Get().GetUiTexture(ResourceManager::ResourceUI::kStorageIcon),
        "Storage",
        ResourceManager::Get().GetUiTexture(ResourceManager::ResourceUI::kGreenFrame));
    storage_button.setScale(sf::Vector2f(3.0f, 3.0f));
    storage_button.callback_ = [this]
    {
        std::cout << "Building storage" << std::endl;

        if (building_manager_.GetActive())
        {
            building_manager_.SetActive(false);
        }
        else
        {
            building_manager_.SetActive(true);
            map_.ClickedTile = std::bind(&BuildingManager::AddStorage, &building_manager_, std::placeholders::_1);
        }
    };
	buttons_.push_back(storage_button);


}

void Game::Init()
{
#ifdef TRACY_ENABLE
    ZoneScoped;
#endif

    sf::Vector2i windowSize = sf::Vector2i(125, 75);

    // create the window
    window_.create(sf::VideoMode(map_.GetTileSize().x * windowSize.x, map_.GetTileSize().y * windowSize.y), "Funny game window");

    InitUI();

    map_.Generate();

    fix_view_ = window_.getDefaultView();
}

void Game::Loop()
{
    // run the program as long as the window is open
    while (window_.isOpen())
    {
        sf::Event event;

        // check all the window's events that were triggered since the last iteration of the loop
        while (window_.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window_.close();

            // Handle UI Events
            for (auto button : buttons_)
            {
                button.HandleEvent(event);
            }

            // Handle View Events
            // The zoom feature won't be used because it brakes the buttons
            view_point_.Zoom(event, window_);

            view_point_.Move(event);
        }

        // clear the window with black color
        window_.clear(sf::Color::Black);

        // Move the view depending on the position of the camera
        view_point_.MoveViewByMouse(window_);

        window_.setView(view_point_.view());
        // draw the tilemap here
        window_.draw(map_);

        clamped_center_ = view_point_.ClampCenterToBounds(view_point_.view().getCenter());

        window_.setView(fix_view_);
        // draw buttons here
        for (auto& button : buttons_) {
            //button.SetButtonPosition(button.GetButtonStartingPosition());
            window_.draw(button);
        }

        // end the current frame
        window_.display();
    }
}