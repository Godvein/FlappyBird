#pragma once
#include <SFML/Graphics.hpp>
class Bird{

private:
float jump_velocity;
float gravity_speed;
sf::Texture texture;
sf::Sprite sprite;

public:
Bird();
void initialize();
void update();
void flap();
void draw(sf::RenderWindow& window);
};
