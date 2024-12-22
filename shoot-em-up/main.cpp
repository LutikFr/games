#include <SFML/Graphics.hpp>

class Game
{
    //variables (я бы все это перенес в отдельный класс связанный с 
    //игроком)
    private:
        bool                m_is_moving_down = false;
        bool                m_is_moving_left = false;
        bool                m_is_moving_right = false;
        bool                m_is_moving_up = false;

        const sf::Time      time_per_frame = sf::seconds(1.f / 60.f);

    //initialization
    public:
                            Game();
        void                run();

    //event processing
    private:
        void                handle_player_input(sf::Keyboard::Key key, 
                                bool is_pressed);
        void                process_events();
        void                update(sf::Time delta_time);
        void                render();

    //rendering
    private:
        sf::RenderWindow    m_window;
        sf::Sprite          m_player;
        sf::Texture         m_texture;
};

Game::Game():
    m_window(sf::VideoMode(640, 480), "SFML Application"),
    m_player(),
    m_texture()
{
    if (!m_texture.loadFromFile("Media/Textures/eagle.jpg"))
    {
        // Handle loading error
    }
    m_player.setTexture(m_texture);
    m_player.setPosition(100.f, 100.f);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    while (m_window.isOpen())
    {
        time_since_last_update += clock.restart();
        while (time_since_last_update > time_per_frame)
        {
            time_since_last_update -= time_per_frame;
            process_events();
            update(time_per_frame);
        }
        render();
    }
}

void Game::process_events()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handle_player_input(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handle_player_input(event.key.code, false);
                break;
            case sf::Event::Closed:
                m_window.close();
                break;
        }
    }
}

void Game::handle_player_input(sf::Keyboard::Key key, 
    bool is_pressed)
{
    switch (key)
    {
        case sf::Keyboard::W:
            m_is_moving_up = is_pressed;
            break;
        case sf::Keyboard::S:
            m_is_moving_down = is_pressed;
            break;
        case sf::Keyboard::A:
            m_is_moving_left = is_pressed;
            break;
        case sf::Keyboard::D:
            m_is_moving_right = is_pressed;
            break;
    }
}

void Game::update(sf::Time delta_time)
{
    float player_speed = 100.f;
    sf::Vector2f movement (0.f, 0.f);
    if (m_is_moving_down)
    {
        movement.y += player_speed;
    }
    if (m_is_moving_left)
    {
        movement.x -= player_speed;
    }
    if (m_is_moving_right)
    {
        movement.x += player_speed;
    }
    if (m_is_moving_up)
    {
        movement.y -= player_speed;
    }
    m_player.move(movement * (float)delta_time.asSeconds());
}

void Game::render()
{
    m_window.clear();
    m_window.draw(m_player);
    m_window.display();
}

int main()
{
    Game game;
    game.run();
}
