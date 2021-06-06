#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

bool Keyhalding(
        int current_string,
        int keycode,
        long unsigned int current_letter,
        std::string lines[]);

void InvoiceProcessing(
        sf::Event& event,
        long unsigned int* current_letter,
        std::string lines[],
        std::string& string_by_user,
        std::string& mistake,
        int current_string,
        int* intseries,
        int* mistakes,
        int keycode);

void NextString(
        long unsigned int* current_letter,
        std::string lines[],
        std::string& string_by_user,
        int* current_string,
        int* queue,
        int count);

void Exercise(
        sf::Event& event,
        bool* print_correct_letter,
        long unsigned int* current_letter,
        std::string lines[],
        std::string& string_by_user,
        std::string& mistake,
        int* current_string,
        int* mistakes,
        int* queue,
        int count,
        int* intseries);
