/**
 * This is an in-place comparison-based sorting algorithm.
 * 
 * A sub-list is maintained which is always sorted. 
 * For example, the lower part of an array is maintained to be sorted. 
 * An element which is to be 'insert'ed in this sorted sub-list, 
 * has to find its appropriate place and then it has to be inserted there. 
 * Hence the name, insertion sort.
 * 
 * The array is searched sequentially and unsorted items are moved 
 * and inserted into the sorted sub-list (in the same array). 
 * This algorithm is not suitable for large data sets as its average 
 * and worst case complexity are of Ο(n2), where n is the number of items.
*/

#include <iostream>

using namespace std;

// Function declaration
void insertionSort( int arrays[], int num );
void printArray (int arrays[], int num);

int main (void)
{
    int num;
    cout << "Enter number of elements: ";
    cin >> num;
    int arrays[num];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> arrays[i];
    }
    cout << "Arrays before sorting: ";
    printArray( arrays, num);
    insertionSort ( arrays, num);
    cout << "Arrays after sorting: ";
    printArray( arrays, num);
}

// Function to sort an array using insertion sort
void insertionSort( int arrays[], int num )
{
    int index, key, i;
    for ( index = 0; index < num; index++)
    {
        key = arrays[index];
        i = index - 1;

        /* Move elements of arrarys[0..i-1], that are
        greater than key, to one position ahead of their 
        current position*/
        while ( i >= 0 && arrays[i] > key)
        {
            arrays[i + 1] = arrays[i];
            i = i - 1;
        }
        arrays[i + 1] = key;

    }
    
}

void printArray (int arrays[], int num)
{
    int i;
    for (i = 0; i < num; i++)
        cout << arrays[i] << " ";
    cout << endl;
    
}