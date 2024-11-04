#pragma once

// KEEP 16:9 Aspect Ratio
#define WINDOW_WIDTH 480 
#define WINDOW_HEIGHT 854 

#define GRAVITY_FACTOR -9.18f
#define DAMPING_FACTOR 0.95f
#define PI 3.14159f

#define BALL_RADIUS 100.0f
#define BALL_POINT_COUNT 50.0f
#define BALL_COLOR sf::Color::Blue

#define BOUNDARY_RADIUS (WINDOW_WIDTH/2.0f)-10.0f
#define BOUNDARY_POINT_COUNT 100.0f
#define BOUNDARY_OUTLINE_THICKNESS 3.0f
#define BOUNDARY_OUTLINE_COLOR sf::Color::White
#define BOUNDARY_FILL_COLOR sf::Color::Transparent
