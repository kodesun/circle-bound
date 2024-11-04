#include "models/Ball.hpp"
#include "DEFINITIONS.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>


namespace satisfying_ball {
    Ball::Ball(){
        this->shape.setRadius(BALL_RADIUS);
        this->shape.setPointCount(BALL_POINT_COUNT);
        this->shape.setOrigin(BALL_RADIUS, BALL_RADIUS);
        this->shape.setPosition(WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f);
        this->shape.setFillColor(BALL_COLOR);
    }

    void Ball::Update(float dt){
        this->shape.move(this->velocity);
        this->velocity.y = this->velocity.y - GRAVITY_FACTOR * dt;
        this->HandleCollisions();
    }

    void Ball::Draw(sf::RenderWindow &window){
        window.draw(this->shape);
    }

    void Ball::HandleCollisions() {
        sf::Vector2f position = this->shape.getPosition();
        sf::Vector2f center(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);

        float dist = std::sqrt(
            std::pow(position.x - center.x, 2) + 
            std::pow(position.y - center.y, 2)
        );

        if (dist + BALL_RADIUS >= BOUNDARY_RADIUS - BOUNDARY_OUTLINE_THICKNESS) {
            sf::Vector2f normal = position - center;
            normal /= dist;

            float overlap = (dist + BALL_RADIUS) - (BOUNDARY_RADIUS - BOUNDARY_OUTLINE_THICKNESS);
            this->shape.setPosition(position - normal * overlap);

            this->velocity = this->velocity - 2.0f * (this->velocity.x * normal.x + this->velocity.y * normal.y) * normal;
            this->velocity *= 1.01f;
        }
    }
}
