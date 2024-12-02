#pragma once 
#include <SFML/Graphics.hpp>
class Pipe{

private:

sf::Texture texture;
sf::Sprite sprite;

public:
void initializeUp();
void initializeDown();
void update();
void draw(sf::RenderWindow& window);
};
