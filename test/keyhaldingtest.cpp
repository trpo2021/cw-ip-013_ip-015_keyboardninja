#include <ctest.h>
#include <libninja/exercise.hpp>
#include <libninja/readingfile.hpp>

CTEST(keycode, A)
{
    sf::Event event;
    int current_string = 0;
    long unsigned int current_letter = 0;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    int keycode = 65;
    const bool exp
            = Keyhalding(event, current_string, keycode, current_letter, lines);
    ASSERT_TRUE(exp);
}

CTEST(keycode, B)
{
    sf::Event event;
    int current_string = 0;
    long unsigned int current_letter = 0;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    int keycode = 66;
    const bool exp
            = Keyhalding(event, current_string, keycode, current_letter, lines);
    ASSERT_FALSE(exp);
}

CTEST(keycode, space)
{
    sf::Event event;
    int current_string = 0;
    long unsigned int current_letter = 1;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    int keycode = 32;
    const bool exp
            = Keyhalding(event, current_string, keycode, current_letter, lines);
    ASSERT_TRUE(exp);
}
