#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;

void Exercise(sf::Event &event, bool *print_correct_letter,
              long unsigned int *current_letter, std::string lines[],
              std::string &utf88, int *current_string);
