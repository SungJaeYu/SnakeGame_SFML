#pragma once
#include "Snake.h"

#define WORLD_BLOCK_SIZE 16


class World
{
public:
    World(sf::Vector2u l_windSize);
    ~World() = default;

    int GetBlockSize();

    void RespawnApple();

    void Update(Snake& l_player);

    void Render(sf::RenderWindow& l_window);

private:
    sf::Vector2u m_windowSize;
    sf::Vector2i m_item;

    int m_blockSize;
    
    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];
};

