#include "Sort.h"

// Selections sort
int indexMax(int *arr, int size, long int &comparisions)
{
    int max = arr[0], index_max = 0;
    for (int i = 1; ++comparisions && i <= size; i++)
    {
        if (++comparisions && max < arr[i])
        {
            max = arr[i];
            index_max = i;
        }
    }
    return index_max;
}

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void selectionSort(int *&arr, int size, long int &comparisions)
{
    int left = size - 1, index;
    while (++comparisions && left >= 1)
    {
        index = indexMax(arr, left, comparisions);
        if(++comparisions && left != index) swap(arr[left], arr[index]);
        left--;
    }
}
//---------------

void insertionSort(int *arr, int size);

void bubbleSort(int *arr, int size);

void headSort(int *arr, int size);

void mergeSort(int *arr, int size);

void quickSort(int *arr, int size);

void radixSort(int *arr, int size);

void shakerSort(int *arr, int size);

void shellSort(int *arr, int size);

void countingSort(int *arr, int size);

void flashSort(int *arr, int size);

void SortData(int type_sort, clock_t &start, clock_t &end, long int &comparisions, int *&arr, int size)
{
    switch (type_sort)
    {
    case selection:
        start = clock();
        selectionSort(arr, size, comparisions);
        end = clock();
        break;
    case insertion:
        break;
    case bubble:
        break;
    case heap:
        break;
    case merge:
        break;
    case quick:
        break;
    case radix:
        break;
    case shaker:
        break;
    case shell:
        break;
    case counting:
        break;
    case flash:
        break;
    default:
        break;
    }
}