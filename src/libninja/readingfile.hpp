#pragma once
#include <fstream>
#include <iostream>
#include <string>

int IsFilesExists();
int CountLinesInFile(std::string filename);
int GetStringsFromFileS(std::string filename, std::string** _lines);
