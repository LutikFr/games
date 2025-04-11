#include <SFML/Graphics.hpp>

class Entity
{
    public:
        void                set_velocity(sf::Vector2f velocity);
        void                set_velocity(float vx, float vy);
        sf::Vector2f        get_velocity() const;

    private:
        sf::Vector2f        m_velocity;
        const float         base_velocity = 10.f;
};

