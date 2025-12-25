#include <memory>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
    ImGui::SFML::Init(window);  // ImGui-SFML

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock deltaClock;  // ImGui delta time

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);  // ImGui Events

            if (event->is<sf::Event::Closed>())
                window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());  // Update ImGui

        window.clear();
        window.draw(shape);
        ImGui::SFML::Render(window);  // Render ImGui
        window.display();
    }

    ImGui::SFML::Shutdown();  // Cleanup
}