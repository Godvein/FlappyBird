#include "background.h"

void BackGround::initialize(){

if(texture.loadFromFile("../assets/background.png")){

//texture sprite
sprite.setTexture(texture);
sprite.scale(4.f, 2.f);
}
}

void BackGround::draw(sf::RenderWindow& window){
window.draw(sprite);
}
