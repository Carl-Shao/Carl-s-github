#include <iostream>
#include <iomanip>
using namespace std;
void bubbleSort(int array[], int number);

int main()
{
    // get the array list and init the array
    int number;
    cout << "What size of the array you want : ";
    cin >> number;
    int array[number];
    // create the list use for loop
    cout << "\nEnter " << number << " integers in your array : ";
    for (int i = 0; i < number; i++)
    {
        cin >> array[i];
    }
    // use the bubble sort function to sort your array
    bubbleSort(array, number);
    // display the array after sorting
    for (int i = 0; i < number; i++)
    {
        cout << array[i] << " ";
    }
    cin.get();
    cin.get();
}

void bubbleSort(int array[], int number) 
{
    // the outside loop to check whether swap two number 
    for (int i = 0; i < number - 1; ++i) {
        bool swapped = false;
        // the inside loop is to swap two number 
        for (int j = 0; j < number - 1 - i; ++j) {
            if (array[j] > array[j + 1]) 
            {  
                swap(array[j], array[j + 1]);
                // change the swapped to convin the swap has happened
                swapped = true;  
            }
        }
        // if no swap then convine it has been sorted
        if (!swapped)
            break;
    }
}