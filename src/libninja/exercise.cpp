#include <libninja/exercise.hpp>

bool Keyhalding(
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

void InvoiceProcessing(
        sf::Event& event,
        long unsigned int* current_letter,
        std::string lines[],
        std::string& utf88,
        int current_string,
        int* intseries,
        int* mistakes,
        int keycode)
{
    if (Keyhalding(current_string, keycode, *current_letter, lines)) {
        utf88 = utf88 + (char)(event.key.code);
        (*current_letter)++;
        (*intseries)++;
    } else {
        (*mistakes)++;
        (*intseries) = 0;
    }
}

void NextString(
        long unsigned int* current_letter,
        std::string lines[],
        std::string& utf88,
        int* current_string,
        int* queue,
        int count)
{
    if (*current_letter == lines[*current_string].size()) {
        utf88.clear();
        lines[*current_string].clear();
        *current_letter = 0;
        (*current_string)++;
        if (*queue < count) {
            (*queue)++;
        }
    }
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
        int count,
        int* intseries)
{
    int keycode = 0;
    if (event.type == sf::Event::TextEntered) {
        *print_correct_letter = true;
        std::cout << "Key Pressed " << event.key.code << "\n";
        keycode = event.key.code;
        InvoiceProcessing(
                event,
                current_letter,
                lines,
                utf88,
                *current_string,
                intseries,
                mistakes,
                keycode);
        NextString(current_letter, lines, utf88, current_string, queue, count);
    }
}
