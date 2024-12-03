#pragma once 
#include <SFML/Graphics.hpp>
class Pipe{

private:

sf::Texture texture;
public:
sf::Sprite sprite;
float y= 0;

public:
int generateRandomInt(int low, int high);
void initializeUp();
void initializeDown(float pos_y);
void update();
void draw(sf::RenderWindow& window);
};
