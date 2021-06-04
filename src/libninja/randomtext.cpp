#include <libninja/randomtext.hpp>

int GetRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int GetRandomText(std::string** _lines)
{
    srand(time(NULL));
    int number_of_text = 0;
    int count = 0;
    std::string filename;
    number_of_text = GetRandomNumber(1, 6);
    filename = "texts/" + std::to_string(number_of_text) + ".txt";
    count = GetStringsFromFileS(filename, _lines);
    if (count == -1) {
        std::cout << "Error! Could't open the " << filename << std::endl;
        exit(3);
    }
    return count;
}
