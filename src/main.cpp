#include <SFML/Graphics.hpp>
#include "bird.h"
#include "background.h"
int main(){

//initialize window
const int window_width = 1000;
const int window_height = 800;
sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Flappy Bird");

window.setFramerateLimit(144);

bool space_pressed = false;
//initialize GameObjects
//Clock
sf::Clock clock;

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
float delta_time = clock.restart().asMicroseconds()/1000;

if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space){
space_pressed = false;
}

bird.update(delta_time);
if(space_pressed == false){
bird.flap(delta_time, space_pressed);
}
window.clear(sf::Color::Black);
background.draw(window);
bird.draw(window);
window.display();
}

return 0;
}
