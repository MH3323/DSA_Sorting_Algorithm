// This library is used for input and output function

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <chrono>
#include "constant.h"

using namespace std;

bool readInput(string file_path, int *&arr, int &size);
bool writeOutput(string file_path, int *arr, int size);
void printParameter_AMode(std::chrono::high_resolution_clock::time_point start,
                          std::chrono::high_resolution_clock::time_point end,
                          long long int comparisions, string parameter);
void printParameter_CMode(std::chrono::high_resolution_clock::time_point start,
                          std::chrono::high_resolution_clock::time_point end,
                          std::chrono::high_resolution_clock::time_point start2,
                          std::chrono::high_resolution_clock::time_point end2,
                          long long int comp_1, long long int comp_2, string parameter);
void printDivide();

void printTest(int *arr, int size);