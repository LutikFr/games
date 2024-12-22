#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Event event; // Создаем объект события

    while (window.isOpen())
    {
        while (window.pollEvent(event)) // Передаем объект события в pollEvent
        {
            if (event.type == sf::Event::Closed) // Проверяем тип события
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
