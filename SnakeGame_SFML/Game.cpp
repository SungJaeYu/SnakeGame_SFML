#include "Game.h"

Game::Game()
    : m_window("Snake Game", sf::Vector2u(WINDOW_SIZE_W, WINDOW_SIZE_H)),
    m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(WINDOW_SIZE_W, WINDOW_SIZE_H))
{

}

Game::~Game()
{
}

void Game::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetDirection() != Direction::Down) {
        m_snake.SetDirection(Direction::Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetDirection() != Direction::Up) {
        m_snake.SetDirection(Direction::Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetDirection() != Direction::Right) {
        m_snake.SetDirection(Direction::Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetDirection() != Direction::Left) {
        m_snake.SetDirection(Direction::Right);
    }
}

void Game::Update()
{
    m_window.Update();

    float timestep = 1.0f / m_snake.GetSpeed();

    float currentTime = m_elapsed.asSeconds();

    if (currentTime >= timestep) {
        m_snake.Tick();
        m_world.Update(m_snake);
        currentTime -= timestep;
        m_elapsed = sf::seconds(currentTime);
        if (m_snake.HasLost()) {
            m_snake.Reset();
        }
    }
}

void Game::Render()
{
    m_window.BeginDraw();
    // TODO: Draw
    m_world.Render(m_window.m_renderwindow);
    m_snake.Render(m_window.m_renderwindow);

    m_window.EndDraw();
}

Window* Game::GetWindow()
{
    return &m_window;
}

sf::Time Game::GetElapsed()
{
    return m_elapsed;
}

void Game::RestartClock()
{
    m_elapsed = m_clock.restart();
}
