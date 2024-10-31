#pragma once

/**
 * AssetManager is a class in charge of saving assets
 * into memory and retrieving them. These assets are 
 * stored within maps, with the asset paired up to a 
 * 'name' key.
 */

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <map>
#include <string>

namespace satisfying_ball{
    class AssetManager {
        public:
            AssetManager(){}
            ~AssetManager(){}

            void LoadFont(std::string name, std::string filename);
            sf::Font &GetFont(std::string name);
            void LoadTexture(std::string name, std::string filename);
            sf::Texture &GetTexture(std::string name);
            void LoadSoundBuffer(std::string name, std::string filename);
            sf::SoundBuffer &GetSoundBuffer(std::string name);

        private:
            std::map<std::string, sf::Font> fonts;
            std::map<std::string, sf::Texture> textures;
            std::map<std::string, sf::SoundBuffer> sounds;
    };
} 
