#include <SFML/Graphics.hpp>
#include <libninja/readingfile.hpp>
#include <sstream>

int main() {
  setlocale(LC_ALL, "Russian");
  int count;
  string *lines = nullptr;
  count = GetStringsFromFileS("texts/rus.txt", &lines);
  if (count < 0) {
    std::cout << "Error" << std::endl;
    return 1;
  }
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
  sf::Font font;
  if (!font.loadFromFile("fonts/19939.otf")) {
    std::cout << "ERROR" << std::endl;
  }
  bool flag = false;
  sf::Text text;
  std::string utf8 = lines[0];
  text.setFont(font);
  text.setString(sf::String::fromUtf8(utf8.begin(), utf8.end()));
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::Green);
  text.setStyle(sf::Text::Bold);
  text.setPosition(100, 200);

  sf::Text RightLetter;
  std::string utf88 = "49";
  RightLetter.setString(sf::String::fromUtf8(utf88.begin(), utf88.end()));
  RightLetter.setFont(font);
  RightLetter.setCharacterSize(24);
  RightLetter.setFillColor(sf::Color::Green);
  RightLetter.setStyle(sf::Text::Bold);
  RightLetter.setPosition(100, 300);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Key::Escape)
          window.close();
      }
      if (event.type == sf::Event::KeyPressed) {
        std::cout << "Key Pressed " << event.key.code << "\n";
        flag = true;
      }
    }
    window.clear();
    if (flag == true)
      window.draw(RightLetter);
    window.draw(text);
    window.display();
  }
  return 0;
}
