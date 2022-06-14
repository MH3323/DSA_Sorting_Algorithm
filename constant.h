#pragma one

// Constant for data type
#define type_rand 0    // Randomized data
#define type_sorted 1  // Sorted data
#define type_rev 2     // Reverse sorted data
#define type_nsorted 3 // Nearly sorted data

// Constants for mode
#define algorithm_mode "-a"
#define compare_mode "-c"

// Constant for type of sorting algoritm
#define selection 0
#define insertion 1
#define bubble 2
#define heap 3
#define merge 4
#define quick 5
#define radix 6
#define shaker 7
#define shell 8
#define counting 9
#define flash 10

// Constants for parameter
#define _p_time "-time"
#define _p_comp "-comp"
#define _p_both "-both"

// Constant for calculating the executable time

#define start_time std::chrono::high_resolution_clock::now()
#define end_time std::chrono::high_resolution_clock::now()