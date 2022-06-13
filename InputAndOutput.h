// This library is used for input and output function

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "constant.h"

using namespace std;

bool readInput(string file_path, int *&arr, int &size);
bool writeOutput(string file_path, int *arr, int size);
void printParameter_AMode(double time, long long int comparisions, string parameter);
void printParameter_CMode(double time_1, double time_2, long long int comp_1, long long int comp_2, string parameter);
void printDivide();

void printTest(int *arr, int size);