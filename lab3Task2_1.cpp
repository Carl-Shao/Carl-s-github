#include <iostream>
#include <chrono>
#include <algorithm>

const int TESTNUMBER = 3;

class BinarySearch {

public:
    bool searchInArray(int arr[], int size, int target) {
        // TODO: implement binary search in arrays
        int left = 0;
        int right = size - 1;

        while(left <= right) {
            int middle = left + (right - left) / 2;
            if(target == arr[middle]) {
                return true;
            } else if (target < arr[middle]) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return false;
    }
};

// accroding to different size to create new array
int*
generateArray(int size)
{
    int* array = new int[size];
    for(int i = 0; i < size; i++) {
        array[i] = rand() % (size * 10);
    }
    return array;
}

// use chrono to test time
void
testSearch(int size, BinarySearch& search)
{
    int* array = generateArray(size);
    std::sort(array, array + size);

    int target = -1;

    auto start = std::chrono::high_resolution_clock::now();
    bool find = search.searchInArray(array, size, target);
    auto end = std::chrono::high_resolution_clock::now();

    // compute nano second this algorithn use
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    std::cout << size << " : " << duration << "\n";
    delete[] array;
}

int
main()
{
    BinarySearch search;
    int array[TESTNUMBER] = {100, 1000, 10000};
    for (int i = 0; i < TESTNUMBER; i++) {
        testSearch(array[i], search);
    }

    std::cin.get();
    std::cin.ignore();
}