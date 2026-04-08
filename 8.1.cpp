#include <iostream>
#include <vector>
using namespace std;
bool LinearSearch(const vector<int> array, int size, int number);

int main()
{
    // put the size of array
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;
    cout << "\n" << "Enter the array : ";
    vector<int> array;
    // use for loop to put number in the array
    for (int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        array.push_back(num);
    }
    // decide which number you wanna search
    int number;
    cout << "\n" << "Enter the number you wanna search : ";
    cin >> number;
    bool search = LinearSearch(array, size, number);
    if (search == true)
        cout << "Find!";
    else 
        cout << "Not Find!";
    cin.get();
    cin.get();
}

bool LinearSearch(const vector<int> array, int size, int number)
{
    // The core code of the program 
    // one by one search 
    for (int i = 0; i < number; i++)
    {
        if (array[i] == number)
            return true;
    }
    return false;
}