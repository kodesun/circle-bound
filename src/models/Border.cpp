#include "models/Border.hpp"
#include "DEFINITIONS.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace satisfying_ball{
    Border::Border(){
        shape.setRadius(this->radius-10.0f);
        shape.setPointCount(50);
        shape.setOrigin(shape.getRadius(), shape.getRadius());
        shape.setPosition(WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f);
        shape.setOutlineThickness(3.0f);
        shape.setOutlineColor(sf::Color::White);
        shape.setFillColor(sf::Color::Transparent);
    }

    void Border::Draw(sf::RenderWindow &window){
        window.draw(shape);
    }
}
