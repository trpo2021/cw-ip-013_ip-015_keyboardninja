#include <SFML/Graphics.hpp>
#include <libninja/exercise.hpp>
#include <libninja/level.hpp>
#include <libninja/randomtext.hpp>
#include <libninja/stars.hpp>
#include <libninja/switcher.hpp>

using namespace sf;

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;
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
    string* lines = nullptr;
    int mistakes;
    int queue;
    std::string mistakes_print;
    std::string mistake_message;
    unsigned int height = 660;
    unsigned int width = 1050;
    RenderWindow window(sf::VideoMode(width, height), "ninja");
    //////////////
    Texture menuBackground1;
    menuBackground1.loadFromFile("src/resources/images/fon.jpg");
    Sprite menuBg1(menuBackground1);
    menuBg1.setPosition(0, 0);
    //////////////
    Font font;
    if (!font.loadFromFile("src/resources/fonts/19939.otf")) {
        std::cout << "ERROR" << std::endl;
    }
    bool print_correct_letter = false;
    Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    text.setPosition(30, 200);
    Text RightLetter;
    std::string string_by_user;
    RightLetter.setFont(font);
    RightLetter.setCharacterSize(24);
    RightLetter.setFillColor(sf::Color::Black);
    RightLetter.setStyle(sf::Text::Bold);
    RightLetter.setPosition(30, 300);
    Text timer;
    std::string time = "Time left: ";
    timer.setFont(font);
    timer.setString(time);
    timer.setCharacterSize(24);
    timer.setFillColor(sf::Color::Black);
    timer.setStyle(sf::Text::Bold);
    timer.setPosition(10, 600);
    Text Mistakes;
    Mistakes.setFont(font);
    Mistakes.setCharacterSize(24);
    Mistakes.setFillColor(sf::Color::Red);
    Mistakes.setStyle(sf::Text::Bold);
    Mistakes.setPosition(10, 10);
    Text Series;
    std::string series = "Current series: ";
    Series.setFont(font);
    Series.setString(series);
    Series.setCharacterSize(24);
    Series.setFillColor(sf::Color::Black);
    Series.setStyle(sf::Text::Bold);
    Series.setPosition(180, 10);
    Text Mistake;
    std::string mistake;
    Mistake.setFont(font);
    Mistake.setCharacterSize(30);
    Mistake.setStyle(sf::Text::Bold);
    Mistake.setPosition(30, 400);
    count = GetRandomText(&lines);
    string_by_user.clear();
    print_correct_letter = false;

    current_letter = 0;
    mistakes = 0;
    current_string = 0;
    queue = 5;
    while (ismenu) {
        Event event;
        while (menuNum == 1) {
            mistake.clear();
            while (window.pollEvent(event)) {
                window.setFramerateLimit(60);
                if (event.type == Event::Closed) {
                    window.close();
                    menuNum = 0;
                    ismenu = false;
                }
                if (event.type == Event::Resized) {
                    height = event.size.height;
                    width = event.size.width;
                    switcher(menuNum, position, height, width);
                }
            }
            window.draw(menuBg1);
            window.display();
            switcher(menuNum, position, height, width);
            if (IntRect(position[0], position[1], position[2], position[3])
                        .contains(Mouse::getPosition(window))) {
                if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj)) {
                    naj = true;
                }
                while (window.pollEvent(event)) {
                    if ((event.type == Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 2;
                        switcher(menuNum, position, height, width);
                        menuBackground1.loadFromFile(
                                "src/resources/images/fon1.jpg");
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
                    if ((event.type == Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 3;
                        switcher(menuNum, position, height, width);
                        menuBackground1.loadFromFile(
                                "src/resources/images/fon2.jpg");
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
                    if ((event.type == Event::MouseButtonReleased) && (naj)
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
                    switcher(menuNum, position, height, width);
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
                    if ((event.type == Event::MouseButtonReleased) && (naj)
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
                        menuBackground1.loadFromFile(
                                "src/resources/images/fon3.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, height, width);
                        if (print_correct_letter)
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
                    if ((event.type == Event::MouseButtonReleased) && (naj)
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
                        menuBackground1.loadFromFile(
                                "src/resources/images/fon3.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, height, width);
                        if (print_correct_letter)
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
                    if ((event.type == Event::MouseButtonReleased) && (naj)
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
                        menuBackground1.loadFromFile(
                                "src/resources/images/fon3.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, height, width);
                        if (print_correct_letter)
                            window.draw(RightLetter);
                        window.draw(text);
                        window.display();

                        naj = false;
                    }
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                menuNum = 1;
                switcher(menuNum, position, height, width);
                menuBackground1.loadFromFile("src/resources/images/fon.jpg");
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
                switcher(menuNum, position, height, width);
                menuBackground1.loadFromFile("src/resources/images/fon.jpg");
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
            timeremain
                    = (starttime - mistakes * penalty
                       - clock.getElapsedTime().asSeconds()
                       + countseries * bonus - timepause);
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
                        string_by_user,
                        mistake,
                        &current_string,
                        &mistakes,
                        &queue,
                        count,
                        &intseries);
            }

            mistakes_print = "Mistakes: " + std::to_string(mistakes);
            Mistakes.setString(mistakes_print);
            RightLetter.setString(string_by_user);
            window.draw(menuBg1);
            if (print_correct_letter)
                window.draw(RightLetter);
            series = "Current series: ";
            series += std::to_string(intseries);
            Series.setString(series);
            if (mistake == "GOOD!")
                Mistake.setFillColor(Color::Green);
            if ("Mistake" == mistake.substr(0, 7))
                Mistake.setFillColor(Color::Red);
            if (intseries > 20) {
                mistake = "EXCELLENT!";
                Mistake.setFillColor(sf::Color::Green);
            }
            Mistake.setString(mistake);
            for (strings_to_print = 0; strings_to_print < queue;
                 strings_to_print++) {
                text.setString(lines[strings_to_print]);
                text.setPosition(
                        30,
                        ((strings_to_print * 25) - (current_string * 25) + 50));
                text.setFillColor(Color::Black);

                window.draw(Series);
                window.draw(timer);
                window.draw(Mistakes);
                window.draw(text);
                window.draw(Mistake);
            }
            window.display();
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                timepause = starttime - timeremain - mistakes * penalty
                        + countseries * bonus; //////////////////////
                menuNum = 5;
                switcher(menuNum, position, height, width);
                menuBackground1.loadFromFile("src/resources/images/fon4.jpg");
                Sprite menuBg1(menuBackground1);
                menuBg1.setPosition(0, 0);
            }
            if (timeremain <= 0) {
                menuNum = 6;
                switcher(menuNum, position, height, width);
                menuBackground1.loadFromFile("src/resources/images/fon5.jpg");
                Sprite menuBg1(menuBackground1);
                menuBg1.setPosition(0, 0);
            }
            if (current_string == (count - 1)) {
                menuNum = 6;
                switcher(menuNum, position, height, width);
                int star = stars(mistakes, timeremain);
                switch (star) {
                case 0:
                    menuBackground1.loadFromFile(
                            "src/resources/images/fon5.jpg");
                    break;
                case 1:
                    menuBackground1.loadFromFile(
                            "src/resources/images/fon6.jpg");
                    break;
                case 2:
                    menuBackground1.loadFromFile(
                            "src/resources/images/fon7.jpg");
                    break;
                case 3:
                    menuBackground1.loadFromFile(
                            "src/resources/images/fon8.jpg");
                    break;
                default:
                    menuBackground1.loadFromFile(
                            "src/resources/images/fon5.jpg");
                    break;
                }
                Sprite menuBg1(menuBackground1);
                menuBg1.setPosition(0, 0);
            }
        }
        while (menuNum == 5) {
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                    menuNum = 0;
                    ismenu = false;
                }
                if (event.type == Event::Resized) {
                    height = event.size.height;
                    width = event.size.width;
                    switcher(menuNum, position, height, width);
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
                    if ((event.type == Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 4;
                        // clock
                        clock.restart();
                        window.clear();
                        menuBackground1.loadFromFile(
                                "src/resources/images/fon3.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, height, width);
                        if (print_correct_letter)
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
                    if ((event.type == Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 1;
                        // clock
                        clock.restart();
                        timepause = 0;
                        // series reset
                        intseries = 0;
                        countseries = 0;
                        //
                        menuBackground1.loadFromFile(
                                "src/resources/images/fon.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, height, width);
                        window.clear();
                        naj = false;
                        count = GetRandomText(&lines);
                        string_by_user.clear();
                        print_correct_letter = false;

                        current_letter = 0;
                        mistakes = 0;
                        current_string = 0;
                        queue = 5;
                    }
                }
            }
        }
        while (menuNum == 6) {
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                    menuNum = 0;
                    ismenu = false;
                }
                if (event.type == Event::Resized) {
                    height = event.size.height;
                    width = event.size.width;
                    switcher(menuNum, position, height, width);
                }
            }
            window.draw(menuBg1);
            Text Mesg;
            Mesg.setFont(font);
            Mesg.setCharacterSize(48);
            Mesg.setFillColor(sf::Color::Black);
            Mesg.setStyle(sf::Text::Bold);

            string mesg[2];
            mesg[0] = "Mistakes: " + std::to_string(mistakes);
            mesg[1] = "Time remain: " + std::to_string(timeremain / 60) + ":"
                    + std::to_string(timeremain % (int)60);
            for (int i = 0; i < 2; i++) {
                Mesg.setString(mesg[i]);
                Mesg.setPosition((525 - 100 - 60 * i), (660 / 2) + i * 50);
                window.draw(Mesg);
            }
            window.display();
            if (IntRect(position[0], position[1], position[2], position[3])
                        .contains(Mouse::getPosition(window))) {
                if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj)) {
                    naj = true;
                }
                while (window.pollEvent(event)) {
                    if ((event.type == Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 4;
                        // clock
                        clock.restart();
                        timepause = 0;
                        // series reset
                        intseries = 0;
                        countseries = 0;
                        //
                        menuBackground1.loadFromFile(
                                "src/resources/images/fon3.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, height, width);
                        window.clear();
                        naj = false;
                        count = GetRandomText(&lines);
                        string_by_user.clear();
                        print_correct_letter = false;
                        mistake.clear();
                        current_letter = 0;
                        mistakes = 0;
                        current_string = 0;
                        queue = 5;
                    }
                }
            }
            if (IntRect(position[4], position[5], position[6], position[7])
                        .contains(Mouse::getPosition(window))) {
                if ((Mouse::isButtonPressed(Mouse::Left)) && (!naj)) {
                    naj = true;
                }
                while (window.pollEvent(event)) {
                    if ((event.type == Event::MouseButtonReleased) && (naj)
                        && (event.mouseButton.button == Mouse::Left)) {
                        menuNum = 1;
                        // clock
                        clock.restart();
                        timepause = 0;
                        // series reset
                        intseries = 0;
                        countseries = 0;
                        //
                        menuBackground1.loadFromFile(
                                "src/resources/images/fon.jpg");
                        Sprite menuBg1(menuBackground1);
                        menuBg1.setPosition(0, 0);
                        switcher(menuNum, position, height, width);
                        window.clear();
                        naj = false;
                        count = GetRandomText(&lines);
                        string_by_user.clear();
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
