#pragma once 
#include <SFML/Graphics.hpp>
#include "pipe.h"
#include <iostream>
#include <vector>
#include <memory>
#include "bird.h"
class PipeManager{

private:

std::vector<std::unique_ptr<Pipe>> pipes;
float timer;
public:

void initialize();
bool update(float delta_time, Bird bird, float& score);
void draw(sf::RenderWindow& window);

};

