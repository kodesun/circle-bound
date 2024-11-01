#pragma once

#include "models/Border.hpp"
#include "models/Ball.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/System/Clock.hpp>

#include <string>

namespace satisfying_ball {
    class Game {
        public:
            Game(int width, int height, std::string title);
            void Run();

        private:
            const float dt = 1.0f/60.0f;
            std::string title;
            sf::RenderWindow window;
            sf::Clock clock;
            sf::Font font;

            Border border;
            Ball ball;
            
            bool paused = false;

            void HandleInput();
            void Update();
            void Draw(float dt);
    };
}
