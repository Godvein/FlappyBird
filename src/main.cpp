#include <SFML/Graphics.hpp>
#include "bird.h"
#include "background.h"
int main(){

//initialize window
const int window_width = 1000;
const int window_height = 800;
sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Flappy Bird");

//initialize GameObjects
//background
BackGround background;
background.initialize();
//bird
Bird bird;
bird.initialize();
while(window.isOpen()){

sf::Event event;

while(window.pollEvent(event)){
//event loop
if(event.type == sf::Event::Closed){

window.close();
}

}
//gameloop
window.clear(sf::Color::Black);
background.draw(window);
bird.draw(window);
window.display();
}

return 0;
}
