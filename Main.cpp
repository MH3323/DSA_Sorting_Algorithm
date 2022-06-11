#include "InputAndOutput.h"
#include "DataGenerator.h"
#include "Sort.h"
#include <string>

// Constants for mode
#define algorithm_mode "-a"
#define compare_mode "-c"

int main(int argc, char *argv[])
{
    clock_t start, end;
    string temp = "", parameter = "";
    int *arr = nullptr;
    int size = 0;
    long long int comparisons = 0;
    if (string(argv[1]) == string(algorithm_mode))
    {
        cout << "ALGORITHM MODE\n";
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
                            SortData(typeSort(string(argv[2])), start, end, comparisons, arr, size);
                            printParameter_AMode(calRunningTime(start, end), comparisons, parameter);
                            writeOutput("output.txt", arr, size);
                        }
                        else
                            cout << "Reading the data file was failing.\n";
                    }
                }
                else
                    cout << "There hasn't this parameter.\n";
            }
            else if (argc == 6)
            {
                // Here is code for command 2
                size = stoi(string(argv[3]));
                if(typeOrder(string(argv[4])) == -1)
                    cout << "No order.\n";
                else
                {
                    arr = new int[size];
                    GenerateData(arr, size, typeOrder(string(argv[4])));
                    writeOutput("input.txt", arr, size);
                    parameter = string(argv[5]);
                    if (isParameter(parameter))
                    {
                        cout << "Input size: " << size << endl;
                        cout << "Input order: " << typeOrder_String(string(argv[4])) << endl;
                        printDivide();
                        SortData(typeSort(string(argv[2])), start, end, comparisons, arr, size);
                        printParameter_AMode(calRunningTime(start, end), comparisons, parameter);
                        writeOutput("output.txt",arr,size);
                    }
                    else
                        cout << "There hasn't this parameter.\n";
                }
            }
        }
        else
            cout << "There hasn't this algorithm.\n";
    }
    else if (string(argv[1]) == string(compare_mode))
    {
        cout << "COMPARE MODE" << endl;
        if (argc == 5)
        {
            // Here is code for command 4
            if (readInput(string(argv[4]), arr, size))
            {
                int Algorithm_1 = typeSort(string(argv[2])), Algorithm_2 = typeSort(string(argv[3]));
                if (Algorithm_1 == -1 || Algorithm_2 == -1)
                {
                    cout << "There hasn't this algorithm.\n";
                }
                else
                {
                    cout << "Algorithm: " << setw(12) << argv[2] << " | " << setw(12) << argv[3] << endl;
                    cout << "Input file : " << argv[4] << endl;
                    cout << "Input size : " << size << endl;
                    printDivide();
                    int *arr2 = new int[size];
                    for (int i = 0; i < size; i++)
                        arr2[i] = arr[i];
                    clock_t start2, end2;
                    long long int comparisons2 = 0;
                    SortData(Algorithm_1, start, end, comparisons, arr, size);
                    SortData(Algorithm_2, start2, end2, comparisons2, arr2, size);
                    printParameter_CMode(calRunningTime(start, end), calRunningTime(start2, end2), comparisons, comparisons2, _p_both);
                    delete[] arr2;
                }
            }
            else
            {
                cout << "Open file fails!\n";
            }

        }
        else if (argc == 6)     {
            // Here is code for command 5
            int Algorithm_1 = typeSort(string(argv[2])), Algorithm_2 = typeSort(string(argv[3]));
            if (Algorithm_1 == -1 || Algorithm_2 == -1)
            {
                cout << "There hasn't this algorithm.\n";
            }
            else
            {
                size = stoi(string(argv[4]));
                cout << "Algorithm: " << setw(12) << argv[2] << "|" << setw(12) << argv[3] << end;
                cout << "Input size : " << size << endl;
                cout << "Input order : " << typeOrder_String(string(argv[5]));
                printDivide();
                int *arr2 = new int[size];
                for (int i = 0; i < size; i++)
                    arr2[i] = arr[i];
                clock_t start2, end2;
                long long int comparisons2 = 0;
                SortData(Algorithm_1, start, end, comparisons, arr, size);
                SortData(Algorithm_2, start2, end2, comparisons2, arr2, size);
                printParameter_CMode(calRunningTime(start, end), calRunningTime(start2, end2), comparisons, comparisons2, _p_both);
                delete[]arr2;
            }
        }
    }
    else
    {
        cout << "Don't have this command.\n";
    }

    // Print test
    // printDivide();
    
    // Delete pointer
    delete[] arr;
}
