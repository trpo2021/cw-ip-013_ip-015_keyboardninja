#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace sf;

bool Keyhalding(sf::Event &event, int current_string,
                long unsigned int current_letter, std::string lines[]);

void Exercise(sf::Event &event, bool *print_correct_letter,
              long unsigned int *current_letter, std::string lines[],
              std::string &utf88, int *current_string, int *mistakes,
              int *queue, int count);
