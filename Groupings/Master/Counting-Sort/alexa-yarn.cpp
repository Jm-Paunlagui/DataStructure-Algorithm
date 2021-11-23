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
    char right;
    cout << "What's your name?? ";
    cin >> name;

    do
    {
        cout << name << ", Please tell me how many elements do you want me sort ?: ";
        cin >> items;

        cout << "\nOkay " << name << ", I'll be sorting the elements with size of " << items << " items, is that right?! [Y,N]? ";
        cin >> right;
    } while (right == 'N' || right == 'N');
    vector<int> array(items);
    do
    {
        cout << "\nPlease state each of the element in the indices " << name << "!\n";
        for (index = 0; index < items; index++)
        {
            cout << "Element in [" << index + 1 << "]: ";
            cin >> elements;
            array[index] = elements;
        }
        cout << "Thank you for stating the elements right " << name << "!";

        cout << "\n\nBefore Sorting...\n";
        displayArray(array);
        countSort(array);
        cout << "\n\nAfter Sorting...\n";
        displayArray(array);
        // To try other elements
        cout << "\nDo you want to try other elements" << name << "? with the size of " << items << " [Y,N]? ";
        cin >> again;
    } while (again == 'Y' || again == 'y');
}

/**************************************
 * DISPLAYS UNSORTED AND SORTED ARRAY *
 **************************************/
void displayArray(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << "\n";
}

void countSort(vector<int> &array)
{
    int max = *max_element(array.begin(), array.end());
    int min = *min_element(array.begin(), array.end());
    int range = max - min + 1;

    // Count will
    vector<int> count(range), output(array.size());
    for (int i = 0; i < array.size(); i++)
        count[array[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = array.size() - 1; i >= 0; i--)
    {
        output[count[array[i] - min] - 1] = array[i];
        count[array[i] - min]--;
    }

    for (int i = 0; i < array.size(); i++)
        array[i] = output[i];
}