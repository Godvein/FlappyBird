#include "pipemanager.h"
void PipeManager::initialize(){
timer = 0;
}
void PipeManager::update(float delta_time){

timer += delta_time;
if(timer > 3000){
std::unique_ptr<Pipe> pipeup = std::make_unique<Pipe>();
std::unique_ptr<Pipe> pipedown = std::make_unique<Pipe>();
pipeup->initializeUp();
pipedown->initializeDown();

pipes.push_back(std::move(pipeup));
pipes.push_back(std::move(pipedown));
timer = 0;
}

for(int i = 0; i< pipes.size(); i++){
pipes[i]->update();
if(pipes[i]->sprite.getPosition().x == 0){

pipes.erase(pipes.begin() + i);
i--;
}
}
}

void PipeManager::draw(sf::RenderWindow& window){
for(auto& pipe: pipes){
pipe->draw(window);
}
}
