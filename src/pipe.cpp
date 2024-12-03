#include "pipe.h"
#include <cstdlib>
#include <iostream>
void Pipe::initializeUp(){

if(texture.loadFromFile("../assets/uppipe.png")){

sprite.setTexture(texture);
}

sprite.setPosition(sf::Vector2f(1000,0));
}

void Pipe::initializeDown(){

if(texture.loadFromFile("../assets/downpipe.png")){

sprite.setTexture(texture);

}
sprite.setPosition(sf::Vector2f(1000,480));



}

void Pipe::update(){

sprite.setPosition(sprite.getPosition() + sf::Vector2f(-1,0));

}

void Pipe::draw(sf::RenderWindow& window){

window.draw(sprite);
}
