#pragma once
#include <SFML/Graphics.hpp>

class BackGround{

private:
sf::Texture texture;
sf::Sprite sprite;

public:

void initialize();
void draw(sf::RenderWindow& window);
};
