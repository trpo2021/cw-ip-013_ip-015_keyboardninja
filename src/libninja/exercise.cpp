#include <libninja/exercise.hpp>

bool Keyhalding(
        sf::Event& event,
        int current_string,
        int keycode,
        long unsigned int current_letter,
        std::string lines[])
{
    if ((char)keycode == lines[current_string][current_letter]) {
        return true;
    }
    return false;
}

void Exercise(
        sf::Event& event,
        bool* print_correct_letter,
        long unsigned int* current_letter,
        std::string lines[],
        std::string& utf88,
        int* current_string,
        int* mistakes,
        int* queue,
        int count)
{
    int keycode;
    if (event.type == sf::Event::TextEntered) {
        *print_correct_letter = true;
        std::cout << "Key Pressed " << event.key.code << "\n";
        keycode = event.key.code;
        if (*current_letter == lines[*current_string].size() - 1) {
            utf88.clear();
            lines[*current_string].clear();
            *current_letter = 0;
            (*current_string)++;
            if (*queue < count) {
                (*queue)++;
                (*mistakes)--;
            }
        }
        if (Keyhalding(
                    event, *current_string, keycode, *current_letter, lines)) {
            utf88 = utf88 + (char)(event.key.code);
            (*current_letter)++;
        } else {
            (*mistakes)++;
        }
    }
}
