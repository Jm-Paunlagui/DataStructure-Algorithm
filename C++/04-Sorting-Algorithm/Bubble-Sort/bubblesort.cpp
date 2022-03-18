/**
 * Bubble sort is a simple sorting algorithm. 
 * This sorting algorithm is comparison-based algorithm in which 
 * each pair of adjacent elements is compared and the elements are 
 * swapped if they are not in order. This algorithm is not suitable 
 * for large data sets as its average and worst case complexity are 
 * of Ο(n2) where n is the number of items. 
 */

#include <iostream>

using namespace std;

void swapping(int &num1, int &num2) // swap the content of num1 and num2
{
    int temp;

    temp = num1;
    num1 = num2;
    num2 = temp;
}

void display(int *array, int size)
{
    for (int index = 0; index < size; index++)
        cout << array[index] << " ";
    cout << endl;
}

void bubbleSort(int *array, int size)
{
    for (int index = 0; index < size; index++)
    {
        int swaps = 0; // flag to detect any swap is there or not
        for (int i = 0; i < size - index - 1; i++)
        {
            if (array[i] > array[i + 1]) // when the current item is bigger than the next
            {
                swapping(array[i], array[i + 1]);
                swaps = 1; // set swap flag
            }
            if (!swaps) // No swap in this pass, so array is sorted
                break;
        }
    }
}

int main(void)
{
    int num;
    cout << "Enter number of elements: ";
    cin >> num;
    int *arrays = new int[num];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> arrays[i];
    }
    cout << "Arrays before sorting: ";
    display(arrays, num);
    bubbleSort(arrays, num);
    cout << "Arrays after sorting: ";
    display(arrays, num);
}
