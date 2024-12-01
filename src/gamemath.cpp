#include "gamemath.h"
#include <math.h>

sf::Vector2f GameMath::normalizeVector(sf::Vector2f vector){

float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);

sf::Vector2f normalized_vector;
normalized_vector.x = vector.x/magnitude;
normalized_vector.y = vector.y/magnitude;
return normalized_vector;

}

bool GameMath::hasCollided(sf::FloatRect rect1, sf::FloatRect rect2){
 
if(rect1.left + rect1.width > rect2.left &&
  rect2.left + rect2.width > rect1.left &&
  rect1.top + rect1.height  > rect2.top &&
  rect2.top + rect2.height > rect1.top){
return true;
}
return false;
}
