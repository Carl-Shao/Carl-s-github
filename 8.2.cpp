#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool BinarySearch(const vector<int> array, int size, int number);

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
    // use sort function to make the array from lowest to highest
    sort(array.begin(), array.end());
    int number;
    // decide which number you wanna search
    cout << "\n" << "Enter the number you wanna search : ";
    cin >> number;
    bool search = BinarySearch(array, size, number);
    if (search == true)
        cout << "Find!";
    else 
        cout << "Not Find!";
    cin.get();
    cin.get();
}

// The logic is check if it is bigger than the middle or smaller
// to decrese the complexity 
bool BinarySearch(const vector<int> array, int size, int number)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (array[mid] == number)
        {
            return true;
        }
        else if (array[mid] < number)
        {
            low = mid + 1;
        }
        else if (array[mid] > number)
        {
            high = mid - 1;
        }
    }
    return false;
}