#pragma once
#include <fstream>
#include <iostream>
#include <string>

int CountLinesInFile(std::string filename);
int GetStringsFromFileS(std::string filename, std::string** _lines);
