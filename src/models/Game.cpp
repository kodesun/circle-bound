#include "models/Game.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

#include <SFML/Window/WindowStyle.hpp>
#include <string>

namespace satisfying_ball{
    Game::Game(int width, int height, std::string title){
        this->window.create(
                sf::VideoMode(width, height),
                title, 
                sf::Style::Close
            );
    }

    void Game::Run(){
        float new_time, frame_time, interpolation;
        float current_time = this->clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while(this->window.isOpen()){
            new_time = this->clock.getElapsedTime().asSeconds();
            frame_time = new_time - current_time;
            frame_time = frame_time > 0.25f ? 0.25f : frame_time;

            current_time = new_time;
            if(!this->paused) accumulator += frame_time;

            this->HandleInput();
            while(accumulator >= this->dt && !this->paused){
                this->Update();
                accumulator -= this->dt;
            }
            
            interpolation = accumulator/this->dt;
            this->Draw(interpolation);
        }
    }

    void Game::HandleInput(){
        sf::Event event;
        
        while(this->window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    this->window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Q:
                            this->window.close();
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
        }
    }

    void Game::Update(){

    }

    void Game::Draw(float dt){
        this->window.clear();
        this->boundary.Draw(this->window);
        this->ball.Draw(this->window);
        this->window.display();
    }
}
