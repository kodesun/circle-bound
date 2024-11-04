#pragma once

#include "DEFINITIONS.hpp"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>


namespace satisfying_ball {
    class Ball {
    public:
        Ball();

        void Update(float dt);
        void Draw(sf::RenderWindow &window);

    private:
        sf::Vector2f velocity = sf::Vector2f(4.0f, 0.0f);

        sf::CircleShape shape;

        void HandleCollisions();
    };
}
