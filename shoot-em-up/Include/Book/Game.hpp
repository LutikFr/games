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
