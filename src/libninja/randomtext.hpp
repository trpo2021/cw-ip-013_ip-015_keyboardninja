#pragma once
#include <fstream>
#include <iostream>

int IsFilesExists();
int CountLinesInFile(std::string filename);
int GetStringsFromFileS(std::string filename, std::string** _lines);
int GetRandomNumber(int min, int max);
int GetRandomText(std::string** _lines);
