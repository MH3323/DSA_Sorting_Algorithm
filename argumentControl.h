#include <string>
#include <chrono>
#include "constant.h"
#include "Sort_VerComp.h"
#include "Sort_VerTime.h"

using namespace std;

bool isAllDigits(string s);
bool isParameter(string s);
int typeSort(string s);
int typeOrder(string s);
string typeOrder_String(string s);
string typeOrder_Num(int i);
string nameSort(string arg_name);

int *copyArrayPointer(int *arr, int size);

void SortData(int type_sort, std::chrono::high_resolution_clock::time_point &start, std::chrono::high_resolution_clock::time_point &done, long long int &comparisons, int *&arr, int size, string parameter_type);
