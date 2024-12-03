#pragma once 
#include <SFML/Graphics.hpp>
#include "pipe.h"
#include <iostream>
#include <vector>
#include <memory>
class PipeManager{

private:

std::vector<std::unique_ptr<Pipe>> pipes;
float timer;
public:

void initialize();
void update(float delta_time);
void draw(sf::RenderWindow& window);

};

