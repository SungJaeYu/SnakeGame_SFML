#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Game.h"

int main(int argc, char** argv[])
{
    Game game;
    sf::Clock clock;
    const float targetFrameTime = 1.0f / 30.0f;

    while (!game.GetWindow()->IsDone()) {
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();

        // Wait for remaining time to reach target frame time
        float remainingTime = targetFrameTime - clock.getElapsedTime().asSeconds();
        if (remainingTime > 0)
        {
            sf::sleep(sf::seconds(remainingTime));
        }
    }
    return 0;
}