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

// Selection sort
int indexMax(int *arr, int size, long long int &comparisons);
void swap(int &a, int &b);
void selectionSort(int *&&arr, int size, long long int &comparisons);

void insertionSort(int *arr, int size);
void bubbleSort(int *arr, int size);
void heapSort(int *arr, int size, long long int &comparisons);

// Merge sort
void merge2Array(int *&arr, int left, int mid, int right, long long int &comparisons);
void mergeSort(long long int &comparisons, int *&arr, int end, int begin = 0);

void quickSort(int *&arr, int size);
void radixSort(int *&arr, int size);
void shakerSort(int *&arr, int size, long long int &comparisons);
void shellSort(int *&arr, int size, long long int &comparisions);
void countingSort(int *&arr, int size);
void flashSort(int *&arr, int size);
void SortData(int type_sort, clock_t &start, clock_t &end, long long int &comparisons, int *&arr, int size);
