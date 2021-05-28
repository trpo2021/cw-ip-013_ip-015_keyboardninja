#include <ctest.h>
#include <libninja/exercise.hpp>
#include <libninja/readingfile.hpp>

CTEST(keycode, true)
{
    int current_string = 0;
    long unsigned int current_letter = 0;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    int keycode = (int)lines[0][0];
    const bool exp = Keyhalding(current_string, keycode, current_letter, lines);
    ASSERT_TRUE(exp);
}

CTEST(keycode, false)
{
    int current_string = 0;
    long unsigned int current_letter = 0;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    int keycode = (int)lines[0][1];
    const bool exp = Keyhalding(current_string, keycode, current_letter, lines);
    ASSERT_FALSE(exp);
}

CTEST(keycode, special_symbol_space)
{
    int current_string = 0;
    long unsigned int current_letter = 1;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    int keycode = (int)lines[0][1];
    const bool exp = Keyhalding(current_string, keycode, current_letter, lines);
    ASSERT_TRUE(exp);
}
