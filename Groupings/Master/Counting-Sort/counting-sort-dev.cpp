/**
 * @file counting-sort-dev.cpp
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
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Function declaration
void displayArray(vector<int> &array);
void countSort(vector<int> &array);
char name[9];

/***************
 * DRIVER CODE *
 ***************/
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

    vector<int> array(items);
    do
    {
        // size() – Returns the number of elements in the vector.
        cout << "\nPlease state each of the element in the indices " << name << "! [Vector size of " << array.size() << "]"
             << "\n";
        for (index = 0; index < items; index++)
        {
            cout << "Element in [" << index + 1 << "]: ";
            cin >> elements;
            array[index] = elements;
        }

        cout << "\n\nBefore Sorting...\n";
        displayArray(array);
        countSort(array);
        cout << "\n\nAfter Sorting...\n";
        displayArray(array);
        // To try other elements
        cout << "\nDo you want to try other elements " << name << "? with the vector size of " << array.size() << " [Y,N]? ";
        cin >> again;
    } while (again == 'Y' || again == 'y');
    cout << "Edii don't, Goodbyeee " << name << ", Salamat na lang sa lahat, See you next life HAHAHHAHA\n";
    cout << "Program Exited...";
}

/**************************************
 * DISPLAYS UNSORTED AND SORTED ARRAY *
 **************************************/
void displayArray(vector<int> &array)
{
    // size() – Returns the number of elements in the vector.
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << "\n";
}

void countSort(vector<int> &array)
{
    // begin() – Returns an iterator pointing to the first element in the vector.
    // end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector.
    // size() – Returns the number of elements in the vector.
    int max = *max_element(array.begin(), array.end());
    int min = *min_element(array.begin(), array.end());
    int range = max - min + 1;

    vector<int> count(range), output(array.size());

    // Store the count of each element
    for (int i = 0; i < array.size(); i++)
    {
        count[array[i] - min]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = array.size() - 1; i >= 0; i--)
    {
        output[count[array[i] - min] - 1] = array[i];
        count[array[i] - min]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < array.size(); i++)
    {
        array[i] = output[i];
    }
}