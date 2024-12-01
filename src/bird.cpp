#include "bird.h"
#include "gamemath.h"
#include <iostream>
Bird::Bird(){

jump_velocity = 8.f;
gravity_speed = 0.1f;
}

void Bird::initialize(){
//texture sprite
if(texture.loadFromFile("../assets/bird.png")){
sprite.setTexture(texture);
sprite.setPosition(100,500);
}

}

bool Bird::update(float delta_time, sf::RectangleShape ground){
//gravity logic
sf::Vector2f ground_direction = sf::Vector2f(100,900) - sprite.getPosition();
ground_direction = GameMath::normalizeVector(ground_direction);

sprite.setPosition(sprite.getPosition() + ground_direction * (gravity_speed * delta_time));

//check collision
if(GameMath::hasCollided(sprite.getGlobalBounds(), ground.getGlobalBounds())){
return true;
}
return false;
}

void Bird::flap(float delta_time, bool& space_pressed){

//control logic
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
sf::Vector2f sky_direction = sf::Vector2f(100,0) - sprite.getPosition();
sky_direction = GameMath::normalizeVector(sky_direction);
sprite.setPosition(sprite.getPosition() + sky_direction * (jump_velocity * delta_time));
space_pressed = true;
}
}

void Bird::draw(sf::RenderWindow& window){
window.draw(sprite);
}
