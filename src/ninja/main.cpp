#include <iostream>
#include <libninja/readingfile.hpp>

int main() {
  int count;
  string *lines = nullptr;
  count = GetStringsFromFileS("texts/rus.txt", &lines);
  if (count < 0) {
    std::cout << "Error" << std::endl;
    return 1;
  }
  for (int i = 0; i < count; i++) {
    std::cout << lines[i] << std::endl;
  }
  if (lines != nullptr)
    delete[] lines;
}
