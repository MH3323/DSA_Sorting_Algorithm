#include "Sort_VerComp.h"

int findMin(int *arr, int size, long long int &comparisons)
{
    int min = arr[0];
    for (int i = 1; ++comparisons && i < size; i++)
        if (++comparisons && arr[i] < min)
            min = arr[i];
    return min;
}

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

void selectionSort(int *&arr, int size, long long int &comparisons)
{
    int left = size - 1, index;
    while (++comparisons && left >= 1)
    {
        index = indexMax(arr, left, comparisons);
        // if (++comparisons && left != index)
        swap(arr[left], arr[index]);
        left--;
    }
}
//-----------------------------------------------------------------
void insertionSort(int *&arr, int size, long long int &comparisons)
{
    int index = 1, pick, insert;
    while (++comparisons && index < size)
    {
        pick = arr[index];
        insert = index - 1;
        while (++comparisons && insert >= 0 && ++comparisons && arr[insert] > pick)
        {
            arr[insert + 1] = arr[insert];
            insert = insert - 1;
        }
        arr[insert + 1] = pick;
        ++index;
    }
}

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
    if (++comparisons && l < size && arr[l] > arr[largest])
        largest = l;
    if (++comparisons && r < size && arr[r] > arr[largest])
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
//-----------------------------------------------------------------
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
//-----------------------------------------------------------------
// Quick Sort
void sortFirstMiddleLast(int *&arr, int first, int mid, int last, long long int &comparisons)
{
    if (++comparisons && arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    if (++comparisons && arr[mid] > arr[last])
        swap(arr[mid], arr[last]);
    if (++comparisons && arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
}

int partition(int *&arr, int first, int last, long long int &comparisons)
{
    int mid = first + (last - first) / 2;
    sortFirstMiddleLast(arr, first, mid, last, comparisons);
    swap(arr[mid], arr[last - 1]);
    int pivotIndex = last;
    int pivot = arr[pivotIndex];
    int indexFromLeft = first - 1;
    int indexFromRight = last;
    while (true)
    {
        while (++comparisons && arr[++indexFromLeft] < pivot)
            ;
        while (++comparisons && arr[--indexFromRight] > pivot)
            ;
        if (++comparisons && indexFromLeft > indexFromRight)
            break;
        swap(arr[indexFromLeft], arr[indexFromRight]);
    }
    swap(arr[pivotIndex], arr[indexFromLeft]);
    pivotIndex = indexFromLeft;
    return pivotIndex;
}

void quickSort(int *&arr, int first, int last, long long int &comparisons)
{
    if (++comparisons && first < last)
    {
        int pivotIndex = partition(arr, first, last, comparisons);
        quickSort(arr, first, pivotIndex - 1, comparisons);
        quickSort(arr, pivotIndex + 1, last, comparisons);
    }
}
//-----------------------------------------------------------------
// Radix sort
int getMax(int *arr, int size, long long int &comparisons)
{
    int max = arr[0];
    for (int i = 1; ++comparisons && i < size; i++)
        if (++comparisons && arr[i] > max)
            max = arr[i];
    return max;
}

void radixCount(int *&arr, int size, int place, long long int &comparisons)
{
    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; ++comparisons && i < max; ++i)
        count[i] = 0;
    for (int i = 0; ++comparisons && i < size; i++)
        count[(arr[i] / place) % 10]++;

    for (int i = 1; ++comparisons && i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; ++comparisons && i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; ++comparisons && i < size; i++)
        arr[i] = output[i];
}

void radixSort(int *&arr, int size, long long int &comparisons)
{
    int max = getMax(arr, size, comparisons);
    for (int place = 1; ++comparisons && (max / place) > 0; place *= 10)
        radixCount(arr, size, place, comparisons);
}
//-----------------------------------------------------------------

void shakerSort(int *&arr, int size, long long int &comparisons)
{
    int Left = 0;
    int Right = size - 1;
    int k = 0;
    while (Left < Right)
    {
        for (int i = Left; i < Right; i++)
        {
            if (++comparisons && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (int i = Right; i > Left; i--)
        {
            if (++comparisons && arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}

void shellSort(int *&arr, int size, long long int &comparisons)
{
    int temp, j;
    for (int gap = size / 2; ++comparisons && gap > 0; gap /= 2)
    {
        for (int i = gap; ++comparisons && i < size; i++)
        {
            temp = arr[i];
            for (j = i; (++comparisons && j >= gap) && (++comparisons && arr[j - gap] > temp); j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void countingSort(int *&arr, int size, long long int &comparisons)
{
    int max = getMax(arr, size, comparisons);
    int *output = new int[size];
    int *count = new int[max];
    for (int i = 0; ++comparisons && i <= max; ++i)
        count[i] = 0;
    for (int i = 0; ++comparisons && i < size; i++)
        count[arr[i]]++;

    for (int i = 1; ++comparisons && i <= max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; ++comparisons && i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; ++comparisons && i < size; i++)
        arr[i] = output[i];
}

void flashSort(int *&arr, int size, long long int &comparisons)
{
    // CLASSIFICATION
    int index_max = 0, minVal = arr[0];
    int num_of_class = int(float(0.45) * size);
    int *classification = new int[num_of_class];
    double delta = double(num_of_class - 1) / (arr[index_max] - minVal);
    for (int i = 1; ++comparisons && i < size; i++)
    {
        if (++comparisons && arr[i] > arr[index_max])
            index_max = i;
        else if (++comparisons && arr[i] < minVal)
            minVal = arr[i];
    }
    if (++comparisons && minVal == arr[index_max])
        return;

    // The loop below is to count element in each class
    for (int i = 0; ++comparisons && i < num_of_class; i++)
        classification[i] = 0;
    for (int i = 0; ++comparisons && i < size; i++)
    {
        int k = int(delta * (arr[i] - minVal));
        ++classification[k];
    }

    // This loop uses to calculate the index of last element in each class.
    for (int i = 1; ++comparisons && i < num_of_class; i++)
    {
        classification[i] += classification[i - 1];
    }

    // PERMUTATION
    swap(arr[index_max], arr[0]);
    int move = 0,
        j = 0,
        curr_class = num_of_class - 1,
        flash_element;
    while (++comparisons && move < size - 1)
    {
        while (++comparisons && j > classification[curr_class] - 1)
        {
            j++;
            curr_class = int(delta * (arr[j] - minVal));
        }
        if (++comparisons && curr_class < 0)
            break;
        flash_element = arr[j];
        while (++comparisons && j != classification[curr_class])
        {
            curr_class = int(delta * (flash_element - minVal));
            --classification[curr_class];
            swap(arr[classification[curr_class]], flash_element);
            ++move;
        }
    }

    delete[] classification;
    insertionSort(arr, size, comparisons);
}
// SORT DATA
void SortData_Ver_Comp(int type_sort, long long int &comparisons, int *&arr, int size)
{
    switch (type_sort)
    {
    case selection:
        selectionSort(arr, size, comparisons);
        break;
    case insertion:
        insertionSort(arr, size, comparisons);
        break;
    case bubble:
        bubbleSort(arr, size, comparisons);
        break;
    case heap:
        heapSort(arr, size, comparisons);
        break;
    case merge:
        mergeSort(comparisons, arr, size - 1);
        break;
    case quick:
        quickSort(arr, 0, size - 1, comparisons);
        break;
    case radix:
        radixSort(arr, size, comparisons);
        break;
    case shaker:
        shakerSort(arr, size, comparisons);
        break;
    case shell:
        shellSort(arr, size, comparisons);
        break;
    case counting:
        countingSort(arr, size, comparisons);
        break;
    case flash:
        flashSort(arr, size, comparisons);
        break;
    default:
        break;
    }
}
