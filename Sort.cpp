#include "Sort.h"

// Selections sort
int indexMax(int *arr, int size, long long int &comparisons)
{
    int max = arr[0], index_max = 0;
    for (int i = 1; ++comparisons && i <= size; i++)
    {
        if (++comparisons && max < arr[i])
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

void selectionSort(int *&arr, int size, long long int &comparisons)
{
    int left = size - 1, index;
    while (++comparisons && left >= 1)
    {
        index = indexMax(arr, left, comparisons);
        if (++comparisons && left != index)
            swap(arr[left], arr[index]);
        left--;
    }
}
//---------------

void insertionSort(int *&arr, int size);

void bubbleSort(int *&arr, int size, long long int &comparisons)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
// Heap sort
void heapify(int arr[], int size, int i, long long int &comparisons)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[l] > arr[largest] && comparisons++)
        largest = l;
    if (r < size && arr[r] > arr[largest] && comparisons++)
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest, comparisons);
    }
}

void heapSort(int arr[], int size, long long int &comparisons)
{

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i, comparisons);
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisons);
    }
}

// Merge sort
void merge2Array(int *&arr, int left, int mid, int right, long long int &comparisons)
{
    // Create two temp arrays
    int subArrayOne_size = mid - left + 1;
    int subArrayTwo_size = right - mid;
    int *subArrayOne = new int[subArrayOne_size],
        *subArrayTwo = new int[subArrayTwo_size];
    // Copy data to two temp arrays
    for (int i = 0; ++comparisons && i < subArrayOne_size; i++)
    {
        subArrayOne[i] = arr[left + i];
    }
    for (int i = 0; ++comparisons && i < subArrayTwo_size; i++)
    {
        subArrayTwo[i] = arr[mid + 1 + i];
    }
    int subArrayOne_Index = 0,
        subArrayTwo_Index = 0,
        mergeArray_Index = left;
    while ((++comparisons && subArrayOne_Index < subArrayOne_size) && (++comparisons && subArrayTwo_Index < subArrayTwo_size))
    {
        if (++comparisons && subArrayOne[subArrayOne_Index] <= subArrayTwo[subArrayTwo_Index])
        {
            arr[mergeArray_Index] = subArrayOne[subArrayOne_Index];
            subArrayOne_Index++;
        }
        else
        {
            arr[mergeArray_Index] = subArrayTwo[subArrayTwo_Index];
            subArrayTwo_Index++;
        }
        mergeArray_Index++;
    }
    while (++comparisons && subArrayOne_Index < subArrayOne_size)
    {
        arr[mergeArray_Index] = subArrayOne[subArrayOne_Index];
        mergeArray_Index++;
        subArrayOne_Index++;
    }
    while (++comparisons && subArrayTwo_Index < subArrayTwo_size)
    {
        arr[mergeArray_Index] = subArrayTwo[subArrayTwo_Index];
        mergeArray_Index++;
        subArrayTwo_Index++;
    }
    delete[] subArrayOne;
    delete[] subArrayTwo;
}
void mergeSort(long long int &comparisons, int *&arr, int end, int begin)
{
    if (++comparisons && end > begin)
    {
        int mid = begin + (end - begin) / 2;
        mergeSort(comparisons, arr, mid, begin);
        mergeSort(comparisons, arr, end, mid + 1);
        merge2Array(arr, begin, mid, end, comparisons);
    }
    else
        return;
}

void quickSort(int *arr, int size);

// Radix sort
int getMax(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void countingSort(int *&arr, int size, int place)
{
    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(arr[i] / place) % 10]++;

    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}
void radixSort(int *&arr, int size, long long int &comparisons)
{
    int max = getMax(arr, size);
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(arr, size, place);
}
// -------------

void shakerSort(int *&arr, int size, long long int &comparisons)
{
    int Left = 0;
    int Right = size - 1;
    int k = 0;
    while (Left < Right)
    {
        for (int i = Left; i < Right; i++)
        {
            if (arr[i] > arr[i + 1] && comparisons++)
            {
                swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (int i = Right; i > Left; i--)
        {
            if (arr[i] < arr[i - 1] && comparisons++)
            {
                swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}

void shellSort(int *&arr, int size, long long int &comparisions)
{
    int temp, j;
    for (int gap = size / 2; ++comparisions && gap > 0; gap /= 2)
    {
        for (int i = gap; ++comparisions && i < size; i++)
        {
            temp = arr[i];
            for (j = i; (++comparisions && j >= gap) && (++comparisions && arr[j - gap] > temp); j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void flashSort(int *&arr, int size);

void SortData(int type_sort, clock_t &start, clock_t &end, long long int &comparisons, int *&arr, int size)
{
    switch (type_sort)
    {
    case selection:
        start = clock();
        selectionSort(arr, size, comparisons);
        end = clock();
        break;
    case insertion:
        break;
    case bubble:
        break;
    case heap:
        start = clock();
        heapSort(arr, size, comparisons);
        end = clock();
        break;
    case merge:
        start = clock();
        mergeSort(comparisons, arr, size - 1);
        end = clock();
        break;
    case quick:
        break;
    case radix:
        break;
    case shaker:
        start = clock();
        shakerSort(arr, size, comparisons);
        end = clock();
        break;
    case shell:
        start = clock();
        shellSort(arr, size, comparisons);
        end = clock();
        break;
    case counting:
        break;
    case flash:
        break;
    default:
        break;
    }
}
