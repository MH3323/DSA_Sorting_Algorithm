#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include "constant.h"

using namespace std;

// Selection sort
int indexMax(int *arr, int size);
void selectionSort(int *&&arr, int size);
//-------
void insertionSort(int *&arr, int size);
void bubbleSort(int *&arr, int size);
void heapSort(int *arr, int size);

// Merge sort
void merge2Array(int *&arr, int left, int mid, int right);
void mergeSort(int *&arr, int end, int begin = 0);
//-------

// Quick sort
void sortFirstMiddleLast(int *&arr, int first, int mid, int last);
int partition(int *&arr, int first, int last);
void quickSort(int *&arr, int first, int last);
//-------

// Radix sort
int getMax(int *arr, int size);
void radixCount(int *&arr, int size, int place);
void radixSort(int *&arr, int size);
//-------

void shakerSort(int *&arr, int size);
void shellSort(int *&arr, int size);
void countingSort(int *&arr, int size);
void flashSort(int arr, int size);

void SortData_Ver_Time(int type_sort, std::chrono::high_resolution_clock::time_point &start, std::chrono::high_resolution_clock::time_point &done, int *&arr, int size);
