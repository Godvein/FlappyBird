#include <SFML/Graphics.hpp>
#include "bird.h"
#include "background.h"
#include "pipemanager.h"
#include <math.h>
bool game_over = false;

int main(){

//initialize window
const int window_width = 1000;
const int window_height = 800;
sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Flappy Bird");
sf::View view(sf::FloatRect(0, 0, window_width, window_height));
window.setView(view);


window.setFramerateLimit(144);

bool space_pressed = false;
//initialize GameObjects

//score
float float_score = 0;
int score = std::ceil(float_score);
sf::Text scoreText;
sf::Font scoreFont;
if(scoreFont.loadFromFile("../assets/ARIAL.TTF")){
scoreText.setFont(scoreFont);
}

scoreText.setString("score: " + std::to_string(score));

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
float_score = 0;
scoreText.setString("score :" + std::to_string(score));
bird.initialize();
background.initialize();
pipemanager.initialize();
}
}
// Update the view based on the current window size
sf::Vector2u windowSize = window.getSize();
sf::View view(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
window.setView(view);
//gameloop
if (game_over) {
window.clear(sf::Color::Black); 
background.draw(window); 
bird.draw(window);
window.draw(scoreText);

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

int score = std::ceil(float_score);

scoreText.setString("score :" + std::to_string(score));
float delta_time = clock.restart().asMicroseconds()/1000;

if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space){
space_pressed = false;
}

bool condition1 = bird.update(delta_time, ground);
bool condition2 = pipemanager.update(delta_time, bird, float_score);

game_over = condition1 || condition2;
if(space_pressed == false){
bird.flap(delta_time, space_pressed);
}
window.clear(sf::Color::Black);
background.draw(window);
pipemanager.draw(window);
bird.draw(window);
window.draw(ground);
window.draw(scoreText);
window.display();
}

return 0;
}

