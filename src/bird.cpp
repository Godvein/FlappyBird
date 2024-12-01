#include "bird.h"

Bird::Bird(){

jump_velocity = 0.2f;
gravity_speed = 0.1;
}

void Bird::initialize(){
//texture sprite
if(texture.loadFromFile("../assets/bird.png")){
sprite.setTexture(texture);
}

}

void Bird::update(){}

void Bird::flap(){}

void Bird::draw(sf::RenderWindow& window){
window.draw(sprite);
}
