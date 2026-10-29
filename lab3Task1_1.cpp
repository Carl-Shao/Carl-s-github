#include <iostream>
#include <chrono>

const int testNumber = 3;
class SequentialSearch {

public:
    bool searchInArray(int arr[], int size, int target) {
        // TODO: implement sequential search in array
        for(int i = 0; i < size; i++) {
            if(arr[i] != target)
                continue;
            else
                return true;
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
testSearch(int size, SequentialSearch& search)
{
    int* array = generateArray(size);

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
    SequentialSearch search;
    int array[testNumber] = {100, 1000, 10000};
    for (int i = 0; i < testNumber; i++) {
        testSearch(array[i], search);
    }

    std::cin.get();
    std::cin.ignore();
}