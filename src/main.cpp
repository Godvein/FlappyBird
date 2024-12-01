#include <SFML/Graphics.hpp>

int main(){
const int window_width = 1000;
const int window_height = 800;
sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Flappy Bird");

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
window.display();
}

return 0;
}
