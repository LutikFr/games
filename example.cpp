#include <SFML/Graphics.hpp>

int main() {
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Circle");

    // Создаем круг
    sf::CircleShape shape; // Радиус круга 50 пикселей
    shape.setRadius(40.f);
    shape.setFillColor(sf::Color::Cyan); // Устанавливаем цвет круга
    shape.setPosition(100.f, 100.f); // Устанавливаем позицию круга в центре окна

    // Основной цикл приложения
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Закрываем окно при нажатии на кнопку закрытия
        }

        window.clear(); // Очищаем окно
        window.draw(shape); // Рисуем круг
        window.display(); // Отображаем содержимое окна
    }

    return 0;
}
