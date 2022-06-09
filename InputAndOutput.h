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

// Constant for data type
const int type_rand = 0;    // Randomized data
const int type_sorted = 1;  // Sorted data
const int type_rev = 2;     // Reverse sorted data
const int type_nsorted = 3; // Nearly sorted data

bool isAllDigits(string s);
bool isParameter(string s);
int typeSort(string s);
int typeOrder(string s);
string typeOrder_String(string s);

double calRunningTime(clock_t start, clock_t end);

bool readInput(string file_path, int *&arr, int &size);
bool writeOutput(string file_path, int *arr, int size);
void printParameter_AMode(double time, long long int comparisions, string parameter);
void printParameter_CMode(double time_1, double time_2, long long int comp_1, long long int comp_2, string parameter);
void printDivide();

void printTest(int *arr, int size);