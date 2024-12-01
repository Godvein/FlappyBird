#pragma once 
#include <SFML/Graphics.hpp>
class GameMath{

public:
static sf::Vector2f normalizeVector(sf::Vector2f vector);
static bool hasCollided(sf::FloatRect rect1, sf::FloatRect rect2);
};
