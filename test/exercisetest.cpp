#include <ctest.h>
#include <libninja/exercise.hpp>
#include <libninja/readingfile.hpp>

CTEST(mistake_true, exercise)
{
    sf::Event event;
    long unsigned int current_letter = 0;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    std::string utf88 = "BCF";
    std::string mistake;
    int current_string = 0;
    int mistakes = 0;
    int intseries = 0;
    int keycode = 11;
    InvoiceProcessing(
            event,
            &current_letter,
            lines,
            utf88,
            mistake,
            current_string,
            &intseries,
            &mistakes,
            keycode);
    ASSERT_EQUAL(mistakes, 1);
}

CTEST(mistake_false, exercise)
{
    sf::Event event;
    long unsigned int current_letter = 0;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    std::string utf88 = "BCF";
    std::string mistake;
    int current_string = 0;
    int mistakes = 0;
    int intseries = 0;
    int keycode = 65;
    InvoiceProcessing(
            event,
            &current_letter,
            lines,
            utf88,
            mistake,
            current_string,
            &intseries,
            &mistakes,
            keycode);
    ASSERT_EQUAL(mistakes, 0);
}

CTEST(nextstring, exercise)
{
    long unsigned int current_letter = 46;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    std::string utf88 = "BCF";
    int current_string = 0;
    int count = 10;
    int queue = 5;
    NextString(&current_letter, lines, utf88, &current_string, &queue, count);
    ASSERT_EQUAL(queue, 6);
}

CTEST(series_up, exercise)
{
    sf::Event event;
    long unsigned int current_letter = 0;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    std::string utf88 = "BCF";
    std::string mistake;
    int current_string = 0;
    int mistakes = 0;
    int intseries = 5;
    int keycode = 65;
    InvoiceProcessing(
            event,
            &current_letter,
            lines,
            utf88,
            mistake,
            current_string,
            &intseries,
            &mistakes,
            keycode);
    ASSERT_EQUAL(intseries, 6);
}

CTEST(series_down, exercise)
{
    sf::Event event;
    long unsigned int current_letter = 0;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    std::string utf88 = "BCF";
    std::string mistake;
    int current_string = 0;
    int mistakes = 0;
    int intseries = 5;
    int keycode = 66;
    InvoiceProcessing(
            event,
            &current_letter,
            lines,
            utf88,
            mistake,
            current_string,
            &intseries,
            &mistakes,
            keycode);
    ASSERT_EQUAL(intseries, 0);
}

CTEST(current_string_clear, exercise)
{
    bool flag = false;
    long unsigned int current_letter = 46;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    std::string utf88 = "BCF";
    int current_string = 0;
    int count = 10;
    int queue = 5;
    NextString(&current_letter, lines, utf88, &current_string, &queue, count);
    if (lines[0] == "")
        flag = true;
    ASSERT_TRUE(flag);
}

CTEST(utf88_clear, exercise)
{
    bool flag = false;
    long unsigned int current_letter = 46;
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    std::string utf88 = "BCF";
    int current_string = 0;
    int count = 10;
    int queue = 5;
    NextString(&current_letter, lines, utf88, &current_string, &queue, count);
    if (utf88 == "")
        flag = true;
    ASSERT_TRUE(flag);
}
