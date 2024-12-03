#include "pipe.h"
#include <random>
#include <iostream>
int Pipe::generateRandomInt(int low, int high) {
std::random_device rd; 
std::mt19937 gen(rd()); 
    
std::uniform_int_distribution<int> dist(low, high);

return dist(gen);
}

void Pipe::initializeUp(){

if(texture.loadFromFile("../assets/uppipe.png")){

sprite.setTexture(texture);
}
y = (float)generateRandomInt(-500, 0);
sprite.setPosition(sf::Vector2f(1000, y));
}

void Pipe::initializeDown(float pos_y){

if(texture.loadFromFile("../assets/downpipe.png")){

sprite.setTexture(texture);

}

sprite.scale(1.f, 2.f);
sprite.setPosition(sf::Vector2f(1000,pos_y + 750));


}

void Pipe::update(){

sprite.setPosition(sprite.getPosition() + sf::Vector2f(-1,0));

}

void Pipe::draw(sf::RenderWindow& window){

window.draw(sprite);
}
