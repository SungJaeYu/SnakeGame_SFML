#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Window
{

public:
    Window() = delete;
    Window(const std::string& l_title, const sf::Vector2u& l_size);
    ~Window();

    void BeginDraw(); // Clear the window
    void EndDraw(); // Display the Window

    void Update();

    bool IsDone();
    bool IsFullScreen();

    sf::Vector2u GetWindowSize();

    void ToggleFullScreen();

    void Draw(sf::Drawable& l_drawble);

    sf::RenderWindow& GetRenderWindow();
private:
    friend class Game;
    void Setup(const std::string& l_title, const sf::Vector2u& l_size);

    void Destroy();
    void Create();

    sf::RenderWindow m_renderwindow;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullScreen;
};

