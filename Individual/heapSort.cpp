/**
 * @file heapSort.cpp
 * @author johnpaunlagui@gmail.com
 * @brief Heap Sort Algorithm with AlgoStep by Jm XD
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

using namespace std;

// Function declaration
void displayElements(int elements[], int items, int isBefore);
void algoStep(int elements[], int items);
void heapifyElements(int elements[], int items, int index);
void heapSortElements(int elements[], int items);

int main()
{

    int items, index;
    // repeat??
    char again;
    // Prompts the user to enter how many elements.
    cout << "Heap sort Algorithm\nEnter the number of elements you would like to input? ";
    cin >> items;

    // Sets the array of elements on how many items
    int* elements = new int[items];

    do
    {
        // Getting the names
        cout << "\nPlease state the elements in each index\n";
        for (index = 0; index < items; index++)
        {
            cout << "[" << index + 1 << "] Element: ";
            cin >> elements[index];
        }

        cout << "\nElements Before Sorting: \n";
        displayElements(elements, items, 0);
        cout << "\nProcess on each iteration...\n";
        heapSortElements(elements, items);
        displayElements(elements, items, 1);

        // To try other elements
        cout << "\nDo you want to try other elements with the size of " << items << " [Y,N]? ";
        cin >> again;
    } while (again == 'Y' || again == 'y');
    cout << "Program Exited...";
    return 0;
}

// Just to make sure it displays the right output
void displayElements(int elements[], int items, int isBefore)
{
    if (isBefore == 0)
    {
        cout << "\nNo.\t\tElements\n";
        for (auto index = 0; index < items; index++)
        {
            cout << "[" << index + 1 << "]\t\t" << elements[index] << endl;
        }
    }
    else
    {
        cout << "\nAfter Sorting: \n";
        cout << "\nNo.\t\tElements\n";
        for (auto index = 0; index < items; index++)
        {
            cout << "[" << index + 1 << "]\t\t" << elements[index] << endl;
        }
    }
}

// Show each iteration of the algorithm
void algoStep(int elements[], int items)
{
    for (int i = 0; i < items; i++)
    {
        cout << "[" << elements[i] << "]"
             << "\t";
    }
    cout << endl;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapifyElements(int elements[], int items, int index)
{

    int largest = index; // Initialize largest as root
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // if left child is larger than root
    if (left < items && elements[left] > elements[largest])
        largest = left;

    // if right child is larger than largest so far
    if (right < items && elements[right] > elements[largest])
        largest = right;

    // if largest is not root
    if (largest != index)
    {
        swap(elements[index], elements[largest]);

        // Recursively heapify the affected sub-tree
        heapifyElements(elements, items, largest);
    }
    algoStep(elements, items);
}

// main function to do heap sort
void heapSortElements(int elements[], int items)
{
    // Build heap (rearrange array)
    for (int index = items / 2 - 1; index >= 0; index--)
        heapifyElements(elements, items, index);

    for (int index = items - 1; index > 0; index--)
    {
        // Move current root to end
        swap(elements[0], elements[index]);
        // call max heapify on the reduced heap
        heapifyElements(elements, index, 0);
    }
}

// END LINE