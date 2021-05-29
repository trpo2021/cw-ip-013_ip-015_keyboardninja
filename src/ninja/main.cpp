#include <SFML/Graphics.hpp>
#include <libninja/exercise.hpp>
#include <libninja/randomtext.hpp>
#include <libninja/switcher.hpp>
#include <libninja/level.hpp>
#include <sstream>

using namespace sf;

void gameloop(
        int lvl,
        sf::Event& event,
        bool print_correct_letter,
        long unsigned int current_letter,
        std::string lines[],
        std::string& utf88,
        int current_string);

int main()
{
    setlocale(LC_ALL, "Russian");
    Clock clock;
    int timepause = 0;
    int timeremain = 0;
    int intseries = 0;
    int countseries = 0;
    int bonusseries = 0;
    int starttime = 0;
    float penalty = 0;
    float bonus = 0;
    int lvl = 0;
    ///////
    int position[12];
    int menuNum = 1;
    bool ismenu = true;
    bool naj = false;
    ///////
    int count;
    long unsigned int current_letter;
    int current_string;
    int strings_to_print;
    string* lines = NULL;
    int mistakes;
    int queue;
    std::string mistakes_print;
    std::string mistake_message;
    int height = 660;
	int width = 1050; 
    sf::RenderWindow window(sf::VideoMode(width, height), "ninja");
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
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    text.setPosition(30, 200);
    sf::Text RightLetter;
    std::string utf88;
    RightLetter.setFont(font);
    RightLetter.setCharacterSize(24);
    RightLetter.setFillColor(sf::Color::Black);
    RightLetter.setStyle(sf::Text::Bold);
    RightLetter.setPosition(30, 300);
    sf::Text timer;
    std::string time = "Time left: ";
    timer.setFont(font);
    timer.setString(time);
    timer.setCharacterSize(24);
    timer.setFillColor(sf::Color::Black);
    timer.setStyle(sf::Text::Bold);
    timer.setPosition(10, 600);
    sf::Text Mistakes;
    Mistakes.setFont(font);
    Mistakes.setCharacterSize(24);
    Mistakes.setFillColor(sf::Color::Red);
    Mistakes.setStyle(sf::Text::Bold);
    Mistakes.setPosition(10, 10);
    sf::Text Series;
    std::string series = "Current series: ";
    Series.setFont(font);
    Series.setString(series);
    Series.setCharacterSize(24);
    Series.setFillColor(sf::Color::Black);
    Series.setStyle(sf::Text::Bold);
    Series.setPosition(180, 10);
    count = GetRandomText(&lines);
    utf88.clear();
    print_correct_letter = false;

    current_letter = 0;
    mistakes = 0;
    current_string = 0;
    queue = 5;
    while (ismenu) {
        sf::Event event;
        
        
        while (menuNum == 1) {
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                    menuNum = 0;
                    ismenu = false;
                }
                if (event.type == Event::Resized) {
                	height = event.size.height;
    				width = event.size.width;
    				switcher(menuNum, position, 12, height, width);
                }
            }
            window.draw(menuBg1);
            window.display();
            switcher(menuNum, position, 12, height, width);
            if (IntRect(position[0], position[1], position[2], position[3])
                        .contains(Mouse::getPosition(window))) {
                if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj)) {
                    naj = true;
                }
                while (window.pollEvent(event)) {
                    if ((event.type == sf::Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 2;
                        switcher(menuNum, position, 12, height, width);
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
                    if ((event.type == sf::Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 3;
                        switcher(menuNum, position, 12, height, width);
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
                    if ((event.type == sf::Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
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
                if (event.type == Event::Resized) {
                	height = event.size.height;
    				width = event.size.width;
    				switcher(menuNum, position, 12, height, width);
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
                    if ((event.type == sf::Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 4;
                        // clock
                        clock.restart();
                        // series reset
                        intseries = 0;
                        countseries = 0;
                        // lvl = easy
                        lvl = 0;
                        window.clear();
                        menuBackground1.loadFromFile("images/fon3.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, 12, height, width);
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
                    if ((event.type == sf::Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 4;
                        // clock
                        clock.restart();
                        // series reset
                        intseries = 0;
                        countseries = 0;
                        // lvl = normal
                        lvl = 1;
                        window.clear();
                        menuBackground1.loadFromFile("images/fon3.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, 12, height, width);
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
                    if ((event.type == sf::Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 4;
                        // clock
                        clock.restart();
                        // series reset
                        intseries = 0;
                        countseries = 0;
                        // lvl = hard
                        lvl = 2;
                        window.clear();
                        menuBackground1.loadFromFile("images/fon3.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, 12, height, width);
                        if (print_correct_letter == true)
                            window.draw(RightLetter);
                        window.draw(text);
                        window.display();

                        naj = false;
                    }
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                menuNum = 1;
                switcher(menuNum, position, 12, height, width);
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
                switcher(menuNum, position, 12, height, width);
                menuBackground1.loadFromFile("images/fon.jpg");
                Sprite menuBg1(menuBackground1);
                menuBg1.setPosition(0, 0);
            }
        }
        while (menuNum == 4) {
            //
            level(lvl, &starttime, &penalty, &bonus, &bonusseries);
            int check;
            if (check < intseries / bonusseries) {
                countseries += 1;
                check = intseries / bonusseries;
            } else if (intseries / bonusseries == 0) {
                check = 0;
            }
            //
            timeremain = (starttime - mistakes * penalty
                     - clock.getElapsedTime().asSeconds() + countseries * bonus - timepause)
                    ;
            time = "Time left: ";
            time += std::to_string(timeremain / 60);
            time += ":";
            time += std::to_string(timeremain % (int)60);
            timer.setString(time);
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                    menuNum = 0;
                    ismenu = false;
                }
                if (event.type == Event::Resized) {
                	height = event.size.height;
    				width = event.size.width;
    			}
                Exercise(
                        event,
                        &print_correct_letter,
                        &current_letter,
                        lines,
                        utf88,
                        &current_string,
                        &mistakes,
                        &queue,
                        count,
                        &intseries);
            }
            mistakes_print = "Mistakes: " + std::to_string(mistakes);
            Mistakes.setString(mistakes_print);
            RightLetter.setString(
                    sf::String::fromUtf8(utf88.begin(), utf88.end()));
            window.draw(menuBg1);
            if (print_correct_letter == true)
                window.draw(RightLetter);
            series = "Current series: ";
            series += std::to_string(intseries);
            Series.setString(series);
            for (strings_to_print = 0; strings_to_print < queue;
                 strings_to_print++) {
                text.setString(String::fromUtf8(
                        lines[strings_to_print].begin(),
                        lines[strings_to_print].end()));
                text.setPosition(
                        30,
                        ((strings_to_print * 25) - (current_string * 25) + 50));
                text.setFillColor(Color::Black);

                window.draw(Series);
                window.draw(timer);
                window.draw(Mistakes);
                window.draw(text);
            }
            window.display();
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            	timepause = starttime - timeremain;//////////////////////
                menuNum = 5;
                switcher(menuNum, position, 12, height, width);
                menuBackground1.loadFromFile("images/fon4.jpg");
                Sprite menuBg1(menuBackground1);
                menuBg1.setPosition(0, 0);
            }
        }
        while (menuNum == 5){
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                    menuNum = 0;
                    ismenu = false;
                }
                if (event.type == Event::Resized) {
                	height = event.size.height;
    				width = event.size.width;
    				switcher(menuNum, position, 12, height, width);
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
                    if ((event.type == sf::Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 4;
                        // clock
                        clock.restart();
                        window.clear();
                        menuBackground1.loadFromFile("images/fon3.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, 12, height, width);
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
                    if ((event.type == sf::Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 1;
                        // clock
                        clock.restart();
                        timepause = 0;
                        // series reset
                        intseries = 0;
                        countseries = 0;
                        //
                        menuBackground1.loadFromFile("images/fon.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, 12, height, width);
                        window.clear();
                        naj = false;
                        count = GetRandomText(&lines);
                        utf88.clear();
                        print_correct_letter = false;

                        current_letter = 0;
                        mistakes = 0;
                        current_string = 0;
                        queue = 5;
                    }
                }
            }
          }
    }
    return 0;
}

// game//

void gameloop(
        int lvl,
        sf::Event& event,
        bool print_correct_letter,
        long unsigned int current_letter,
        std::string lines[],
        std::string& utf88,
        int current_string,
        int mistakes,
        int queue,
        int count,
        int intseries)
{ /*
      int starttime, bonusseries;
      float penalty, bonus;*/

    switch (lvl) {
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
    //double elaps = clock.restart();
    while (!gameover) {
        Exercise(
                event,
                &print_correct_letter,
                &current_letter,
                lines,
                utf88,
                &current_string,
                &mistakes,
                &queue,
                count,
                &intseries);
        //elaps = clock.getElapsedTime().asSeconds();
        //std::cout << elaps << "\n";
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            return;
        }
    }
}


