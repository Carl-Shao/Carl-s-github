#include <iostream>
#include <iomanip>
using namespace std;
void selectionSort(int array[], int number);

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
    selectionSort(array, number);
    // display the array after sorting
    for (int i = 0; i < number; i++)
    {
        cout << array[i] << " ";
    }
    cin.get();
    cin.get(); 
}

void selectionSort(int array[], int number)
{
    // the outside loop to choose a small number to compare
    for (int i = 0; i < number - 1; i++)
    {
        // the inner loop to check all the elements after the small number
        for (int j = i + 1; j < number; j++)
        {
            // if a new number is smaller than the number then swap them
            if (array[j] < array[i])
            {
                swap(array[i], array[j]);
            }
        }
    }
}