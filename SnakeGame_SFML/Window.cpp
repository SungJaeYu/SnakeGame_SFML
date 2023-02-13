#include "Window.h"

Window::Window(const std::string& l_title, const sf::Vector2u& l_size)
{
    Setup(l_title, l_size);
}

Window::~Window()
{
    Destroy();
}

void Window::BeginDraw()
{
    m_renderwindow.clear(sf::Color::Black);
}

void Window::EndDraw()
{
    m_renderwindow.display();
}

void Window::Update()
{
    sf::Event event;
    while (m_renderwindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_isDone = true;
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
            ToggleFullScreen();
        }
    }
}

bool Window::IsDone()
{
    return m_isDone;
}

bool Window::IsFullScreen()
{
    return m_isFullScreen;
}

sf::Vector2u Window::GetWindowSize()
{
    return m_windowSize;
}

void Window::ToggleFullScreen()
{
    m_isFullScreen = !m_isFullScreen;
    Destroy();
    Create();
}

void Window::Draw(sf::Drawable& l_drawble)
{
    m_renderwindow.draw(l_drawble);
}

sf::RenderWindow& Window::GetRenderWindow()
{
    return m_renderwindow;
}

void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullScreen = false;
    m_isDone = false;
    Create();
}

void Window::Destroy()
{
    m_renderwindow.close();
}

void Window::Create()
{
    auto style = (m_isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_renderwindow.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
}
