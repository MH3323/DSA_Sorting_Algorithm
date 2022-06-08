#include "InputAndOutput.h"
#include "Sort.h"

bool isAllDigits(string s)
{
    int i = 0;
    while (i < s.length() && isdigit(s[i]) != 0)
        i++;
    if (i == s.length())
        return true;
    else
        return false;
}

bool isParameter(string s)
{
    if (s != _p_both && s != _p_comp && s != _p_time)
        return false;
    else
        return true;
}

int typeSort(string s)
{
    if (s == "slection-sort")
        return selection;
    if (s == "insertion-sort")
        return insertion;
    if (s == "bubble-sort")
        return bubble;
    if (s == "heap-sort")
        return heap;
    if (s == "merge-sort")
        return merge;
    if (s == "quick-sort")
        return quick;
    if (s == "radix-sort")
        return radix;
    if (s == "shaker-sort")
        return shaker;
    if (s == "counting-sort")
        return counting;
    if (s == "flash-sort")
        return flash;
    return -1;
}

double calRunningTime(clock_t start, clock_t end)
{
    return double(end - start) / (CLOCKS_PER_SEC);
}

bool readInput(string file_path, int *&arr, int &size)
{
    fstream file;
    file.open(file_path, ios::in);
    if (file.fail())
    {
        arr = nullptr;
        size = 0;
        file.close();
        return false;
    }
    else
    {
        file >> size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            file >> arr[i];
        }
        file.close();
        return true;
    }
}

bool writeOutput(string file_path, int *arr, int size)
{
    ofstream file;
    file.open(file_path);
    if (file.fail())
        return false;
    else
    {
        file << size << endl;
        for (int i = 0; i < size; i++)
        {
            file << arr[i] << " ";
        }
        return true;
    }
}

void printParameter_AMode(double time, long int comparisions, string parameter)
{
    if (parameter == _p_time)
        cout << "Running time: " << time << endl;
    else if (parameter == _p_comp)
        cout << "Comparisions: " << comparisions << endl;
    else if (parameter == _p_both)
    {
        cout << "Running time: " << time << endl;
        cout << "Comparisions: " << comparisions << endl;
    }
}

void printParameter_CMode(double time_1, double time_2, long int comp_1, long int comp_2, string parameter)
{
    if (parameter == _p_time)
        cout << "Running time: " << setw(12) << time_1 << " | " << setw(12) << time_2 << endl;
    else if (parameter == _p_comp)
        cout << "Comparisions: " << setw(12) << comp_1 << " | " << setw(12) << comp_2 << endl;
    else if (parameter == _p_both)
    {
        cout << "Running time: " << setw(12) << time_1 << " | " << setw(12) << time_2 << endl;
        cout << "Comparisions: " << setw(12) << comp_1 << " | " << setw(12) << comp_2 << endl;
    }
}

void printDivide()
{
    for (int i = 0; i < 10; i++)
        cout << "-";
    cout << endl;
}