#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;

// Constant for data type
#define rand 0;    // Randomized data
#define sorted 1;  // Sorted data
#define rev 2;     // Reverse sorted data
#define nsorted 3; // Nearly sorted data

template <class T>
void HoanVi(T &a, T &b);

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);