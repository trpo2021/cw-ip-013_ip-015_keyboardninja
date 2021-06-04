#include <ctest.h>
#include <libninja/readingfile.hpp>
CTEST(count_real, lines)
{
    std::string* lines = nullptr;
    const int count = GetStringsFromFileS("texts/1.txt", &lines);
    ASSERT_EQUAL(count, 11);
}

CTEST(count_not_real, lines)
{
    std::string* lines = nullptr;
    const int count = GetStringsFromFileS("texts/564.txt", &lines);
    ASSERT_EQUAL(count, -1);
}

CTEST(read, lines)
{
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    bool exp;
    std::string real
            = "Make is typically used to build executable programs and";
    if (real == lines[0])
        exp = true;
    ASSERT_TRUE(exp);
}
