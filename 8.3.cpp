#include <iostream>
using namespace std;
const int ProducNum = 9;
int BinarySearch(int array[], int size, int number);

int main()
{
    // init the array id of products
    int id[ProducNum] = {914, 915, 916, 917, 918, 919, 920, 921, 922};
    
    //get the string name of each id products
    string name[ProducNum] = {
        "Six Steps to Leadership",
        "Six Steps to Leadership",
        "The Road to Excellence",
        "Seven Lessons of Quality",
        "Seven Lessons of Quality",
        "Seven Lessons of Quality",
        "Teams Are Made, Not Born",
        "Leadership for the Future",
        "Leadership for the Future"
    };

    //get the string description of the products
    string description[ProducNum] = {
        "Book", "Audio CD", "DVD",
        "Book", "Audio CD", "DVD",
        "Book", "Book", "Audio CD"
    } ;

    // get the price of each product
    double price[ProducNum] = {12.95, 14.95, 18.95, 16.95, 21.95,
                                31.95, 14.95, 14.95, 16.95};

    // while loop continue to check the product if you not break
    while(1)
    {
        cout << "Enter the item's product number: ";
        int id_number;
        cin >> id_number;
        //use binary search to check whether id is available
        int index = BinarySearch(id, ProducNum, id_number);
        // fix the problem of no id
        if (index == -1)
            cout << "That product number was not found.\n";
        else 
        {
            cout << "Name: " << name[index] << endl;
            cout << "Description: " << description[index] << endl;
            cout << "Price: $" << price[index] << endl;
        }
        //check should we continue the while loop
        cout << "Would you like to look up another product? (y/n)";
        char judge;
        cin >> judge;
        if (judge == 'n')
            break;
    }
    cin.get();
    cin.get();
}

// Then we use Binary Search in 8.2
int BinarySearch(int array[], int size, int number)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (array[mid] == number)
        {
            return mid;
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
    return -1;
}