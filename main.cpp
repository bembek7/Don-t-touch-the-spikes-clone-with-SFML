#include "Game.hpp"

int main()
{
    std::vector<sf::Texture> playerTextures;
    for(unsigned int i = 1; i <= 8; i++)
    {
        std::string filename;
        filename = "BirdTex/Bird" + std::to_string(i) + ".png";
        sf::Texture tex = sf::Texture();
        tex.loadFromFile(filename);
        playerTextures.push_back(tex);
    }
    Game game(400, 600, playerTextures, "Spike.png");
    game.Play();
    return 0;
}