#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include "constant.h"

using namespace std;

int findMin(int *arr, int size, long long int &comparisons);

// Selection sort
int indexMax(int *arr, int size, long long int &comparisons);
void selectionSort(int *&&arr, int size, long long int &comparisons);

void insertionSort(int *&arr, int size, long long int &comparisons);
void bubbleSort(int *&arr, int size, long long int &comparisons);
void heapSort(int *arr, int size, long long int &comparisons);

// Merge sort
void merge2Array(int *&arr, int left, int mid, int right, long long int &comparisons);
void mergeSort(long long int &comparisons, int *&arr, int end, int begin = 0);

// Quick sort
void sortFirstMiddleLast(int *&arr, int first, int mid, int last, long long int &comparisons);
int partition(int *&arr, int first, int last, long long int &comparisons);
void quickSort(int *&arr, int first, int last, long long int &comparisons);

int getMax(int *arr, int size, long long int &comparisons);
void radixCount(int *&arr, int size, int place, long long int &comparisons);
void radixSort(int *&arr, int size, long long int &comparisons);

void shakerSort(int *&arr, int size, long long int &comparisons);
void shellSort(int *&arr, int size, long long int &comparisons);
void countingSort(int *&arr, int size, long long int &comparisons);
void flashSort(int arr, int size, long long int &comparisons);
void SortData_Ver_Comp(int type_sort, long long int &comparisons, int *&arr, int size);
