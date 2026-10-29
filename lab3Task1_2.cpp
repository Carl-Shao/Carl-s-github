#include <iostream>
#include <vector>
#include <chrono>

const int TESTNUMBER = 3;

class SequentialSearch {
public:
    bool searchInVector(const std::vector<int>& vec, int target) {
        // TODO: implement sequential search in vector
        int size = vec.size();
        for(int i = 0; i < size; i++) {
            if(vec[i] != target)
                continue;
            else return true;
        }
        return false;
    }
};

// accroding to different size to create new array
std::vector<int>
generateArray(int size)
{
    std::vector<int> array(size);
    for(int i = 0; i < size; i++) {
        array[i] = rand() % (size * 10);
    }
    return array;
}

// use chrono to test time
void
testSearch(int size, SequentialSearch& search)
{
    std::vector array = generateArray(size);

    int target = -1;

    auto start = std::chrono::high_resolution_clock::now();
    bool find = search.searchInVector(array, target);
    auto end = std::chrono::high_resolution_clock::now();

    // compute nano second this algorithn use
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    std::cout << size << " : " << duration << "\n";
}

int
main()
{
    SequentialSearch search;
    int array[TESTNUMBER] = {100, 1000, 10000};
    for (int i = 0; i < TESTNUMBER; i++) {
        testSearch(array[i], search);
    }

    std::cin.get();
    std::cin.ignore();
}