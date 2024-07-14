#include "Game.h"

#include <iostream>

#include "../GlobalStatistics/GlobalGameStatistics.h"

void Game::Initialize()
{
    this->videoMode = new sf::VideoMode(600, 600);
}

void Game::InitWindow()
{
    this->window = new sf::RenderWindow(
    *this->videoMode,
    "Model First game",
    sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(GlobalGameStatistics::GetFrameRateLimit());
}

void Game::InitCharacter()
{
    player = new sf::RectangleShape(sf::Vector2f(128.f, 128.f));
    player->setOutlineColor(sf::Color::Green);
    player->setOutlineThickness(10);
    playerTexture.loadFromFile("H:\\Games\\SMFTests\\CubieJump\\CubieJump\\SourceFiles\\Resources\\Sprites\\Idle.png");
    player->setTexture(&playerTexture);
    this->animation = new Animation(
        &playerTexture,
        AnimationType::InfiniteLoop,
        sf::Vector2u(5, 1),
        0.5f);
}

Game::Game() : GlobalGameStatistics(),
                animation(nullptr)
{
    this->Initialize();
    this->InitWindow();
    this->InitCharacter();
}

Game::~Game()
{
    delete this->window;
    delete this->videoMode;
}

void Game::Update()
{
    this->PollEvents();
    UpdatemousePosition();
}


/*
   Renders the gameObjects
    - display frames in window
 */
void Game::Render()
{
    animation->Update(0,GlobalGameStatistics::GetDeltaTime());
    player->setTextureRect(animation->uvRect);
    this->window->clear();
    this->window->draw(*this->player);
    this->window->display();
}

bool Game::Running() const
{
    return GetWindowIsOpen();
}

void Game::PollEvents()
{
    while(this->window->pollEvent(this->event))
    {
        switch (event.type)  // NOLINT(clang-diagnostic-switch-enum)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        default:
            break;
        }
    }
}

bool Game::GetWindowIsOpen() const
{
    return this->window->isOpen();
}

void Game::UpdatemousePosition()
{
    auto const xPosition = sf::Mouse::getPosition(*this->window).x;
    auto const yPosition = sf::Mouse::getPosition(*this->window).y ;

    if (xPosition >= 0 && xPosition <= this->videoMode->width &&
        yPosition >= 0 && yPosition <= this->videoMode->height )
    {
        mousePosition = sf::Vector2i(xPosition, yPosition);
        std::cout << "Mouse pos:" << mousePosition.x << " "
            << mousePosition.y << "\n";
    }
}
