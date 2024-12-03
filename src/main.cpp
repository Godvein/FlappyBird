#include <SFML/Graphics.hpp>
#include "bird.h"
#include "background.h"
#include "pipemanager.h"
bool game_over = false;

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

//pipemanager
PipeManager pipemanager;
pipemanager.initialize();

//background
BackGround background;
background.initialize();

//ground
sf::RectangleShape ground(sf::Vector2f(1000.f, 200.f));
ground.setPosition(0,800);

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

//if space pressed on gameover screen
if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && game_over) {

game_over = false;
bird.initialize();
background.initialize();
pipemanager.initialize();
}
}
//gameloop
if (game_over) {
window.clear(sf::Color::Black); 
background.draw(window); 
bird.draw(window);
pipemanager.draw(window);

sf::Font font;
font.loadFromFile("../assets/ARIAL.TTF"); 
sf::Text gameOverText;
gameOverText.setFont(font);
gameOverText.setString("Game Over! Press Enter to Restart");
gameOverText.setCharacterSize(24);
gameOverText.setFillColor(sf::Color::White);
gameOverText.setPosition(250, 350);
window.draw(gameOverText);

window.display();  
continue;  
}
//if not game over
float delta_time = clock.restart().asMicroseconds()/1000;

if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space){
space_pressed = false;
}

game_over = bird.update(delta_time, ground);
pipemanager.update(delta_time);
if(space_pressed == false){
bird.flap(delta_time, space_pressed);
}
window.clear(sf::Color::Black);
background.draw(window);
pipemanager.draw(window);
bird.draw(window);
window.draw(ground);
window.display();
}

return 0;
}

