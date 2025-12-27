#include <memory>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Bouncin");
    sf::FloatRect windowBounds({ 0.f, 0.f}, window.getDefaultView().getSize()) ;
    ImGui::SFML::Init(window);

    // Placeholder shape 1
    sf::CircleShape circle(100.f);
    circle.setPosition({ 100.f, 500.f });
    circle.setFillColor(sf::Color::Green);
    
    // Circle Shape Text
    const sf::Font font1("fonts/Micro5-Regular.ttf");

    sf::Text text1(font1, "Circle");
    text1.setCharacterSize(30);
    text1.setStyle(sf::Text::Regular);
    text1.setFillColor(sf::Color::Black);
    sf::FloatRect textBounds1 = text1.getGlobalBounds();

    // Placeholder shape 2
    sf::RectangleShape rect({ 100.f, 100.f });
    rect.setPosition({ 200.f, 100.f });
    rect.setFillColor(sf::Color::Blue);

    // Rectangle Shape Text
    const sf::Font font2("fonts/MountainsofChristmas-Regular.ttf");

    sf::Text text2(font2, "Rect");
    text2.setCharacterSize(30);
    text2.setStyle(sf::Text::Regular);
    text2.setFillColor(sf::Color::White);
    sf::FloatRect textBounds2 = text2.getGlobalBounds();

    // Velocity
    sf::Vector2f velocityCircle = { 0.1f, 0.1f };
    sf::Vector2f velocityRectangle = { 0.5f, 0.5f };

    sf::Clock deltaClock;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);

            if (event->is<sf::Event::Closed>())
                window.close();
        }
        // Circle Movement
        circle.move(velocityCircle);
        sf::Vector2f positionCircle = circle.getPosition();
        float diameter = circle.getRadius() * 2;

        if (positionCircle.x <= 0 || positionCircle.x + diameter >= windowBounds.size.x)
        {
            velocityCircle.x = -velocityCircle.x;
        };

        if (positionCircle.y <= 0 || positionCircle.y + diameter >= windowBounds.size.y)
        {
            velocityCircle.y = -velocityCircle.y;
        };

        sf::Vector2f textpos1(positionCircle.x + circle.getRadius() - textBounds1.size.x / 2.f , positionCircle.y + circle.getRadius() - textBounds1.size.y / 2.f);
        text1.setPosition(textpos1);

        // Rectangle Movement
        rect.move(velocityRectangle);
        sf::Vector2f positionRect = rect.getPosition();
        sf::Vector2f size = rect.getSize();

        if (positionRect.x <= 0 || positionRect.x + size.x >= windowBounds.size.x)
        {
            velocityRectangle.x = -velocityRectangle.x;
        };

        if (positionRect.y <= 0 || positionRect.y + size.y >= windowBounds.size.y)
        {
            velocityRectangle.y = -velocityRectangle.y;
        };

        sf::Vector2f textpos2(positionRect.x + (size.x / 2.f) - (textBounds2.size.x / 2.f), positionRect.y + (size.y / 2.f) - (textBounds2.size.y / 2.f));
        text2.setPosition(textpos2);

        ImGui::SFML::Update(window, deltaClock.restart());

        window.clear();
        window.draw(circle);
        window.draw(text1);
        window.draw(rect);
        window.draw(text2);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}