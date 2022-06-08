#include "InputAndOutput.h"
#include "DataGenerator.h"
#include "Sort.h"
#include <string>

// Constants for mode
#define algorithm_mode "-a"
#define compare_mode "-c"

//
#define selection_sort selectionSort(a, n)

// Constant for data type
const int type_rand = 0;    // Randomized data
const int type_sorted = 1;  // Sorted data
const int type_rev = 2;     // Reverse sorted data
const int type_nsorted = 3; // Nearly sorted data

int main(int argc, char *argv[])
{
    if (string(argv[1]) == string(algorithm_mode))
    {
        if (argc == 4)
        {
            // Here is code for command 1 and command 3
        }
        else if (argc == 5)
        {
            // Here is code for command 2
        }
    }
    else if (string(argv[1]) == string(compare_mode))
    {
        if (argc == 4)
        {
            // Here is code for command 4
        }
        else if (argc == 5)
        {
            // Here is code for command 5
        }
    }
    else
    {
        cout << "Don't have this command.\n";
    }
}