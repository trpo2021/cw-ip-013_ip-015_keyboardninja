#include <libninja/exercise.hpp>

void Exercise(sf::Event &event, bool *print_correct_letter,
              long unsigned int *current_letter, std::string lines[],
              std::string &utf88, int *current_string) {
  if (event.type == sf::Event::TextEntered) {
    *print_correct_letter = true;
    std::cout << "Key Pressed " << event.key.code << "\n";
    if (*current_letter == lines[*current_string].size() - 1) {
      utf88.clear();
      lines[*current_string].clear();
      *current_letter = 0;
      (*current_string)++;
    }
    std::cout << 1;
    if ((char)event.key.code == lines[*current_string][*current_letter]) {
      utf88 = utf88 + (char)(event.key.code);
      (*current_letter)++;
    }
  }
}
