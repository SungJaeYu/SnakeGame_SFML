#pragma once
#include "Window.h"
#include "World.h"
#include "Snake.h"

#define WINDOW_SIZE_W 800
#define WINDOW_SIZE_H 600

class Game
{
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();

    Window* GetWindow();
    sf::Time GetElapsed();
    void RestartClock();
private:
    Window m_window;
    World m_world;
    Snake m_snake;

    // Timer
    sf::Clock m_clock;
    sf::Time m_elapsed;
};

