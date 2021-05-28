#include <ctest.h>
#include <libninja/randomtext.hpp>

CTEST(GetRandomNumber, test)
{
    int exp;
    bool flag = false;
    exp = GetRandomNumber(1, 4);
    for (int i = 1; i < 5; i++) {
        if (i == exp) {
            flag = true;
            break;
        }
    }
    ASSERT_TRUE(flag);
}

CTEST(GetRandomText, test)
{
    std::string* lines = nullptr;
    GetRandomText(&lines);
    bool flag = false;
    std::string exp[4]
            = {"A computer is a machine that can be programmed",
               "What makes every American a typical one is a desire to get a "
               "well-paid job that will",
               "Advertisements want to persuade us to buy particular products "
               "How do they do it?",
               "The year of 1998 was announced by UNESCO the Year of Pushkin. "
               "In this way the mankind paid tribute"};
    for (int i = 0; i < 4; i++) {
        if (exp[i] == lines[0]) {
            flag = true;
            break;
        }
    }
    ASSERT_TRUE(flag);
}
