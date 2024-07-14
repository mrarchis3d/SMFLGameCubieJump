#include <iostream>

#include "GameCore/Game.h"
#include "GlobalStatistics/GlobalGameStatistics.h"

using namespace sf;

int main()
{
    Game game;
    float deltatime;
    sf::Clock clock;
    while (game.Running()) {
        deltatime = clock.restart().asSeconds();
        game.Update();
        game.Render();
        game.UpdateDeltaTime(deltatime);
    }

    return 0;
}
