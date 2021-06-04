#include <ctest.h>
#include <libninja/randomtext.hpp>

CTEST(GetRandomNumber, test)
{
    int exp;
    bool flag = false;
    exp = GetRandomNumber(1, 6);
    for (int i = 1; i < 7; i++) {
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
    std::string exp[6] = {
            "Make is typically used to build executable programs and",
            "In statistics, Cochrans C test, named after William G. Cochran,",
            "Git is software for tracking changes in any set of files, usually",
            "In software development, Make is a build automation tool that",
            "As Git is a distributed version-control system, it could",
            "Make can decide where to start through topological sorting."};
    for (int i = 0; i < 6; i++) {
        if (exp[i] == lines[0]) {
            flag = true;
            break;
        }
    }
    ASSERT_TRUE(flag);
}
