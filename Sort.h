#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;

// Constant for type of sorting algoritm
#define selection 0
#define insertion 1
#define bubble 2
#define heap 3
#define merge 4
#define quick 5
#define radix 6
#define shaker 7
#define shell 8
#define counting 9
#define flash 10

void selectionSort(int *arr, int size);
void insertionSort(int *arr, int size);
void bubbleSort(int *arr, int size);
void headSort(int *arr, int size);
void mergeSort(int *arr, int size);
void quickSort(int *arr, int size);
void radixSort(int *arr, int size);
void shakerSort(int *arr, int size);
void shellSort(int *arr, int size);
void countingSort(int *arr, int size);
void flashSort(int arr, int size);
void SortData(int type_sort, clock_t &start, clock_t &end, long int &comparisions, int *&arr, int size);