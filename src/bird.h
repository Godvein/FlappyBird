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
void update(float delta_time);
void flap(float delta_time, bool& space_pressed);
void draw(sf::RenderWindow& window);
};
