#include "pipemanager.h"
#include "gamemath.h"
void PipeManager::initialize(){
timer = 0;
}
bool PipeManager::update(float delta_time, Bird bird, float& score){

timer += delta_time;
if(timer > 3000){

//using smart pointers because of how sfml handles textures
std::unique_ptr<Pipe> pipeup = std::make_unique<Pipe>();
std::unique_ptr<Pipe> pipedown = std::make_unique<Pipe>();
pipeup->initializeUp();
pipedown->initializeDown(pipeup->y);

pipes.push_back(std::move(pipeup));
pipes.push_back(std::move(pipedown));
timer = 0;
}

for(int i = 0; i< pipes.size(); i++){
//update pipe position
pipes[i]->update();

//check collision
if(GameMath::hasCollided(pipes[i]->sprite.getGlobalBounds(), bird.sprite.getGlobalBounds())){
pipes.clear();
return true;
}

//check if player passed pipe
if(pipes[i]->sprite.getGlobalBounds().left < 100){
score+=0.005;
}
//erase the pipe if out of window
if(pipes[i]->sprite.getPosition().x == 0){
pipes.erase(pipes.begin() + i);
i--;
}
}
return false;
}

void PipeManager::draw(sf::RenderWindow& window){
//iterate through pointers to draw pipe
for(auto& pipe: pipes){
pipe->draw(window);
}
}
