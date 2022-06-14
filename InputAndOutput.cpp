#include "InputAndOutput.h"

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
    fstream file;
    file.open(file_path, ios::out);
    if (file.fail())
        return false;
    else
    {
        file << size << endl;
        if (arr != nullptr)
            for (int i = 0; i < size; i++)
            {
                file << arr[i] << " ";
            }
        return true;
    }
}

#define time_precision 30

void printParameter_AMode(std::chrono::high_resolution_clock::time_point start,
                          std::chrono::high_resolution_clock::time_point end,
                          long long int comparisions, string parameter)
{
    if (parameter == _p_time)
        cout << "Running time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << endl;
    else if (parameter == _p_comp)
        cout << "Comparisions: " << left << setw(14) << comparisions << endl;
    else if (parameter == _p_both)
    {
        cout << "Running time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << endl;
        cout << "Comparisions: " << left << setw(14) << comparisions << endl;
    }
}

void printParameter_CMode(std::chrono::high_resolution_clock::time_point start,
                          std::chrono::high_resolution_clock::time_point end,
                          std::chrono::high_resolution_clock::time_point start2,
                          std::chrono::high_resolution_clock::time_point end2,
                          long long int comp_1, long long int comp_2, string parameter)
{
    if (parameter == _p_time)
        cout << "Running time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
             << " | " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << endl;
    else if (parameter == _p_comp)
        cout << "Comparisions: " << left << setw(14) << comp_1 << " | " << left << setw(14) << comp_2 << endl;
    else if (parameter == _p_both)
    {
        cout << "Running time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
             << " | " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << endl;
        cout << "Comparisions: " << setw(14) << comp_1 << " | " << setw(14) << comp_2 << endl;
    }
}

void printDivide()
{
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << "-";
    cout << endl;
}

void printTest(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
