#include "InputAndOutput.h"
#include "DataGenerator.h"
#include "Sort.h"
#include <string>

// Constants for mode
#define algorithm_mode "-a"
#define compare_mode "-c"

// Constant for data type
const int type_rand = 0;    // Randomized data
const int type_sorted = 1;  // Sorted data
const int type_rev = 2;     // Reverse sorted data
const int type_nsorted = 3; // Nearly sorted data

int main(int argc, char *argv[])
{
    clock_t start, end;
    string temp = "", parameter = "";
    int *arr = nullptr;
    int size = 0;
    long int comparisions = 0;
    if (string(argv[1]) == string(algorithm_mode))
    {
        cout << "ALGORITHM MODE.\n";
        if (typeSort(string(argv[2])) != -1)
        {
            cout << "Algorithm: " << argv[2] << endl;
            if (argc == 5)
            {
                // Here is code for command 1 and command 3
                temp = string(argv[3]);
                parameter = string(argv[4]);
                if (isParameter(parameter))
                {
                    if (isAllDigits(temp))
                    {
                        // Here is code for command 3
                        cout << "Command 3";
                    }
                    else
                    {
                        if (readInput(temp, arr, size))
                        {
                            cout << "Input file: " << temp << endl;
                            cout << "Input size: " << size << endl;
                            printDivide();
                            SortData(typeSort(string(argv[2])), start, end, comparisions, arr, size);
                            printParameter_AMode(calRunningTime(start, end), comparisions, parameter);
                        }
                        else
                            cout << "Reading the data file was failing.\n";
                    }
                }
                else
                    cout << "There hasn't this parameter.\n";
            }
            else
                cout << "There hasn't this algorithm.\n";
        }
        else if (argc == 6)
        {
            // Here is code for command 2
        }
    }
    else if (string(argv[1]) == string(compare_mode))
    {
        if (argc == 5)
        {
            // Here is code for command 4
        }
        else if (argc == 6)
        {
            // Here is code for command 5
        }
    }
    else
    {
        cout << "Don't have this command.\n";
    }
    
    // Print test
    printDivide();
    printTest(arr,size);

    // Delete pointer
    delete[] arr;
}