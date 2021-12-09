/**
 * @file counting-sortu-dev.cpp
 * @section 3 CS-1
 * @author Bueno, Nathanael
 *         Hinggan, Mutya
 *         Paunlagui, John Moises
 *         Tolentino, Charles Justine)
 * @brief Counting Sort Algorithm made with C++ 
 *        Compiler version
 *        - g++.exe (Rev7, Built by MSYS2 project) 10.3.0
 *        Text editor
 *        - Visual Studio Code 1.61.2
 * @version 0.1
 * @date 2021-12-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
// Counting sort in C++ programming

#include <iostream>
using namespace std;

// Function declaration
void countSort(int array[], int size);
void displayArray(int array[], int size);

// Global var
char name[9];

// Driver code
int main()
{
    /*
     * items handles how many items. 
     * index for indexing            
     * elements is the number that will be inputed                       
     */
    int items, index, elements;

    // repeat??
    char again;
    cout << "What's your name?? ";
    cin >> name;
    cout << name << ", This is Counting Sort Algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array.\n\nso ";
    cout << name << ", Please tell me how many elements do you want me sort?: ";
    cin >> items;

    int array[items];
    do
    {
        // size() – Returns the number of elements in the vector.
        cout << "\nPlease state each of the element in the indices " << name << "! [Array size of " << items << "]"
             << "\n";
        for (index = 0; index < items; index++)
        {
            cout << "Element in [" << index + 1 << "]: ";
            cin >> elements;
            array[index] = elements;
        }

        cout << "\n\nBefore Sorting...\n";
        displayArray(array, items);
        countSort(array, items);
        cout << "\n\nAfter Sorting...\n";
        displayArray(array, items);
        // To try other elements
        cout << "\nDo you want to try other elements " << name << "? with the array size of " << items << " [Y,N]? ";
        cin >> again;
    } while (again == 'Y' || again == 'y');
    cout << "Edii don't, Goodbyeee " << name << ", Salamat na lang sa lahat, See you next life HAHAHHAHA\n";
    cout << "Program Exited...";
}

void countSort(int array[], int size)
{
    // The size of count must be at least the (max+1) but
    // we cannot assign declare it as int count(max+1) in C++ as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int output[10];
    int count[10];
    int max = array[0];

    // Find the largest element of the array
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

// Function to print an array
void displayArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
