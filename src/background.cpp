#include "background.h"
BackGround::BackGround(){


sprite.scale(4.f, 2.f);
}
void BackGround::initialize(){

if(texture.loadFromFile("../assets/background.png")){

//texture sprite
sprite.setTexture(texture);
}
}

void BackGround::draw(sf::RenderWindow& window){
window.draw(sprite);
}
