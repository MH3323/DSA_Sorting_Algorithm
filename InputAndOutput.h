// This library is used for input and output function

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Constants for parameter
#define _p_time "-time"
#define _p_comp "-comp"
#define _p_both "-both"

bool readInput(string file_path, int *&arr, int &size);
bool writeOutput(string file_path, int *arr, int size);
void printParameter_AMode(long int time, long int comparisions, string parameter);
void printParameter_CMode(long int time_1, long int time_2, long int comp_1, long int comp_2, string parameter);
void printDivide();