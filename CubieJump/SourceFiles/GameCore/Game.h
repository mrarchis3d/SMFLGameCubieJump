#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../GameObjects/Animation.h"
#include "../GlobalStatistics/GlobalGameStatistics.h"


/*
 * Class that acts as game engine.
 * Wrapper class.
 */
class Game : public GlobalGameStatistics
{
    sf::RenderWindow* window = nullptr;
    sf::VideoMode* videoMode = nullptr;
    sf::Event event;
    sf::RectangleShape* player;
    sf::Texture playerTexture;
    Animation* animation =nullptr;
    sf::Vector2i mousePosition = sf::Vector2i(0.f, 0.f);
    
public:
    void InitCharacter();
    Game();
    virtual ~Game();
    //Functions
    void Update();
    void Render();
    bool Running() const;
    void UpdateFPS(float fps) {
        SetFPS(fps);
    }
    void UpdateDeltaTime(float deltatime) {
        SetDeltaTime(deltatime);
    }

private:
    void PollEvents();
    bool GetWindowIsOpen() const;
    void Initialize();
    void InitWindow();
    void UpdatemousePosition();
};
