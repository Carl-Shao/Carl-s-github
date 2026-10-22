#include <iostream>
#include <chrono>
#include <iomanip>

// O(1) constant time
void
constFunction(int n)
{
    for(int i = 0; i < 100; i++) {
        n *= 2;
    }
}

// O(n) n time
void
linearFunction(int n)
{
    int sum = 0;
    while(n--)
        sum += n * 2;
}

// O(n^2) n squre time
void
quadraticFunction(int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum += i * j;
        }
    }
}

// O(log n) log2^n time
void
logarithmicFunction(int n)
{
    for(int i = 0; i < 100; i++) {
        while(n > 1)
            n /= 2;
    }
}

// compute time
double computeTime(void (*func)(int), int n) {
    auto start = std::chrono::high_resolution_clock::now();
    func(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    return elapsed.count();
}

int
main()
{
    int sizes[] = {100, 1000, 10000, 100000};
    for(int i = 0; i < 4; i++) {
        int n = sizes[i];
        double t0 = computeTime(constFunction, n) / 100;
        double t1 = computeTime(linearFunction, n);
        double t2 = computeTime(quadraticFunction, n);
        double t3 = computeTime(logarithmicFunction, n) / 100;
        std::cout << std::setw(8)  << n
                  << std::setw(12) << t0
                  << std::setw(12) << t1
                  << std::setw(16) << t2
                  << std::setw(12) << t3 << "\n";
    }
    std::cin.get();
    std::cin.ignore();
}
