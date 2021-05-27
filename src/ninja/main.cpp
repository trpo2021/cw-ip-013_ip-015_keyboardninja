#include <SFML/Graphics.hpp>
#include <libninja/exercise.hpp>
#include <libninja/readingfile.hpp>
#include <libninja/switcher.hpp>
#include <sstream>

using namespace sf;
void timer(int lvl, double &curtime);
void gameloop(int lvl);
double curtime = 0; 
int main() {
  setlocale(LC_ALL, "Russian");
  ///////
  int position[12];
  int menuNum = 1;
  bool ismenu = true;
  bool naj = false;
  ///////
  int count;
  long unsigned int current_letter = 0;
  int current_string = 0;
  int strings_to_print = 0;
  string *lines = nullptr;
  count = GetStringsFromFileS("texts/eng.txt", &lines);
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
  bool print_correct_letter = false;
  sf::Text text;
  std::string utf8 = lines[0];
  text.setFont(font);
  text.setString(sf::String::fromUtf8(utf8.begin(), utf8.end()));
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::Green);
  text.setStyle(sf::Text::Bold);
  text.setPosition(100, 200);
  sf::Text RightLetter;
  std::string utf88;
  RightLetter.setFont(font);
  RightLetter.setCharacterSize(24);
  RightLetter.setFillColor(sf::Color::Black);
  RightLetter.setStyle(sf::Text::Bold);
  RightLetter.setPosition(200, 500);
  while (ismenu) {
    sf::Event event;
    print_correct_letter = false;
    utf88.clear();
    current_letter = 0;
    while (menuNum == 1) {
      while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
          window.close();
          menuNum = 0;
          ismenu = false;
        }
      }
      window.draw(menuBg1);
      window.display();
      switcher(menuNum, position, 12);
      if (IntRect(position[0], position[1], position[2], position[3])
              .contains(Mouse::getPosition(window))) {
        if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj)) {
          naj = true;
        }
        while (window.pollEvent(event)) {
          if ((event.type == sf::Event::MouseButtonReleased) && (naj) &&
              (event.mouseButton.button == Mouse::Left)) {
            menuNum = 2;
            switcher(menuNum, position, 12);
            menuBackground1.loadFromFile("images/fon1.jpg");
            Sprite menuBg1(menuBackground1);
            menuBg1.setPosition(0, 0);
            naj = false;
          }
        }
      }
      if (IntRect(position[4], position[5], position[6], position[7])
              .contains(Mouse::getPosition(window))) {
        if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj)) {
          naj = true;
        }
        while (window.pollEvent(event)) {
          if ((event.type == sf::Event::MouseButtonReleased) && (naj) &&
              (event.mouseButton.button == Mouse::Left)) {
            menuNum = 3;
            switcher(menuNum, position, 12);
            menuBackground1.loadFromFile("images/fon2.jpg");
            Sprite menuBg1(menuBackground1);
            menuBg1.setPosition(0, 0);
            naj = false;
          }
        }
      }
      if (IntRect(position[8], position[9], position[10], position[11])
              .contains(Mouse::getPosition(window))) {

        if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj)) {
          naj = true;
        }
        while (window.pollEvent(event)) {
          if ((event.type == sf::Event::MouseButtonReleased) && (naj) &&
              (event.mouseButton.button == Mouse::Left)) {
            ismenu = false;
            menuNum = 0;
          }
        }
      }
    }
    while (menuNum == 2) {
      while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
          window.close();
          menuNum = 0;
          ismenu = false;
        }
      }
      window.draw(menuBg1);
      window.display();
      if (IntRect(position[0], position[1], position[2], position[3])
              .contains(Mouse::getPosition(window))) {
        if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj)) {
          naj = true;
        }
        while (window.pollEvent(event)) {
          if ((event.type == sf::Event::MouseButtonReleased) && (naj) &&
              (event.mouseButton.button == Mouse::Left)) {
            menuNum = 4;
            window.clear();
            menuBackground1.loadFromFile("images/fon3.jpg");
            Sprite menuBg1(menuBackground1);
            menuBg1.setPosition(0, 0);
            switcher(menuNum, position, 12);
            if (print_correct_letter == true)
              window.draw(RightLetter);
            window.draw(text);
            window.display();

            naj = false;
          }
        }
      }
      if (IntRect(position[4], position[5], position[6], position[7])
              .contains(Mouse::getPosition(window))) {
        if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj)) {
          naj = true;
        }
        while (window.pollEvent(event)) {
          if ((event.type == sf::Event::MouseButtonReleased) && (naj) &&
              (event.mouseButton.button == Mouse::Left)) {
            menuNum = 4;
            menuBackground1.loadFromFile("images/fon3.jpg");
            Sprite menuBg1(menuBackground1);
            menuBg1.setPosition(0, 0);
            switcher(menuNum, position, 12);
            window.clear();
            if (print_correct_letter == true)
              window.draw(RightLetter);
            window.draw(text);
            window.display();
            naj = false;
          }
        }
      }
      if (IntRect(position[8], position[9], position[10], position[11])
              .contains(Mouse::getPosition(window))) {
        if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj)) {
          naj = true;
        }
        while (window.pollEvent(event)) {
          if ((event.type == sf::Event::MouseButtonReleased) && (naj) &&
              (event.mouseButton.button == Mouse::Left)) {
            menuNum = 4;
            menuBackground1.loadFromFile("images/fon3.jpg");
            Sprite menuBg1(menuBackground1);
            menuBg1.setPosition(0, 0);
            switcher(menuNum, position, 12);
            naj = false;
          }
        }
      }

      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        menuNum = 1;
        switcher(menuNum, position, 12);
        menuBackground1.loadFromFile("images/fon.jpg");
        Sprite menuBg1(menuBackground1);
        menuBg1.setPosition(0, 0);
      }
    }
    while (menuNum == 3) {
      while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
          window.close();
          menuNum = 0;
          ismenu = false;
        }
      }
      window.draw(menuBg1);
      window.display();
      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        menuNum = 1;
        switcher(menuNum, position, 12);
        menuBackground1.loadFromFile("images/fon.jpg");
        Sprite menuBg1(menuBackground1);
        menuBg1.setPosition(0, 0);
      }
    }
    while (menuNum == 4) {
      while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
          window.close();
          menuNum = 0;
          ismenu = false;
        }
        Exercise(event, &print_correct_letter, &current_letter, lines, utf88,
                 &current_string);
      }
      RightLetter.setString(sf::String::fromUtf8(utf88.begin(), utf88.end()));
      window.draw(menuBg1);
      if (print_correct_letter == true)
        window.draw(RightLetter);
      for (strings_to_print = 0; strings_to_print < count; strings_to_print++) {
        text.setString(String::fromUtf8(lines[strings_to_print].begin(),
                                        lines[strings_to_print].end()));
        text.setPosition(30, (strings_to_print * 25) - (current_string * 25));
        text.setFillColor(Color::Black);
        window.draw(text);
      }//

      window.display(); 
      //gameloop(0);
      if (Keyboard::isKeyPressed(Keyboard::Escape))
      {
      //
        menuNum = 2;
        switcher(menuNum, position, 12);
        menuBackground1.loadFromFile("images/fon1.jpg");
        Sprite menuBg1(menuBackground1);
        menuBg1.setPosition(0, 0);
      }
    }
  }
  return 0;
}

//game//

void gameloop(int lvl) 
{/*
	int starttime, bonusseries; 
	float penalty, bonus;*/
	switch(lvl)
	{
		case 0:
			/*starttime = 180;
			penalty = 1;
			bonusseries = 20;
			bonus = 1.5;*/
			break;
		case 1:
			/*starttime = 180;
			penalty = 2;
			bonusseries = 30;
			bonus = 1;*/
			break;
		case 2:
			/*starttime = 120;
			penalty = 3.5;
			bonusseries = 40;
			bonus = 1;*/
			break;
	}
	bool gameover = false;
	Clock clock;
	double elaps = clock.restart().asSeconds();
	while(!gameover)  
	{
		elaps = clock.getElapsedTime().asSeconds();
		std::cout << elaps << "\n";
		if (Keyboard::isKeyPressed(Keyboard::Escape))
      {
      	return;
      }
	}
}
