#include "argumentControl.h"

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
    if (s == "selection-sort")
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
    if (s == "shell-sort")
        return shell;
    return -1;
}

int typeOrder(string s)
{
    if (s == "-rand")
        return type_rand;
    if (s == "-nsorted")
        return type_nsorted;
    if (s == "-sorted")
        return type_sorted;
    if (s == "-rev")
        return type_rev;
    return -1;
}

string typeOrder_String(string s)
{
    if (s == "-rand")
        return "Randomized";
    if (s == "-nsorted")
        return "Nearly Sorted";
    if (s == "-sorted")
        return "Sorted";
    if (s == "-rev")
        return "Reversed";
    return "";
}

string typeOrder_Num(int i)
{
    if (i == 0)
        return "Randomized";
    if (i == 1)
        return "Nearly Sorted";
    if (i == 2)
        return "Sorted";
    if (i == 3)
        return "Reversed";
    return "";
}

string nameSort(string arg_name)
{
    string name = arg_name;
    name[0] -= 32;
    name[name.find('-')] = ' ';
    name[name.find(' ') + 1] -= 32;
    return name;
}

double calRunningTime(clock_t start, clock_t end)
{
    return double(end - start) / double(CLOCKS_PER_SEC);
}