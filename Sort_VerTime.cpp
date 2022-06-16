#include "Sort_VerTime.h"

int findMin(int *arr, int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

// Selections sort
int indexMax(int *arr, int size)
{
    int max = arr[0], index_max = 0;
    for (int i = 1; i <= size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            index_max = i;
        }
    }
    return index_max;
}

void selectionSort(int *&arr, int size)
{
    int left = size - 1, index;
    while (left >= 1)
    {
        index = indexMax(arr, left);
        swap(arr[left], arr[index]);
        left--;
    }
}
//-----------------------------------------------------------------

void insertionSort(int *&arr, int size)
{
    int index = 1, pick, insert;
    while (index < size)
    {
        pick = arr[index];
        insert = index - 1;
        while (insert >= 0 && arr[insert] > pick)
        {
            arr[insert + 1] = arr[insert];
            insert = insert - 1;
        }
        arr[insert + 1] = pick;
        ++index;
    }
}

void bubbleSort(int *&arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Heap sort
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
//-----------------------------------------------------------------

// Merge sort
void merge2Array(int *&arr, int left, int mid, int right)
{
    // Create two temp arrays
    int subArrayOne_size = mid - left + 1;
    int subArrayTwo_size = right - mid;
    int *subArrayOne = new int[subArrayOne_size],
        *subArrayTwo = new int[subArrayTwo_size];
    // Copy data to two temp arrays
    for (int i = 0; i < subArrayOne_size; i++)
    {
        subArrayOne[i] = arr[left + i];
    }
    for (int i = 0; i < subArrayTwo_size; i++)
    {
        subArrayTwo[i] = arr[mid + 1 + i];
    }
    int subArrayOne_Index = 0,
        subArrayTwo_Index = 0,
        mergeArray_Index = left;
    while ((subArrayOne_Index < subArrayOne_size) && (subArrayTwo_Index < subArrayTwo_size))
    {
        if (subArrayOne[subArrayOne_Index] <= subArrayTwo[subArrayTwo_Index])
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
    while (subArrayOne_Index < subArrayOne_size)
    {
        arr[mergeArray_Index] = subArrayOne[subArrayOne_Index];
        mergeArray_Index++;
        subArrayOne_Index++;
    }
    while (subArrayTwo_Index < subArrayTwo_size)
    {
        arr[mergeArray_Index] = subArrayTwo[subArrayTwo_Index];
        mergeArray_Index++;
        subArrayTwo_Index++;
    }
    delete[] subArrayOne;
    delete[] subArrayTwo;
}

void mergeSort(int *&arr, int end, int begin)
{
    if (end > begin)
    {
        int mid = begin + (end - begin) / 2;
        mergeSort(arr, mid, begin);
        mergeSort(arr, end, mid + 1);
        merge2Array(arr, begin, mid, end);
    }
    else
        return;
}
//-----------------------------------------------------------------

// Quick Sort
void sortFirstMiddleLast(int *&arr, int first, int mid, int last)
{
    if (arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    if (arr[mid] > arr[last])
        swap(arr[mid], arr[last]);
    if (arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
}

int partition(int *&arr, int first, int last)
{
    int mid = first + (last - first) / 2;
    sortFirstMiddleLast(arr, first, mid, last);
    swap(arr[mid], arr[last - 1]);
    int pivotIndex = last;
    int pivot = arr[pivotIndex];
    int indexFromLeft = first - 1;
    int indexFromRight = last;
    while (true)
    {
        while (arr[++indexFromLeft] < pivot)
            ;
        while (arr[--indexFromRight] > pivot)
            ;
        if (indexFromLeft > indexFromRight)
            break;
        swap(arr[indexFromLeft], arr[indexFromRight]);
    }
    swap(arr[pivotIndex], arr[indexFromLeft]);
    pivotIndex = indexFromLeft;
    return pivotIndex;
}

void quickSort(int *&arr, int first, int last)
{
    if (first < last)
    {
        int pivotIndex = partition(arr, first, last);
        quickSort(arr, first, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, last);
    }
}
//-----------------------------------------------------------------

// Radix sort
int getMax(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void radixCount(int *&arr, int size, int place)
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

void radixSort(int *&arr, int size)
{
    int max = getMax(arr, size);
    for (int place = 1; (max / place) > 0; place *= 10)
        radixCount(arr, size, place);
}
//-----------------------------------------------------------------

void shakerSort(int *&arr, int size)
{
    int Left = 0;
    int Right = size - 1;
    int k = 0;
    while (Left < Right)
    {
        for (int i = Left; i < Right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (int i = Right; i > Left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}

void shellSort(int *&arr, int size)
{
    int temp, j;
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            temp = arr[i];
            for (j = i; (j >= gap) && (arr[j - gap] > temp); j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void countingSort(int *&arr, int size)
{
    int max = getMax(arr, size);
    int *output = new int[size];
    int *count = new int[max];
    for (int i = 0; i <= max; ++i)
        count[i] = 0;
    for (int i = 0; i < size; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void flashSort(int *&arr, int size)
{
    // CLASSIFICATION

    int index_max = 0, minVal = arr[0];
    int num_of_class = int(float(0.45) * size);
    double delta = double(num_of_class - 1) / (arr[index_max] - minVal);
    int *classification = new int[num_of_class];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[index_max])
            index_max = i;
        else if (arr[i] < minVal)
            minVal = arr[i];
    }
    if (minVal == arr[index_max])
        return;

    // The loop below is to count element in each class
    for (int i = 0; i < num_of_class; i++)
        classification[i] = 0;
    for (int i = 0; i < size; i++)
    {
        int k = int(delta * (arr[i] - minVal));
        ++classification[k];
    }

    // This loop uses to calculate the index of last element in each class.
    for (int i = 1; i < num_of_class; i++)
    {
        classification[i] += classification[i - 1];
    }

    // PERMUTATION

    swap(arr[index_max], arr[0]);
    int move = 0,
        j = 0,
        curr_class = num_of_class - 1,
        hold, t, flash_element;
    while (move < size - 1)
    {
        while (j > classification[curr_class] - 1)
        {
            j++;
            curr_class = int(delta * (arr[j] - minVal));
        }
        if (curr_class < 0)
            break;
        flash_element = arr[j];
        while (j != classification[curr_class])
        {
            curr_class = int(delta * (flash_element - minVal));
            --classification[curr_class];
            swap(arr[classification[curr_class]], flash_element);
            ++move;
        }
    }

    delete[] classification;
    insertionSort(arr, size);
}

// SORT DATA
void SortData_Ver_Time(int type_sort, std::chrono::high_resolution_clock::time_point &start, std::chrono::high_resolution_clock::time_point &done, int *&arr, int size)
{
    switch (type_sort)
    {
    case selection:
        start = start_time;
        selectionSort(arr, size);
        done = end_time;
        break;
    case insertion:
        start = start_time;
        insertionSort(arr, size);
        done = end_time;
        break;
    case bubble:
        start = start_time;
        bubbleSort(arr, size);
        done = end_time;
        break;
    case heap:
        start = start_time;
        heapSort(arr, size);
        done = end_time;
        break;
    case merge:
        start = start_time;
        mergeSort(arr, size - 1);
        done = end_time;
        break;
    case quick:
        start = start_time;
        quickSort(arr, 0, size - 1);
        done = end_time;
        break;
    case radix:
        start = start_time;
        radixSort(arr, size);
        done = end_time;
        break;
    case shaker:
        start = start_time;
        shakerSort(arr, size);
        done = end_time;
        break;
    case shell:
        start = start_time;
        shellSort(arr, size);
        done = end_time;
        break;
    case counting:
        start = start_time;
        countingSort(arr, size);
        done = end_time;
        break;
    case flash:
        start = start_time;
        flashSort(arr, size);
        done = end_time;
        break;
    default:
        break;
    }
}
