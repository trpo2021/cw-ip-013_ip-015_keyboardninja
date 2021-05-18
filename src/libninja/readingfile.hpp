#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int CountLinesInFile(string filename);
int GetStringsFromFileS(string filename, string **_lines);
