#include <string>
#include <time.h>
#include "constant.h"

using namespace std;

bool isAllDigits(string s);
bool isParameter(string s);
int typeSort(string s);
int typeOrder(string s);
string typeOrder_String(string s);
string typeOrder_Num(int i);
string nameSort(string arg_name);

double calRunningTime(clock_t start, clock_t end);