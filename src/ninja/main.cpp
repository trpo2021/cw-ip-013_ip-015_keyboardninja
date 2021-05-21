#include <SFML/Graphics.hpp>
#include <libninja/readingfile.hpp>
#include <libninja/switcher.hpp>
#include <sstream>

using namespace sf;

int main() {
  setlocale(LC_ALL, "Russian");
  ///////
  int position[12];
  int menuNum = 1;
  bool ismenu = true;
  bool naj = false;
  ///////
  int count;
  string *lines = nullptr;
  count = GetStringsFromFileS("texts/rus.txt", &lines);
  if (count < 0) {
    std::cout << "Error" << std::endl;
    return 1;
  }
  sf::RenderWindow window(sf::VideoMode(1050, 660), "SFML works!");
  //////////////
  Texture menuBackground1;
  menuBackground1.loadFromFile("images/fon.jpg");
  Sprite menuBg1(menuBackground1);
  menuBg1.setPosition(0, 0);
  //////////////
  sf::Font font;
  if (!font.loadFromFile("fonts/19939.otf")) {
    std::cout << "ERROR" << std::endl;
  }
  //bool flag = false;
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

  while (ismenu)
  {
    sf::Event event;

    while (menuNum == 1)
    {
      while (window.pollEvent(event))
      {
        if (event.type == Event::Closed)
        {
          window.close();
          menuNum = 0;
          ismenu = false;
        }
      }
      window.draw(menuBg1);
      window.display();
      switcher(menuNum, position, 12);
      if (IntRect(position[0], position[1], position[2], position[3]).contains(Mouse::getPosition(window)))
      {

        if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj))
        {
          naj = true;
        }
        while (window.pollEvent(event))
        {
          if ((event.type == sf::Event::MouseButtonReleased) && (naj) && (event.mouseButton.button == Mouse::Left))

          {
            menuNum = 2;
            switcher(menuNum, position, 12);
            menuBackground1.loadFromFile("images/fon1.jpg");
            Sprite menuBg1(menuBackground1);
            menuBg1.setPosition(0, 0);
            naj = false;
            
          }
        }
      }

      if (IntRect(position[4], position[5], position[6], position[7]).contains(Mouse::getPosition(window)))
      {

        if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj))
        {
          naj = true;
        }
        while (window.pollEvent(event))
        {
          if ((event.type == sf::Event::MouseButtonReleased) && (naj) && (event.mouseButton.button == Mouse::Left))
          {

            menuNum = 3;
            switcher(menuNum, position, 12);
            menuBackground1.loadFromFile("images/fon2.jpg");
            Sprite menuBg1(menuBackground1);
            menuBg1.setPosition(0, 0);
            naj = false;
            
          }
        }
      }

      if (IntRect(position[8], position[9], position[10], position[11]).contains(Mouse::getPosition(window)))
      {

        if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj))
        {
          naj = true;
        }
        while (window.pollEvent(event))
        {
          if ((event.type == sf::Event::MouseButtonReleased) && (naj) && (event.mouseButton.button == Mouse::Left))
          {
            ismenu = false;
            menuNum = 0;
          }
        }
      }
    }
  }
    
    /*while (window.pollEvent(event)) {
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
  
    window.clear();
    if (flag == true)
      window.draw(RightLetter);
    window.draw(text);
    window.display();*/
  
  return 0;
}
