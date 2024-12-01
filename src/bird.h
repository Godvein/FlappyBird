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
bool update(float delta_time, sf::RectangleShape ground);
void flap(float delta_time, bool& space_pressed);
void draw(sf::RenderWindow& window);
};
