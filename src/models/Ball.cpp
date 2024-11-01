#include "models/Ball.hpp"
#include "DEFINITIONS.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>


namespace satisfying_ball {
    Ball::Ball(){
        this->shape.setRadius(10.0f);
        this->shape.setPointCount(50);
        this->shape.setOrigin(this->shape.getRadius(), this->shape.getRadius());
        this->shape.setPosition(WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f);
        this->shape.setFillColor(sf::Color::Red);
    }

    void Ball::Draw(sf::RenderWindow &window){
        window.draw(this->shape);
    }
}
