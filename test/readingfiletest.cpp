#include <ctest.h>
#include <iostream>
#include <libninja/readingfile.hpp>
CTEST(count, lines)
{
    std::string* lines = nullptr;
    const int count = GetStringsFromFileS("texts/1.txt", &lines);
    ASSERT_EQUAL(count, 15);
}

CTEST(read, lines)
{
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    bool exp;
    std::string real = "A computer is a machine that can be programmed";
    if (real == lines[0])
        exp = true;
    ASSERT_TRUE(exp);
}
