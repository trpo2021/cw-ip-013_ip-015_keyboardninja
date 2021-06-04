#include <libninja/readingfile.hpp>

int CountLinesInFile(std::string filename)
{
    std::ifstream F(filename, std::ios::in);
    if (!F) {
        return -1;
    }
    int count = 0;
    char buffer[1000];
    while (!F.eof()) {
        count++;
        F.getline(buffer, 1000);
    }
    F.close();
    return count;
}

int GetStringsFromFileS(std::string filename, std::string** _lines)
{
    std::string* lines;
    int n = CountLinesInFile(filename);
    if (n == -1)
        return -1;
    std::ifstream F(filename);
    if (!F)
        return -1;

    try {
        lines = new std::string[n];
    } catch (std::bad_alloc& e) {
        std::cout << e.what() << std::endl;
        F.close();
        return -2;
    }
    char buffer[1000];

    for (int i = 0; i < n; i++) {
        F.getline(buffer, 1000);
        int len;
        for (len = 0; buffer[len] != '\0'; len++)
            ;
        lines[i].assign(buffer, len);
    }
    F.close();
    *_lines = lines;
    return n;
}
