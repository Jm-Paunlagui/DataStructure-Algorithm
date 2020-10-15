/**
 * In the selection sort technique, the list is divided into two parts.
 * 1. The subarray which already sorted.
 * 2. Remaining subarray which is unsorted. 
 * At first we take the maximum or minimum data from the array. 
 * After getting the data (say minimum) we place it at the beginning
 * of the list by replacing the data of first place with the minimum data. 
 * After performing the array is getting smaller. 
 * Thus this sorting technique is done.
 *  
 *  THE COMPLEXITY OF SELECTION SORT TECHNIQUE
 *  Time Complexity: O(n2)
 *  Space Complexity: O(1)
 */

#include <iostream>

using namespace std;

// Function declaration
void swapping (int &num1, int &num2);
void display (int *array, int size);
void selectionSort (int *array, int size);

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
    display( arrays, num);
    selectionSort ( arrays, num);
    cout << "Arrays after sorting: ";
    display ( arrays, num);
}

void swapping (int &num1, int &num2) // swap the content of num1 and num2
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

void display (int *array, int size)
{
    for (int index = 0; index < size; index++)
        cout << array[index] << " ";
    cout << endl;  
}

void selectionSort (int *array, int size)
{
    int num, i, imin;
    for ( num = 0; num < size - 1; num++)
    {
        imin = num;
        for ( i = num + 1; i < size; i++)
            if (array[i] < array[imin])
                imin = i;
                swap(array[num], array[imin]);    
    }
}