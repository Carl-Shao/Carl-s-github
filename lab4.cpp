#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;
using namespace std::chrono;

class MyVector {

// member of MyVector
private:
    int* data;
    int  sz;

public:
    // Constructor MyVector
    MyVector(int n = 0) : data(new int[n]), sz(n) {}

    // Copy
    MyVector(const MyVector& v) : data(new int[v.sz]), sz(v.sz) {
        for (int i = 0; i < sz; ++i) 
            data[i] = v.data[i];
    }

    // Move
    MyVector(MyVector&& v) noexcept : data(v.data), sz(v.sz) {
        v.data = nullptr; 
        v.sz = 0;
    }

    MyVector& operator=(const MyVector& v) {
        if (this != &v) { 
            delete[] data; 
            sz = v.sz; 
            data = new int[sz];
            for (int i = 0; i < sz; ++i) 
                data[i] = v.data[i]; }
        return *this;
    }

    MyVector& operator=(MyVector&& v) noexcept {
        if (this != &v) { 
            delete[] data; 
            data = v.data; 
            sz = v.sz;
            v.data = nullptr;
            v.sz = 0; }
        return *this;
    }

    ~MyVector() { delete[] data; }

    int& operator[](int i) { return data[i]; }
    int  operator[](int i) const { return data[i]; }
    int  size() const { return sz; }
    int* begin() { return data; }
    int* end() { return data + sz; }

    // To let you get the begining and the end of the MyVector array
    const int* begin() const { return data; }
    const int* end() const { return data + sz; }

    // Linear Search
    int linearSearch(int v) const {
        for (int i = 0; i < sz; ++i) 
            if (data[i] == v) return i;
        return -1;
    }

    // Binary Search
    int binarySearch(int v) const {
        int low = 0, high = sz - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (data[mid] == v) 
                return mid;
            if (data[mid] < v) 
                low = mid + 1; 
            else 
                high = mid - 1;
        }
        return -1;
    }

    // Sort
    void sort() {
        std::sort(data, data + sz);
    }
};

double timeMs(void (*f)()) {
    auto t0 = high_resolution_clock::now();
    f();
    auto t1 = high_resolution_clock::now();
    return duration<double, milli>(t1 - t0).count();
}

// Use global to test all the function
vector<int> ga, ga2, ga3;
MyVector gb, gb2, gb3;
int target;

// linear function
void do_std_linear() { 
    for (int k = 0; k < 10; ++k) 
        find(ga.begin(), ga.end(), target); 
}
void do_my_linear() { 
    for (int k = 0; k < 10; ++k) 
        gb.linearSearch(target); 
}

// binary search function
void do_std_bin() { 
    for (int k = 0; k < 100; ++k) 
        binary_search(ga2.begin(), ga2.end(), target); 
}
void do_my_bin() { 
    for (int k = 0; k < 100; ++k) 
        gb2.binarySearch(target); 
}

// sort function
void do_std_sort() { 
    sort(ga2.begin(), ga2.end()); 
}
void do_my_sort() { 
    gb2.sort(); 
}

// copy function
void do_std_copy() { 
    vector<int> c = ga;  
}
void do_my_copy() { 
    MyVector c = gb; 
}

// Move Function
void do_std_move() { 
    vector<int> c = move(ga3); 
}
void do_my_move() { 
    MyVector c = move(gb3); 
}


void test(int n) {
    cout << "\nn = " << n << "\n";
    cout << left << setw(16) << "Operation"
         << setw(16) << "std::vector"
         << setw(16) << "MyVector" << "\n";
    cout << string(48, '-') << "\n";

    // construct the array
    srand(42);
    vector<int> a(n);
    MyVector    b(n);
    for (int i = 0; i < n; ++i) {
        int v = rand() % (n * 10 + 1);
        a[i] = v;
        b[i] = v;
    }
    target = a[n / 2];

    // distribute a and b
    ga = a;
    gb = b;

    // Linear Search Test
    double t1 = timeMs(do_std_linear);
    double t2 = timeMs(do_my_linear);
    cout << left << setw(16) << "LinearSearch"
         << setw(16) << fixed << setprecision(3) << t1
         << setw(16) << t2 << "\n";

    // redistribute a and b
    ga2 = ga;
    gb2 = gb;

    // Binary Search Test
    t1 = timeMs(do_std_bin);
    t2 = timeMs(do_my_bin);
    cout << left << setw(16) << "BinarySearch"
         << setw(16) << t1 << setw(16) << t2 << "\n";

    // Sort Test
    t1 = timeMs(do_std_sort);
    t2 = timeMs(do_my_sort);
    cout << left << setw(16) << "Sort"
         << setw(16) << t1 << setw(16) << t2 << "\n";

    // Copy Test
    t1 = timeMs(do_std_copy);
    t2 = timeMs(do_my_copy);
    cout << left << setw(16) << "Copy"
         << setw(16) << t1 << setw(16) << t2 << "\n";

    // redistribute a and b
    ga3 = ga;
    gb3 = gb;
    // Move Test
    t1 = timeMs(do_std_move);
    t2 = timeMs(do_my_move);
    cout << left << setw(16) << "Move"
         << setw(16) << t1 << setw(16) << t2 << "\n";
    
}

int main() {
    // test 1000 times
    test(1000);
    // test 10000 times
    test(10000);
    // test 100000 times
    test(100000);
    cin.get();
    cin.ignore();
    return 0;
}