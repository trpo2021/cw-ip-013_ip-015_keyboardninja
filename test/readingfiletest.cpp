#include <ctest.h>
#include <libninja/readingfile.hpp>

CTEST(exist_txt, lines)
{
    const int exp = IsFilesExists();
    ASSERT_EQUAL(exp, 0);
}

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

CTEST(read1, lines)
{
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/1.txt", &lines);
    bool exp = false;
    std::string real
            = "Make is typically used to build executable programs and";
    if (real == lines[0])
        exp = true;
    ASSERT_TRUE(exp);
}

CTEST(read2, lines)
{
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/2.txt", &lines);
    bool exp = false;
    std::string real
            = "In statistics, Cochrans C test, named after William G. Cochran,";
    if (real == lines[0])
        exp = true;
    ASSERT_TRUE(exp);
}

CTEST(read3, lines)
{
    std::string* lines = nullptr;
    GetStringsFromFileS("texts/3.txt", &lines);
    bool exp = false;
    std::string real
            = "Git is software for tracking changes in any set of files, "
              "usually";
    if (real == lines[0])
        exp = true;
    ASSERT_TRUE(exp);
}
