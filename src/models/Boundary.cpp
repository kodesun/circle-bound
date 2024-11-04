#include "models/Boundary.hpp"
#include "DEFINITIONS.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace satisfying_ball{
    Boundary::Boundary(){
        shape.setRadius(BOUNDARY_RADIUS);
        shape.setPointCount(BOUNDARY_POINT_COUNT);
        shape.setOrigin(shape.getRadius(), shape.getRadius());
        shape.setPosition(WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f);
        shape.setOutlineThickness(BOUNDARY_OUTLINE_THICKNESS);
        shape.setOutlineColor(BOUNDARY_OUTLINE_COLOR);
        shape.setFillColor(BOUNDARY_FILL_COLOR);
    }

    void Boundary::Draw(sf::RenderWindow &window){
        window.draw(shape);
    }
}
