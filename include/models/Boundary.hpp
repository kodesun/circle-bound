#pragma once

#include "DEFINITIONS.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

namespace satisfying_ball {
    class Boundary {
        public:
            Boundary();

            void Draw(sf::RenderWindow &window);

        private:
            double radius = WINDOW_WIDTH/2.0f;
            sf::CircleShape shape; 
    };
}
